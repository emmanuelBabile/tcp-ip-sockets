# About the project

Statement of the project
------------------------
Realization of a server program and two clients with TCP/IP sockets so that the server calculates the sum of the numbers from 1 to N.
The N is sent by the clients and the results will be sent from the server to the clients in using for() processes in the server.

Warning
-------
* If you enter a letter or another thing, it will return a loop. To exit this loop, you should enter ctrl+C or ctrl+Z.
The solution was to check the type of the inserted value but this function does not exist in C.

In general, with C you're expected to know the types of your variable.

** To disconnect from the server, enter 0 or a negative number.

Build and execution steps
-------------------------
Build Steps :
1. gcc tcpSocketServer.c -o tcpSocketServe
2. gcc tcpSocketClient.c -o tcpSocketClient

Execute Steps :
1. Run the server using ./tcpSocketServe
2. Run clients in other terminals ./tcpSocketClient