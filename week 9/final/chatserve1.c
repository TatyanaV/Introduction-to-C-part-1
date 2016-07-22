/*
 * Project 1
 * Description: This program is a server that connects with one client at a
 *     time to engage in an alternating chat session. The dialogue persists
 *     until one host closes the connection. Thereafter, the server continues
 *     to listen for client requests until receiving an interrupt signal.
 *  https://github.com/lewallep/cs372/blob/master/Proj1/chatserve.c
 https://github.com/nelseric/chat/blob/master/server/server.c
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
#include <ctype.h>

#define BACKLOG       5 // Arbitrary queue size of connection requests
#define MAX_ARG_LEN 256 // Maximum number of characters in command-line argument
#define MAX_MSG_LEN 500 // Number of characters for the message - up to 500
#define HANDLE_SIZE  10 // Number of characters for the host B = client handler

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
    // chartserce on host A waits fon a port[specified by command-line] for a client request
    //using command line, 2 arguments are expected:
    //1.chartserve
    //2. <port # on which to listen for connection requests, must be in the range [1024, 65535]
    // if incorrect number of arguments are entered display an error
    char c;
	if (argc != 2) {
        fprintf(stderr, "ERROR: No port specified.\n");
		fprintf(stderr, "Please type: chatserve <port #>, port must be in the range 1024-65535\n");
		exit(1);
	}

	// checks and make sure that an integer was entered for the port
	if (!isInt(argv[1])) {
		fprintf(stderr, "ERROR: Port number must be an integer\n");
		exit(1);
	}
	//Reads data from s and stores them according to parameter format into the locations given
	//by the additional arguments, as if scanf was used, but reading from s instead of the standard input (stdin).
    sscanf(argv[1], "%d %c", &port, &c);
	//per the following refferences: port # in the range 1024-65535 can be freely used
	//page 193 Computer Networkinng top down approach
	//https://technet.microsoft.com/en-us/library/gg398833.aspx
	//https://books.google.com/books?id=nDnSBQAAQBAJ&pg=PA389&lpg=PA389&dq=port+numbers+used+for+servers+1024-65535+chats&source=bl&ots=P50QoqyGGC&sig=7zbmQcn6m13xumh_aJl3bHB-c5E&hl=en&sa=X&ved=0CEoQ6AEwB2oVChMIudbevKLuyAIVRM9jCh2bEwcD#v=onepage&q=port%20numbers%20used%20for%20servers%201024-65535%20chats&f=false
	if (port < 1024 || port > 65535) {
		fprintf(stderr, "ERROR: Port number must be in the range [1024, 65535]\n");
		exit(1);
	}

	// if both chartserve and the port number in the range 1024-65535 were entered
	//the chat SERVER will be run until interrupt signal is detected
	startChatServer(port);
	exit(0);
}


/*Retrieves a  valis message from stanadrd input
    receives:   handle - c-string identifier for message author
                message - output characer buffer for message
    returns:    valid message
    pre:        message should be large enough to hold all bytes of the message
    post:       modified message
 */
void getMessage(char *handle, char *message){
	// Get a valid message from standard input.
	while(1) {
		// Prompt the server for a message.
		printf("%s> ", handle);
		//http://www.cplusplus.com/reference/cstdio/fgets/
		//read characters from teh screem, the maximum length is 500 and store the message in the variable message
		fgets(message, MAX_MSG_LEN, stdin);
		//remove white spaces from the message
		//http://stackoverflow.com/questions/13084236/function-to-remove-spaces-from-string-char-array-in-c
		//trimming leading and trailing whitespace from a string in C
		stripWhitespaces(message);

		// making sure that the message is between 1 -500 charactes long
		if (strlen(message) < 1 || strlen(message) > MAX_MSG_LEN) {
			printf("Message must be between 1 and %d characters\n", MAX_MSG_LEN);
		}
		else { break; }
	}
}

/*Provides feedback before terminating the 'CHATSERVE' program in response to an interrupt signal
function is taken from http://pubs.opengroup.org/onlinepubs/009695399/functions/sigaction.html
function uses sigaction that allows the calling process to examine and/or specify the action to
be associated with a specific signal, action will be set to SEG_DFL for the default action

    receives:   signal number
    returns:    nothing
    pre:        none
    post:       program terminates
 */
 //http://man7.org/linux/man-pages/man2/sigaction.2.html
 //http://man7.org/linux/man-pages/man7/signal.7.html
void handleInterrupt(int sig){
	int status;                   // Return status
	//used to change the action taken by a process on receipt of a specific signal
	struct sigaction interrupt;   // Signal action for handling interrupt

	// Provide feedback to the user.
	printf("\nchatserve closed\n");

	//sa_handler specifies the action to be associated with signum, will be set to SIG_DFL for the default action
	interrupt.sa_handler = SIG_DFL;
	//checkes the status of the signation
	//Upon successful completion, sigaction() shall return 0; otherwise, -1 shall be returned,
    //perrno will be set to indicate the error, and no new signal-catching function will be installed.
	status = sigaction(SIGINT, &interrupt, 0);
	if (status == -1) {
		perror("ERROR: error occured in sigaction");
		exit(1);
	}

	// causes signal SIGINT to be genereated and sends an interrupt signal to
	// the executing process in order to force the default behavior.
	//Upon successful completion, 0 shall be returned.
	//Otherwise, a non-zero value shall be returned  and errno shall be set to indicate the error
	//http://pubs.opengroup.org/onlinepubs/009695399/functions/raise.html
	//http://www.tutorialspoint.com/c_standard_library/c_function_raise.htm
	status = raise(SIGINT);
	if (status == -1) {
		perror("ERROR: in raising the SIGINT");
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

/*Function that used 'recv()(for TCP SOCK_STREAM sockets) ' function to receive messages from a connected socket
  if no messages are available at the socket, the receive call waits for a message to arrive
    receives:   socket - connection endpoint on which to receive data
                buffer - data destination
                numBytes - target number of bytes to receive
    returns:    none
    pre:        established connection on the given socket
                buffer is large enough to hold a given # of bytes
    post:       modified buffer
 */
//http://man7.org/linux/man-pages/man2/recv.2.html
void recvAll(int socket, void *buffer, int numBytes){
	int ret;               // Return value for 'recv'
	int receivedBytes;     // Total number of bytes received

	// Retrieve the given number of bytes.
	receivedBytes = 0;
	while (receivedBytes < numBytes) {
	    //receives messages from a connected socket
	    //no messages are available at the socket, the receive calls wait for a message to arrive
	    //ssize_t recv(int sockfd, void *buf, size_t len, int flags);
	    /*
	    The recv() function takes the following arguments:
        socket    Specifies the socket file descriptor.
        buffer    Points to a buffer where the message should be stored.
        length    Specifies the length in bytes of the buffer pointed to by the buffer argument.
        flags    Specifies the type of message reception.
        */
		ret = recv(socket, buffer + receivedBytes, numBytes - receivedBytes, 0);

		// Error encountered.
		if (ret == -1) {
			perror("ERROR: in recv function while receiving message for a connected socket");
			exit(1);
		}

		// Data received.
		else {
			receivedBytes += ret;
		}
	}
}

/*Function that receives a message packet from the given socket
    receives:   socket - connection endpoint on which to receive data
                handle - output buffer for header field containing author
                message - output buffer for encapsulated message datave
                The message protocol is based on section 7.5 of Beej's Guide to Network Programming.
                                   _   Header
                length - 2 bytes     |_/
                handle - 10 bytes   _|   Data
                message - 500 bytes ____/
    returns:    none
    pre:        established connection on the given socket
                buffer is large enough to hold a given # of bytes
    post:       'handle' and 'message' are modified
 */

void recvPacket(int socket, char *handle, char *message){
	unsigned short packetLength;  // Number of bytes in packet
	unsigned short messageLength; // Number of bytes in message

	// Receive the packet length.
	recvAll(socket, &packetLength, sizeof(packetLength));
	//converts the unsigned short integer netshort from network byte order to host byte order
    // convert our byte orderings to "big-endian" before receiving them
	//see http://beej.us/guide/bgnet/output/html/multipage/htonsman.html
	packetLength = ntohs(packetLength);

	// Receive the handle field.
	recvAll(socket, handle, HANDLE_SIZE);
	handle[HANDLE_SIZE] = '\0';
	// Receive the message data.
	messageLength = packetLength - HANDLE_SIZE - sizeof(packetLength);
	recvAll(socket, message, messageLength);
	message[messageLength] = '\0';
}

/*Function alternates between receiveing and sending message packets from a clent to the server
    receives:   connectedSocket - server's endpoint of client-server connection
    returns:    none
    pre:        there is a connection on the given socket
    post:       none
 */
void runChatSession(int connectedSocket){
	char clientHandle[HANDLE_SIZE + 1];         // Identifier for the client
	char serverHandle[HANDLE_SIZE + 1];         // Identifier for the server
	char message[MAX_MSG_LEN + 1];              // Message buffer
	// Associate the server with a handle.
	//fill memory with a constant byte
	//void *memset(void *s, int c, size_t n);
	// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
	//hardcoding HANDLE for the server
	memset(serverHandle, '\0', HANDLE_SIZE + 1);
	strcpy(serverHandle, "SERVER");

	while (1) {
		// Receive message packet from the client.
		recvPacket(connectedSocket, clientHandle, message);

		// Close the chat session on the server if necessary.
		if (strcmp(message, "\\quit") == 0) {
			printf("Clint requested to close connection. Connection with client closed\n");
			break;
		}

		// if connection is not closed: Display received message.
		printf("%s> %s\n", clientHandle, message);

		// Get a message from the server.
		getMessage(serverHandle, message);

		// Close the chat session on both ends if necessary.
		if (strcmp(message, "\\quit") == 0) {
			printf("Connection with client closed by the SERVER'S request\n");
			sendPacket(connectedSocket, serverHandle, "\\quit");
			break;
		}

		// Send message packet to the client.
		sendPacket(connectedSocket, serverHandle, message);
	}
}


/*Function that invokes 'send' as many times as necessary to send all of the given bytes of data
    receives:   socket - connection endpoint on which to send data
                buffer - data source
                numBytes - target number of bytes to send
    returns:    none
    pre:        there is a connection on the given socket
                buffer is large enough to accomodate a message
    post:       none
 */
void sendAll(int socket, void *buffer, int numBytes){
	int ret;           // Return value for 'send'
	int sentBytes;     // Total number of bytes sent

	// Send the given number of bytes.
	sentBytes = 0;
	while (sentBytes < numBytes) {
	    //function similar to recv, but this function sends messages
	    //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
	    //http://man7.org/linux/man-pages/man2/send.2.html
	    //http://beej.us/guide/bgnet/output/html/multipage/sendman.html
		ret = send(socket, buffer + sentBytes, numBytes - sentBytes, 0);
		// Error encountered.
		if (ret == -1) {
			perror("ERROR: in send function when sending a message");
			exit(1);
		}

		// Data sent.
		else {
			sentBytes += ret;
		}
	}
}

/*Function that invokes 'sendAll' function to send a message packet from a given socket
    receives:   socket - connection endpoint on which to send data
                handle - input c-string for author of message
                message - input c-string for message data to encapsulate
                The message protocol is based on section 7.5 of Beej's Guide to Network Programming.
                                   _   Header
                length - 2 bytes     |_/
                handle - 10 bytes   _|   Data
                message - 500 bytes ____/

    returns:    none
    pre:        established connection on the given socket
                buffer is large enough to hold a given # of bytes
    post:       'handle' and 'message' are modified
 */
void sendPacket(int socket, char *handle, char *message){
	unsigned short packetLength;  // Number of bytes in packet

	// Send the packet length.
	//htons--converts the unsigned short integer netshort from network byte order to host byte order
	// convert our byte orderings to "big-endian" before sending them out
	//see http://beej.us/guide/bgnet/output/html/multipage/htonsman.html
	packetLength = htons(sizeof(packetLength) + HANDLE_SIZE + strlen(message));
	sendAll(socket, &packetLength, sizeof(packetLength));

	// Send the handle field.
	sendAll(socket, handle, HANDLE_SIZE);

	// Send the message data.
	sendAll(socket, message, strlen(message));
}

/*Function runs a server that listens on a given port # and talks to 1 client at a time using ALTERNATING chat session
    receives:   port - machine port to interface with clients
    returns:    none
    pre:        The listening port should be in the range [1024 -65535] to avoid conflicts with standard services.
    post:       none
 */
 //https://en.wikibooks.org/wiki/C_Programming/Networking_in_UNIX
void startChatServer(int port){
	int connectedSocket;              // Socket created upon accepting client
	int serverSocket;                 // Socket for receiving client requests
	int status;                       // Return status
	struct sigaction interrupt;       // Signal action for handling interrupt
	struct sockaddr_in serverAddress; // Server address

	// Configure the server address
	//http://man7.org/linux/man-pages/man7/ip.7.html
	// address family, network is IPv4. According to the book, page 160 we do not
	//need to worry about understanding this right now, we will cover IPv4 in chapter 4
	serverAddress.sin_family = AF_INET;
	//big-indian conversion
	//set port number
	serverAddress.sin_port = htons(port);
	//set IP number - localhost -- this nunmber will be indicated by the user 127.0.0.1
	//When INADDR_ANY is specified in the bind call,
    //the socket will be bound to all local interfaces
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	// Create a server-side socket
	//we are using AF_INET -- IPv4 network
	//SOCK_STREAM---socket type is TCP
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		perror("ERROR: in creating a server socket");
		exit(1);
	}

	// Associate server-side socket with listening port.
	//binding the server socekt [that is, assigning] the port number to the servers socket
	status = bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
	//if (status == -1) {
		//perror("bind");
		//exit(1);
	//}

	// Listen for connections
	//http://linux.die.net/man/2/listen
	//int listen(int sockfd, int backlog);
	// backlog argument defines the maximum length to which the queue of pending connections for sockfd may grow
	//for more information see http://linux.die.net/man/2/listen
	status = listen(serverSocket, BACKLOG);
	if (status == -1) {
		perror("ERROR: in the listen function");
		exit(1);
	}

	// Register a callback to handle an interrupt signal.
	interrupt.sa_handler = &handleInterrupt;
	interrupt.sa_flags = 0;
	//initializes the signal set given by set to empty, with all signals excluded from the set.
	//http://gnats.netbsd.org/29944
	sigemptyset(&interrupt.sa_mask);
	status = sigaction(SIGINT, &interrupt, 0);
	if (status == -1) {
		perror("ERROR: in the sigaction function");
		exit(1);
	}

	// Accept and handle connection requests until interrupted.
	while (1) {
		// AAccept a connection with the accept() system call.
		//This call typically blocks until a client connects with the server.
		//http://www.tutorialspoint.com/unix_sockets/socket_server_example.htm
		connectedSocket = accept(serverSocket, NULL, NULL);
		if (connectedSocket == -1) {
			perror("ERROR: in accept function");
			exit(1);
		}
		printf("Connection with client opened\n");
		printf("Enter \"\\quit\" to close connection\n");
		//if connection is accepted start communicating
		runChatSession(connectedSocket);
		// Terminate the connection.
		status = close(connectedSocket);
		if (status == -1) {
			perror("ERROR: in close function");
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
void stripWhitespaces(char *str){
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
