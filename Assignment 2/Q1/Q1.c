#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/time.h>		
#include <unistd.h>		
#include <signal.h>	

void sigterm(int signo, siginfo_t *info, void *extra) {

    struct sigaction action = {0};

        action.sa_flags = SA_SIGINFO; 
        action.sa_sigaction = &sigterm;

    if (sigaction(SIGTERM, &action, NULL) == -1) { 
            perror("sigusr: sigaction");
            exit(1);
        }

    // void *ptr_val = info->si_value.sival_ptr;
    int int_val = info->si_value.sival_int;

    printf("Random value: %u\n",int_val);
}

void sigusr1(int signo, siginfo_t *info, void *extra){
    struct sigaction action = {0};

        action.sa_flags = SA_SIGINFO; 
        action.sa_sigaction = &sigusr1;

    if (sigaction(SIGUSR1, &action, NULL) == -1) { 
            perror("sigusr: sigaction");
            exit(1);
        }

    // void *ptr_val = info->si_value.sival_ptr;
    int int_val = info->si_value.sival_int;

    printf("Time: %u\n",int_val);
}

void main(){
    int id = fork();
    int SR_pid = 0;
    int ST_pid = 0;
    int Parent_pid = getpid();

    
    if (id == 0){                       // S1 process
        
        printf("executing S1...\n");            
        fflush(stdout); 

        struct sigaction action = {0};

        action.sa_flags = SA_SIGINFO; 
        action.sa_sigaction = &sigterm;

        if (sigaction(SIGTERM, &action, NULL) == -1) { 
            perror("sigusr: sigaction");
            exit(1);
        }

        action.sa_flags = SA_SIGINFO; 
        action.sa_sigaction = &sigusr1;

        if (sigaction(SIGUSR1, &action, NULL) == -1) { 
            perror("sigusr: sigaction");
            exit(1);
        }

        while(1){
            sleep(1);
        }
        pause(); 
        
    }
    else {                          // Parent process
        sleep(1);
        int c_id = fork();

        if (c_id == 0){             // ST process
            sleep(2);
            ST_pid = getpid();
            
            char pid[10];
            sprintf(pid,"%d",id);
            char *args[] = {pid,NULL};

            execv("ST.out",args);   // Calling exec to ST...
        
        }
        else {                      // SR process

            sleep(2);
            SR_pid = getpid();

            char pid[10];
            sprintf(pid,"%d",id);
            char *args[] = {pid,NULL};

            execv("SR.out",args);   // Calling exec to SR...
        }
    
        printf("running parent...\n");
        
        printf("%d\n",Parent_pid);
        fflush(stdout);
        while (1){
            sleep(1);
        }
        
    }

}