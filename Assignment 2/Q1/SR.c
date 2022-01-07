#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/time.h>		
#include <unistd.h>		
#include <signal.h>	

#define INTERVAL 1000

int pid_arg;

int Parent_pid;

void handler(){
    signal(SIGALRM,handler);
    
    char vk;
    int v;
    
    __asm__ volatile(
            "rdrand %0 ; setc %1"
            : "=r" (v), "=qm" (vk)
    );

    union sigval value;
    value.sival_int = v;

    sigqueue (pid_arg, SIGTERM,value);
}

int main(int argc, char *argv[]){

    pid_arg = atoi(argv[0]);

    printf("executing SR...\n");
    
    signal(SIGALRM,handler);

    struct itimerval it_val;	

    it_val.it_value.tv_sec =     INTERVAL/1000;
    it_val.it_value.tv_usec =    (INTERVAL*1000) % 1000000;	
    it_val.it_interval = it_val.it_value;

    setitimer(ITIMER_REAL, &it_val, NULL);

    while (1) 
        pause();
   
    return 0;
    }
