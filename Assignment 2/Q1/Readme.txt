LOGIC BEHIND THE CODE:
    The program has 3 c files Q1.c,SR.c,ST.c.

    Q1.c calls two programs SR and ST using execv system call.
    the code forks child process with S1 which registers a signal handler for the 
    signal "SIGTERM".
    
    main() forks two more child process SR and ST.

    The SR process replaces using execv system call.
    SR.c uses "setitimer()" to send "SIGALRM" signal at set intervals.
    the "SIGALRM" signals are handled by a handler which generates random number.
    after generating the random number, the handler uses "sigqueue" system call to send
    the random number and "SIGTERM" signal back to S1.

    similarly in the ST process: 
    the SIGALRM handler in ST passes the time[in ns]=(clock_ticks/CPU_frequency) and sends
    "SIGTERM" signal to S1 .

HOW TO RUN:
    1. Run the Makefile using "make" command .
    2. Run "make run" to execute the file.


    

