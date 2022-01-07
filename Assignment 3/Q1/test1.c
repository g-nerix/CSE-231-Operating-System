#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define SYS_print_vruntime 448
extern int errno;
void work(){
    // printf("...Starting Time = %u\n",start);
    int i, Number, count, Minimum, Maximum; 

    Minimum = 1;
    Maximum = 400000;

  for(Number = Minimum; Number <= Maximum; Number++)
  {
    count = 0;
    for (i = 2; i <= Number/2; i++)
    {
      if(Number%i == 0)
      {
  	count++;
  	break;
      }
    }
    if(count == 0 && Number != 1 )
    {

    }  
  }
}
int main() {
    printf("In the process without vruntime syscall\n");
    printf("...Starting Time = %u\n",start);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    work();
    end = clock();
    printf("...Ending Time = %u\n",end);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("took %f seconds to execute \n", cpu_time_used);
    
    printf("In the process with vruntime syscall\n");
    int res = syscall(SYS_print_vruntime, getpid(), 100);
    if(res != 0){
	    printf("ERROR");
    }     
    printf("...Starting Time = %u\n",start);
    start = clock();
    work();
    end = clock();
    printf("...Ending Time = %u\n",end);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("took %f seconds to execute \n", cpu_time_used);
  
    
  return 0;
      
}
