Q1
[Processes]
We have made 2 processes one for section A(child process) and another for Section B(parent process)
we open the file in each parent and child process and iterate over all the file and determine if it is a record of section A or not
if yes then we add the entries in an array and iterate all over the the file till we reach to the end of the file.
we repeat the same process for section b and finally print the the average for each assignment, we also wait for the child process to terminate.

[Threads]
we use a similar approach as in the first part and make 2 function one for sec a and another for sec b and execute the threads. since we have to compute 
the total average we make the sum of array as global and then we reffer it in the main program.

Q2 
here we are calling function a() from the main() function. "Function a()" asks the user to enter a 64 bit int. after which a wrapperfun() prints the character array required and calls 
b1.asm file which alters the calling sequence by poping return address of the callint function and pushing address of function c(). So finally when the function b() executes ret instruction, 
it moves to function c() and finally function c() calls exit() function to end the execution. 