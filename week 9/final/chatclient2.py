#CS372 Project #1
#Programmer: Joe Kramer
#Reference: https://docs.python.org/2/library/socket.html
#			http://www.tutorialspoint.com/python/python_networking.htm

import socket # the socket module forms the basis of all network communications
import getopt
import sys
import os

# Used to process outgoing messages via send()
# also used to display the users chosen username		
def outGoingBuffer(socket_holder, newUserName):
	#print newUserName
	sys.stdout.write(newUserName)
	out_buffer = raw_input("> ")
	
	# Used to verify string length is over 500
	while (len(out_buffer) > 500 or len(out_buffer) < 1 ):
		print "Please enter a message between [1-500] characters."
		#out_buffer = raw_input(string(newUserName) + '>')
		sys.stdout.write(newUserName)
		out_buffer = raw_input("> ")
	#the line below, sends the string with the users name and message using TCP connection
	socket_holder.send(out_buffer)
	if out_buffer == "\quit":
		print "You have requested to close this connection. Good Bye"
		#connection is closed
		socket_holder.close
		sys.exit()	
	

# used to check the command line arguments
# also used to call the messagingClient function, which runs the 
# the majority of the program. 	
if __name__ == '__main__':
	if len(sys.argv) != 3:
		print "ERROR: Please Enter: python chatclient.py <IP Address> <Port Number>"
		sys.exit()
	#IP address is the second argument
	ip_address = sys.argv[1]
	#port number is the 3rd argument
	port_number = int(sys.argv[2])
	#creates a clients socket.
	#the 1st parameter indicates the address familyt, AF_INET indicates that the underlighting network is IPv4
	#2nr parameter indicates that the socket is of type SOCK_STREAM, which means that it is TCP socket
	socket_holder = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	#before the client can send data to the server using TCP socket, a TCP connection must be first established between
	#server and the client
	#the line below initiates a connection between client and the server
	#the paremeter of the connect() function is the adress of the SERVER side of the connection - IP and PORT #
	socket_holder.connect((ip_address, port_number))
	#Receives the servers name which is hardcoded as SERVER
	serverName = socket_holder.recv(500)

	# This block is used to get the users desired username.
	newUserName = raw_input("Please enter a User Name:")
	#print len(newUserName)
	while 1 > len(newUserName) or len(newUserName) > 10:
		newUserName = raw_input("User Name must be between [1-10] characters. Reenter a User Name: ")
	#the line below, sends the string with the users name theough the client's socket and into the TCP connection
	socket_holder.send(newUserName)
	while 1:
		#send the username and the message to the server
		#waits for the response from the sender
		outGoingBuffer(socket_holder, newUserName)
		#when charactes arrive from the server, they get placed into a string. Characters
		#continue to accumulate until the line ends with a carriage character.
		#the buffer size is 500
		#the message from the server is displayed
		in_buffer = str(socket_holder.recv(500))
		#is the message that was sent by the server states that the server wants to quit
		if in_buffer == "\quit":
			print "Server requested to close connection. Good Bye"
			#clients socket is closed
			socket_holder.close()
			sys.exit()
		#if the server does not want to close a connection, a client is prompted to type another message
		else:

			print serverName + "> " + in_buffer
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 