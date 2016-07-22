/*
 * Brett Fedack
 * CS372 Summer 2015
 * Project 1
 * Description: This program is a server that connects with one client at a
 *     time to engage in an alternating chat session. The dialogue persists
 *     until one host closes the connection. Thereafter, the server continues
 *     to listen for client requests until receiving an interrupt signal.
 */

#include <ctype.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#define BACKLOG       5 // Arbitrary queue size of connection requests
#define MAX_ARG_LEN 256 // Maximum number of characters in command-line argument
#define MAX_MSG_LEN 500 // Maximum number of characters in a message
#define HANDLE_SIZE  10 // Number of bytes reserved for handle in message protocol

void getMessage(char *handle, char *message);
void handleInterrupt(int sig);
int isStrInt(char *str, int *n);
void recvAll(int socket, void *buffer, int size);
void recvPacket(int socket, char *handle, char *message);
void runChatSession(int connectedSocket);
void sendAll(int socket, void *buffer, int numBytes);
void sendPacket(int socket, char *handle, char *message);
void startChatServer(int port);
void stripWhitespaces(char *str);
int isInt(char *string);

int main(int argc, char **argv)
{
	int port; // Port number on which to listen for connection requests
    char c;
	// Exactly two command line arguments are expected.
	if (argc != 2) {
		fprintf(stderr, "usage: chatserve <port #>\n");
		exit(1);
	}

	// The given port number must be an integer.
	if (!isInt(argv[1])) {
		fprintf(stderr, "chatserve: Port number must be an integer\n");
		exit(1);
	}
    sscanf(argv[1], "%d %c", &port, &c);
	// The given port number must be in the range [1024, 65535].
	if (port < 1024 || port > 65535) {
		fprintf(stderr, "chatserve: Port number must be in the range [1024, 65535]\n");
		exit(1);
	}

	// Run the chat server until an interrupt signal is detected.
	startChatServer(port);

	exit(0);
}


/*
 * Function: getMessage
 *
 * Purpose:  This function retrieves a valid message from standard input.
 *
 * Receives: handle - c-string identifier for message author
 *           message - output character buffer for message
 *
 * Returns:  A valid message is returned.
 *
 * Pre:      'message' shall be large enough to hold all bytes of the message.
 *
 * Post:     'message' is modified.
 */
void getMessage(char *handle, char *message)
{
	// Get a valid message from standard input.
	while(1) {
		// Prompt the server for a message.
		printf("%s> ", handle);
		fgets(message, MAX_MSG_LEN, stdin);
		stripWhitespaces(message);

		// Validate the input.
		if (strlen(message) < 1 || strlen(message) > MAX_MSG_LEN) {
			printf("Message must be between 1 and %d characters\n", MAX_MSG_LEN);
		}
		else { break; }
	}
}


/*
 * Function: handleInterrupt
 *
 * Purpose:  This callback provides feedback before terminating the 'chatserve'
 *           program in response to an interrupt signal.
 *
 * Receives: sig - signal number
 *
 * Returns:  None
 *
 * Pre:      None
 *
 * Post:     The program terminates.
 */
void handleInterrupt(int sig)
{
	int status;                   // Return status
	struct sigaction interrupt;   // Signal action for handling interrupt

	// Provide feedback to the user.
	printf("\nchatserve closed\n");

	// Restore interrupt handling to the default behavior.
	interrupt.sa_handler = SIG_DFL;
	status = sigaction(SIGINT, &interrupt, 0);
	if (status == -1) {
		perror("sigaction");
		exit(1);
	}

	// Send an interrupt signal in order to force the default behavior.
	status = raise(SIGINT);
	if (status == -1) {
		perror("raise");
		exit(1);
	}
}


/*Function checks if the string is an INT
    receives:   str- c-string that may represent an int
    returns:    1 if a string is an INT and 0 if the string is not an INT
    pre:        none
    post:       none
 */
//taken from http://www.linuxforums.org/forum/programming-scripting/148423-checking-if-string-integer.html
int isInt(char *string){
        int i, stringLength = strlen(string);
        for(i = 0; i < stringLength; i++){
            if(isdigit(string[i]) == 0 || ispunct(string[i]) != 0)
                break;
        }
        if(i != stringLength)
                return 0;
        else
                return 1;
}


/*
 * Function: recvAll
 *
 * Purpose:  This function invokes 'recv' as many times as necessary to receive
 *           all of the given bytes of data.
 *
 * Receives: socket - connection endpoint on which to receive data
 *           buffer - data destination
 *           numBytes - target number of bytes to receive
 *
 * Returns:  None
 *
 * Pre:      A connection shall be established on the given socket.
 *           'buffer' shall be large enough to hold the given number of bytes.
 *
 * Post:     'buffer' is modified.
 */
void recvAll(int socket, void *buffer, int numBytes)
{
	int ret;               // Return value for 'recv'
	int receivedBytes;     // Total number of bytes received

	// Retrieve the given number of bytes.
	receivedBytes = 0;
	while (receivedBytes < numBytes) {
		ret = recv(socket, buffer + receivedBytes, numBytes - receivedBytes, 0);

		// Error encountered.
		if (ret == -1) {
			perror("recv");
			exit(1);
		}

		// Data received.
		else {
			receivedBytes += ret;
		}
	}
}


/*
 * Function: recvPacket
 *
 * Purpose:  This function receives a message packet from the given socket.
 *
 *           The message protocol is based on section 7.5 of Beej's Guide to
 *           Network Programming.
 *                                   _   Header
 *               length - 2 bytes     |_/
 *               handle - 10 bytes   _|   Data
 *               message - 500 bytes ____/
 *
 * Receives: socket - connection endpoint on which to receive data
 *           handle - output buffer for header field containing author
 *           message - output buffer for encapsulated message data
 *
 * Returns:  None
 *
 * Pre:      A connection shall be established on the given socket.
 *           Output buffers shall be large enough for their respective data.
 *
 *
 * Post:     'handle' and 'message' are modified.
 */
void recvPacket(int socket, char *handle, char *message)
{
	unsigned short packetLength;  // Number of bytes in packet
	unsigned short messageLength; // Number of bytes in message

	// Receive the packet length.
	recvAll(socket, &packetLength, sizeof(packetLength));
	packetLength = ntohs(packetLength);

	// Receive the handle field.
	recvAll(socket, handle, HANDLE_SIZE);
	handle[HANDLE_SIZE] = '\0';

	// Receive the message data.
	messageLength = packetLength - HANDLE_SIZE - sizeof(packetLength);
	recvAll(socket, message, messageLength);
	message[messageLength] = '\0';
}


/*
 * Function: runChatSession
 *
 * Purpose:  This function alternates between receiving and sending message
 *           packets from a client to the server.
 *
 * Receives: connectedSocket - server's endpoint of client-server connection
 *
 * Returns:  None
 *
 * Pre:      A connection shall be established on the given socket.
 *
 * Post:     None
 */
void runChatSession(int connectedSocket)
{
	char clientHandle[HANDLE_SIZE + 1];         // Identifier for the client
	char serverHandle[HANDLE_SIZE + 1];         // Identifier for the server
	char message[MAX_MSG_LEN + 1];              // Message buffer

	// Associate the server with a handle.
	memset(serverHandle, '\0', HANDLE_SIZE + 1);
	strcpy(serverHandle, "HAL9000");

	while (1) {
		// Receive message packet from the client.
		recvPacket(connectedSocket, clientHandle, message);

		// Close the chat session on the server if necessary.
		if (strcmp(message, "\\quit") == 0) {
			printf("Connection with client closed\n");
			break;
		}

		// Display received message.
		printf("%s> %s\n", clientHandle, message);

		// Get a message from the server.
		getMessage(serverHandle, message);

		// Close the chat session on both ends if necessary.
		if (strcmp(message, "\\quit") == 0) {
			printf("Connection with client closed\n");
			sendPacket(connectedSocket, serverHandle, "\\quit");
			break;
		}

		// Send message packet to the client.
		sendPacket(connectedSocket, serverHandle, message);
	}
}


/*
 * Function: sendAll
 *
 * Purpose:  This function invokes 'send' as many times as necessary to send
 *           all of the given bytes of data.
 *
 * Receives: socket - connection endpoint on which to send data
 *           buffer - data source
 *           numBytes - target number of bytes to send
 *
 * Returns:  None
 *
 * Pre:      A connection shall be established on the given socket.
 *           'buffer' shall be large enough to hold the given number of bytes.
 *
 * Post:     None
 */
void sendAll(int socket, void *buffer, int numBytes)
{
	int ret;           // Return value for 'send'
	int sentBytes;     // Total number of bytes sent

	// Send the given number of bytes.
	sentBytes = 0;
	while (sentBytes < numBytes) {
		ret = send(socket, buffer + sentBytes, numBytes - sentBytes, 0);

		// Error encountered.
		if (ret == -1) {
			perror("send");
			exit(1);
		}

		// Data sent.
		else {
			sentBytes += ret;
		}
	}
}


/*
 * Function: sendPacket
 *
 * Purpose:  This function sends a message packet from the given socket.
 *
 *           The message protocol is based on section 7.5 of Beej's Guide to
 *           Network Programming.
 *                                   _   Header
 *               length - 2 bytes     |_/
 *               handle - 10 bytes   _|   Data
 *               message - 500 bytes ____/
 *
 * Receives: socket - connection endpoint on which to send data
 *           handle - input c-string for author of message
 *           message - input c-string for message data to encapsulate
 *
 * Returns:  None
 *
 * Pre:      A connection shall be established on the given socket.
 *
 * Post:     None
 */
void sendPacket(int socket, char *handle, char *message)
{
	unsigned short packetLength;  // Number of bytes in packet

	// Send the packet length.
	packetLength = htons(sizeof(packetLength) + HANDLE_SIZE + strlen(message));
	sendAll(socket, &packetLength, sizeof(packetLength));

	// Send the handle field.
	sendAll(socket, handle, HANDLE_SIZE);

	// Send the message data.
	sendAll(socket, message, strlen(message));
}


/*
 * Function: startChatServer
 *
 * Purpose:  This function runs a server that listens on the given port and
 *           engages one client at a time in an alternating chat session.
 *
 * Receives: port - machine port to interface with clients
 *
 * Returns:  None
 *
 * Pre:      The listening port shall be at least 1024 to avoid conflicts with
 *           standard services.
 *
 *           The listening port shall be no greater than 65535 to stay within
 *           the bounds of available ports.
 *
 * Post:     None
 */
void startChatServer(int port)
{
	int connectedSocket;              // Socket created upon accepting client
	int serverSocket;                 // Socket for receiving client requests
	int status;                       // Return status
	struct sigaction interrupt;       // Signal action for handling interrupt
	struct sockaddr_in serverAddress; // Server address

	// Configure the server address.
	serverAddress.sin_family = AF_INET;         // IPv4
	serverAddress.sin_port = htons(port);       // Big-endian conversion
	serverAddress.sin_addr.s_addr = INADDR_ANY; // Localhost

	// Create a server-side socket.
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		perror("socket");
		exit(1);
	}

	// Associate server-side socket with listening port.
	status = bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
	if (status == -1) {
		perror("bind");
		exit(1);
	}

	// Listen for connections.
	status = listen(serverSocket, BACKLOG);
	if (status == -1) {
		perror("listen");
		exit(1);
	}

	// Register a callback to handle an interrupt signal.
	interrupt.sa_handler = &handleInterrupt;
	interrupt.sa_flags = 0;
	sigemptyset(&interrupt.sa_mask);
	status = sigaction(SIGINT, &interrupt, 0);
	if (status == -1) {
		perror("sigaction");
		exit(1);
	}

	// Accept and handle connection requests until interrupted.
	while (1) {
		// Accept an incoming connection.
		connectedSocket = accept(serverSocket, NULL, NULL);
		if (connectedSocket == -1) {
			perror("accept");
			exit(1);
		}
		printf("Connection with client opened\n");
		printf("Enter \"\\quit\" to close connection\n");

		// Exchange messages between the client and server.
		runChatSession(connectedSocket);

		// Terminate the connection.
		status = close(connectedSocket);
		if (status == -1) {
			perror("close");
			exit(1);
		}
	}
}


/*
 * Function: stripWhitespaces
 *
 * Purpose:  This function removes leading and trailing whitespace characters
 *           from a c-string.
 *
 * Receives: str - c-string string to be stripped of whitespaces
 *
 * Returns:  None
 *
 * Pre:      The input c-string shall not reference a string literal.
 *
 * Post:     'str' is modified.
 */
void stripWhitespaces(char *str)
{
	char *start; // Reference to the string's beginning.
	char *end;   // Reference to the string's end.

	// Reference the end of the string.
	end = strchr(str, '\0');

	// Terminate the string after the final non-whitespace character.
	while (isspace(*--end));
	*++end = '\0';

	// Reference the first non-whitespace character.
	start = str;
	while (isspace(*start)) { ++start; }

	// Copy the stripped string into the original.
	strcpy(str, start);
}
