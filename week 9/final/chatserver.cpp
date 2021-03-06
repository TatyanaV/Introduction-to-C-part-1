// CS372 Project #1
// Programmer: Joe Kramer
// Reference: http://beej.us/guide/bgnet/

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

//Globals
struct sockaddr_in hostAddress;
char serverHandle[510] = "SERVER";	//Used as the server I.D.
char inBuffer[510];
char outBuffer[510];
int listenChat;
int portNumber;
int connectChat;
string clientsUserName;

// These boolians are used to handle when the client quits the connections but
// the sever still stays active while looking for another connection.
bool incommingEndConnection;
bool outGoingEndConnection;
bool endConnection;

/*Function to process the username = HANDLER of the client
    receives:   none
    returns:    none
    pre:        none
    post:       none
 */
void incomingUserName(){
    //fill memory with a constant byte
	//void *memset(void *s, int c, size_t n);
	// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c
	//clearning the buffer by filling it 0
	memset(&inBuffer, 0, sizeof(inBuffer));
    //receives messages from a connected socket
    //no messages are available at the socket, the receive calls wait for a message to arrive
    //ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    /*
    The recv() function takes the following arguments:
        socket    Specifies the socket file descriptor.
        buffer    Points to a buffer where the message should be stored.
        length    Specifies the length in bytes of the buffer pointed to by the buffer argument.
        flags     Specifies the type of message reception.
    */
    //please note that the size of the buffer is 500
    int receiveCheck;
	receiveCheck = recv(connectChat, inBuffer, 500, 0);
    // Error encountered
    if (receiveCheck == -1) {
        cerr << "ERROR: in recv function while receiving message for a connected socket" << endl;
        exit(1);
    }
    else {
        //in this case everything that was typed by the user will be the username
        clientsUserName = inBuffer;
    }

}


/*Function to create a socket
//http://www.cis.gvsu.edu/~wolffe/courses/cs656/projects/tutorial_CSockets.html
    receives:   none
    returns:    none
    pre:        none
    post:       none
 */
void creatNewSocket(){
    /*
    The socket() call creates an unnamed socket and returns a file descriptor to the calling process.
    The function prototype is as follows:  int socket(int domain, int type, int protocol);
    where domain specifies the address domain, type specifies the socket type, and the third
    argument is the protocol (this is usually set to 0 to automatically select the appropriate default).
    Here is a typical socket() call:    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    This establishes a socket in the Internet domain, and configures it for stream-oriented
    communication using the default TCP protocol*/
	listenChat = socket(AF_INET, SOCK_STREAM, 0);
    //fill memory with a constant byte
	//void *memset(void *s, int c, size_t n);
	// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c
	//clearning the buffer by filling it 0
	memset(&hostAddress, '0', sizeof(hostAddress));
    // Configure the server address
	//http://man7.org/linux/man-pages/man7/ip.7.html
	// address family, network is IPv4. According to the book, page 160 we do not
	//need to worry about understanding this right now, we will cover IPv4 in chapter 4
	hostAddress.sin_family = AF_INET;
    //set port number
    //converts the unsigned short integer netshort from network byte order to host byte order
    // convert our byte orderings to "big-endian" before receiving them
	//see http://beej.us/guide/bgnet/output/html/multipage/htonsman.html
	hostAddress.sin_port = htons(portNumber);
    //the socket will be bound to all local interfaces
    // Scince this is a server, the IP address has been set to INADDR_ANY,
    //specifying that connections will be accepted from any other host.
	hostAddress.sin_addr.s_addr = htonl(INADDR_ANY);
}


/*Function to send messages to the connected client
    receives:   none
    returns:    none
    pre:        none
    post:       none
 */
void outGoingChat(){
    //clients handler
	cout << clientsUserName << "> " << inBuffer << endl;
	//server handler
	cout << serverHandle << "> ";
	//can accept up to 500 charactesr
	//sizeof ( line )
	//char outBuffer1[510];
	cin.getline(outBuffer, sizeof(outBuffer));
	//string will be used to check if appropriate size of message was enered
	string easyComparisonString = outBuffer;
	// used to verify string length is over 500
	while(easyComparisonString.length() > 500 || easyComparisonString.length() < 1 ){
		memset(&outBuffer, 0, sizeof(outBuffer));
		if(easyComparisonString.length() > 500){
            cout << "ERROR: Your message is more than 500 characters long. Retype your message." << endl;
		}
        if(easyComparisonString.length() < 1 ){
            cout << "ERROR: Your message is less than 1 character long. Retype your message." << endl;
		}
		cout << serverHandle << "> ";
		cin.clear();
		cin.ignore(easyComparisonString.length(), '\n');
		cin.getline(outBuffer, sizeof(outBuffer));
		//cin.ignore(easyComparisonString.length(), '\n');
		//cin.clear();
		easyComparisonString.clear();
		easyComparisonString = outBuffer;
	}

	// If user would like to quit then quit
	if (easyComparisonString == "\\quit")	{
		cout << "Server requested to close connection. Waiting for new connection..." << endl << endl;
		outGoingEndConnection = true;
		endConnection = true;
	}

    if (easyComparisonString.length() < 500){
            easyComparisonString = outBuffer;
            send(connectChat, outBuffer, strlen(outBuffer), 0);
        }
    //function sends messages
    //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    //http://man7.org/linux/man-pages/man2/send.2.html
    //http://beej.us/guide/bgnet/output/html/multipage/sendman.html
	// Used to send data to the client
	//send(connectChat, outBuffer, strlen(outBuffer), 0);
}

/*Function to read messages from the client
    receives:   none
    returns:    none
    pre:        none
    post:       none
 */
void incomingChat(){
    //receives messages from a connected socket
    //no messages are available at the socket, the receive calls wait for a message to arrive
    //ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    /*
    The recv() function takes the following arguments:
        socket    Specifies the socket file descriptor.
        buffer    Points to a buffer where the message should be stored.
        length    Specifies the length in bytes of the buffer pointed to by the buffer argument.
        flags     Specifies the type of message reception.
    */
    //please note that the size of the buffer is 500
	recv(connectChat, inBuffer, 500, 0);
	string easyComparisonString = inBuffer;
	// If a client wants to quit
	if (easyComparisonString == "\\quit"){
		cout << "Client requested to close connection. Waiting for new connection..." << endl << endl;
		incommingEndConnection = true;
		endConnection = true;
	}
}




/*Function to accept an incomming connection. The read messages from the client.
note that server handler is hardcoded to SERVER
    receives:   none
    returns:    none
    pre:        none
    post:       none
 */
void approveConenction(){
	// Accept incoming requests.
	while(1){
        // AAccept a connection with the accept() system call.
		//This call typically blocks until a client connects with the server.
		//http://www.tutorialspoint.com/unix_sockets/socket_server_example.htm
		connectChat = accept(listenChat, (struct sockaddr*)NULL,NULL);
		cout << "Connection with client opened." << endl;
        //function sends messages
        //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        //http://man7.org/linux/man-pages/man2/send.2.html
        //http://beej.us/guide/bgnet/output/html/multipage/sendman.html
        // Used to send data to the client
		send(connectChat, serverHandle, strlen(serverHandle),0);
		//get the clients name
		incomingUserName();
		//Logic sentinels to manage if the client decided to quit or not.
		endConnection = false;
		incommingEndConnection = false;
		outGoingEndConnection = false;

		while(!endConnection){
			// Used to reset the buffers.
			memset(&outBuffer, 0, sizeof(outBuffer));
			memset(&inBuffer, 0, sizeof(inBuffer));
            //read messages from the client
			incomingChat();
            //if te client requested to end connecting
			if(incommingEndConnection){
				close(connectChat);
                // Listen for connections
                //http://linux.die.net/man/2/listen
                //int listen(int sockfd, int backlog);
                // backlog argument defines the maximum length to which the queue of pending connections for sockfd may grow
                //for more information see http://linux.die.net/man/2/listen
				listen(listenChat, 10);
			}
			else
                //if still connected send messages to the connected client
				outGoingChat();
            //if the server requested to end connection
			if(outGoingEndConnection){
				close(connectChat);
                // Listen for connections
                //http://linux.die.net/man/2/listen
                //int listen(int sockfd, int backlog);
                // backlog argument defines the maximum length to which the queue of pending connections for sockfd may grow
                //for more information see http://linux.die.net/man/2/listen
				listen(listenChat, 10);
			}
		}
	}
}


// Used to handle kill signals from the user.
void sigintHandler(int pram){
	char quitBuffer[500];
	quitBuffer[0]='\\';
	quitBuffer[1]='q';
	quitBuffer[2]='u';
	quitBuffer[3]='i';
	quitBuffer[4]='t';
	cout << "\n ** Signal Received ** Server has shut down...\n" <<  endl;
	send(connectChat, quitBuffer, strlen(quitBuffer), 0);		//Used to send a quit command to the client, because the server has shut down.
	close(connectChat);
	exit(1);
}


// This function is ment to be as a guide function. It will call all the functions
// to run the socket program.
int main(int argc, char **argv){
    int portNumberCheck; //to validate the correct entry was made for port number
    // chartserce on host A waits fon a port[specified by command-line] for a client request
    //using command line, 2 arguments are expected:
    //1.chartserve
    //2. <port # on which to listen for connection requests, must be in the range [1024, 65535]
    // if incorrect number of arguments are entered display an error
  	if(argc!=2){
		cerr << "ERROR: No port specified. Type: ./chatserver.cpp <port number>, port must be in the range [1024-65535] " << endl;
		exit(1);
	}
    //per the following refferences: port # in the range 1024-65535 can be freely used
	//page 193 Computer Networkinng top down approach
	//https://technet.microsoft.com/en-us/library/gg398833.aspx
	//https://books.google.com/books?id=nDnSBQAAQBAJ&pg=PA389&lpg=PA389&dq=port+numbers+used+for+servers+1024-65535+chats&source=bl&ots=P50QoqyGGC&sig=7zbmQcn6m13xumh_aJl3bHB-c5E&hl=en&sa=X&ved=0CEoQ6AEwB2oVChMIudbevKLuyAIVRM9jCh2bEwcD#v=onepage&q=port%20numbers%20used%20for%20servers%201024-65535%20chats&f=false
	// places the port number in the var
	portNumberCheck = atoi(argv[1]);
	if (portNumberCheck < 1024 || portNumberCheck > 65535) {
		cerr << "ERROR: Port number must be in the range [1024 - 65535]" << endl;
		exit(1);
	}

	signal(SIGINT, sigintHandler);
	//place the port # in the variable
	portNumber = atoi(argv[1]);
	//creat new socket
	creatNewSocket();
	// Associate server-side socket with listening port.
	//binding the server socekt [that is, assigning] the port number to the servers socket
	bind(listenChat, (struct sockaddr*)&hostAddress, sizeof(hostAddress));
    // Listen for connections
    //http://linux.die.net/man/2/listen
    //int listen(int sockfd, int backlog);
    // backlog argument defines the maximum length to which the queue of pending connections for sockfd may grow
    //for more information see http://linux.die.net/man/2/listen
	listen(listenChat, 10);
	//accept an incomming connection. The read messages from the client.
	approveConenction();
	return 0;
}






























