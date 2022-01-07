#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SYS_reader 449
#define SYS_init 450


int main(){

  syscall(SYS_init,20);
  
  for(int i=0; i < 20; i++){
    
    long long int random = syscall(SYS_reader);
    
    printf("Got %d: %lld\n",k+1, random);
    
    usleep(1000);
    
    k++;
  }
  return 0;  
}
