# Brett Fedack
# CS372 Summer 2015
# Project 1
# Description: This program is a client that connects with a server to engage
#     in an alternating chat session. The dialogue persists until one host
#     closes the connection, at which point this program ends.

import re                                        # Regular expressions
import sys                                       # System-specific parameters
from socket import socket, AF_INET, SOCK_STREAM  # Sockets API
from struct import pack, unpack                  # Structured binary data
HANDLE_SIZE = 10 # Number of bytes reserved for handle in message protocol

def main():
    # Exactly three command-line arguments are expected.
    if len(sys.argv) != 3:
        print 'usage: python2 chatclient <server-hostname> <port #>'
        sys.exit(1)
    serverHost = sys.argv[1]
    serverPort = sys.argv[2]

    # The given port number must be an integer.
    if not isStrInt(serverPort):
        print  'chatclient: Port number must be an integer'
        sys.exit(1)
    serverPort = int(serverPort)

    # The given port number must be in the range [1024, 65535].
    if int(serverPort) < 1024 or int(serverPort) > 65535:
        print  'chatclient: Port number must be in the range [1024, 65535]'
        sys.exit(1)

    # Run the chat client until the client-server connection is closed.
    startChatClient(serverHost, serverPort)

    sys.exit(0)


# Function: getMessage
#
# Purpose:  This function retrieves a valid message from standard input.
#
# Receives: handle - identifier for message author
#
# Returns:  A valid message is returned.
#
# Pre:      None
#
# Post:     None
def getMessage(handle):
    maxMessageSize = 500

    # Get a valid message from standard input.
    while True:
        # Prompt the client for a message.
        message = raw_input('{0}> '.format(handle)).strip()

        # Validate the input.
        if len(message) < 1 or len(message) > maxMessageSize:
            print 'Message must be between 1 and {0} characters'.format(maxMessageSize)
        else:
            break

    return message


# Function: getUserHandle
#
# Purpose:  This function retrieves a valid user handle from standard input.
#
# Receives: None
#
# Returns:  A valid user handle is returned.
#
# Pre:      None
#
# Post:     None
def getUserHandle():
    # Get a valid user handle.
    while True:
        # Prompt the user for his/her handle.
        handle = raw_input('Enter a user handle: ').strip()

        # Validate the user's input.
        if len(handle) < 1 or len(handle) > HANDLE_SIZE:
            print 'User handle must be between 1 and {0} characters'.format(HANDLE_SIZE)
        else:
            break

    return handle


# Function: isStrInt
#
# Purpose:  This function determines if the given string represents an integer.
#
# Receives: string - string that may represent an integer
#
# Returns:  Whether or not the string represents an integer is returned.
#
# Pre:      None
#
# Post:     None
def isStrInt(string):
    # Assist matching by stripping leading and trailing whitespace characters.
    string = string.strip()

    # Attempt to match an integer substring.
    result = re.match('[0-9]+', string)
    if result is None:
        return False

    # The given string represents an integer if all characters are matched.
    return string == result.group(0)


# Function: recvAll
#
# Purpose:  This function invokes 'recv' as many times as necessary to receive
#           all of the given bytes of data.
#
# Receives: socket - connection endpoint on which to receive data
#           numBytes - target number of bytes to receive
#
# Returns:  The buffer of received data is returned.
#
# Pre:      A connection shall be established on the given socket.
#
# Post:     None
def recvAll(socket, numBytes):
    # Retrieve the given number of bytes.
    data = '';
    while len(data) < numBytes:
        try:
            data += socket.recv(numBytes - len(data))
        except Exception as e:
            print e.strerror
            sys.exit(1);

    return data


# Function: recvPacket
#
# Purpose:  This function receives a message packet from the given socket.
#
#           The message protocol is based on section 7.5 of Beej's Guide to
#           Network Programming.
#                                  _   Header
#               length  - 2 bytes   |_/
#               handle  - 10 bytes _|   Data
#               message - X bytes  ____/
#
# Receives: socket - connection endpoint on which to receive data
#
# Returns:  A (handle, message) tuple is returned.
#
# Pre:      A connection shall be established on the given socket.
#
# Post:     None
def recvPacket(socket):
    # Receive the packet length.
    packetLength = unpack('>H', recvAll(socket, 2))[0]

    # Receive the handle field.
    handle = recvAll(socket, HANDLE_SIZE)

    # Receive the message data.
    message = recvAll(socket, packetLength - HANDLE_SIZE - 2)

    return handle, message


# Function: runChatSession
#
# Purpose:  This function alternates between sending and receiving message
#           packets from the client to a server.
#
#           The message protocol is based on section 7.5 of Beej's Guide to
#           Network Programming.
#
# Receives: clientSocket - client's endpoint of client-server connection
#           clientHandle - identifier for client
#
# Returns:  None
#
# Pre:      A connection shall be established on the given socket.
#
# Post:     None
def runChatSession(clientSocket, clientHandle):
    while True:
        # Get a message from the client.
        message = getMessage(clientHandle)

        # Close the chat session on both ends if necessary.
        if message == '\quit':
            print 'Connection with server closed'
            sendPacket(clientSocket, clientHandle, '\quit')
            break

        # Send message packet to the server.
        sendPacket(clientSocket, clientHandle, message)

        # Receive message packet from the server.
        serverHandle, message = recvPacket(clientSocket)

        # Close the chat session on the client if necessary.
        if message == '\quit':
            print 'Connection with server closed'
            break

        # Display received message.
        print '{0}> {1}'.format(serverHandle, message)


# Function: sendPacket
#
# Purpose:  This function sends a message packet from the given socket.
#
#           The message protocol is based on section 7.5 of Beej's Guide to
#           Network Programming.
#                                  _   Header
#               length  - 2 bytes   |_/
#               handle  - 10 bytes _|   Data
#               message - X bytes  ____/
#
# Receives: socket  - connection endpoint on which to send data
#           handle  - author of message
#           message - message data to encapsulate
#
# Returns:  None
#
# Pre:      A connection shall be established on the given socket.
#
# Post:     None
def sendPacket(socket, handle, message):
    # Determine message packet length.
    packetLength = 2 + HANDLE_SIZE + len(message)

    # Build the message packet.
    packet = pack('>H', packetLength)
    packet += handle.ljust(HANDLE_SIZE, '\0')
    packet += message

    # Send message packet to the server.
    try:
        socket.sendall(packet)
    except Exception as e:
        print e.strerror
        sys.exit(1)


# Function: startChatClient
#
# Purpose:  This function runs a client that connects to a sever on the given
#           host address and port number, and engages the server in an
#           alternating chat session.
#
# Receives: serverHost - IP address of server
#           serverPort - server-side port for receiving client requests
#
# Returns:  None
#
# Pre:      The server-side port shall be at least 1024 to avoid conflicts with
#           standard services.
#
#           The server-side port shall be no greater than 65535 to stay within
#           the bounds of available ports.
#
# Post:     None
def startChatClient(serverHost, serverPort):
    # Associate the client with a handle.
    clientHandle = getUserHandle()

    # Create a client-side socket.
    try:
        clientSocket = socket(AF_INET, SOCK_STREAM, 0)
    except Exception as e:
        print e.strerror
        sys.exit(1)

    # Establish a connection between the client and server.
    try:
        clientSocket.connect((serverHost, serverPort))
    except Exception as e:
        print e.strerror
        sys.exit(1)
    print 'Connection with server opened'
    print 'Enter "\quit" to close connection'

    # Exchange messages between the client and server.
    runChatSession(clientSocket, clientHandle)

    # Close the client-server connection.
    try:
        clientSocket.close()
    except Exception as e:
        print e.strerror
        sys.exit(1)


# Define script point of entry.
if __name__ == '__main__':
    main()
