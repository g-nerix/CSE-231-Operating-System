The file contins three types of programs (as asked in the question) to implement IPC:
	1. using fifo IPC method.
	2. using UNIX Domain Socket IPC method.
	3. using Message passing queue IPC method.

How to compile and run the code:
	1. run the "make" command in terminal [this will compile all the files].
	2. In case of fifo:
        	-> first run the "fifo_p1.o" executable by writing ./fifo_p1.o in the terminal.[sender]
        	-> second run the "fifo_p2.o" executable by writing ./fifo_p2.o in the terminal.[reciever]	
	3. for socket:
        	->  first run the "socket_p2.o" executable by writing ./socket_p2.o in the terminal.[client]
        	->  second run the "socket_p2.o" executable by writing ./socket_p1.o in the terminal.[server]
	4. for Message passing queue:
        	-> first run the  "message_queue_p1.o" executable by writing ./message_queue_p1.o in the terminal.[sender]
        	-> second run the  "message_p2.o" executable by writing ./message_queue_p2.o in the terminal.[reciever]
---------------------------------------------------------------------------------------------------------------------
WARNING:
	RUNNING IN WRONG ORDER CAN RESULT IN ERRORS.
---------------------------------------------------------------------------------------------------------------------