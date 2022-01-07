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
        unsigned max;
        unsigned min; 

        __asm__ volatile("rdtsc" : "=a" (min), "=d" (max)); 
        
        unsigned long long clock = (((unsigned long long)min)|((unsigned long long)max)<<32);
        unsigned long long t = clock/1800000000;

        union sigval v;
        v.sival_int=t;
        
        sigqueue (pid_arg, SIGUSR1,v);
}

int main(int argc, char *argv[]){

    pid_arg = atoi(argv[0]);

    printf("executing ST...\n");

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