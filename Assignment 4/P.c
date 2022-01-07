#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SYS_writer 448

int main(){
    
   int i;
 
   for (int m = 0; m<20; m++){
       
       int fd = open("/dev/urandom", O_RDONLY);

       else{
           
           unsigned char buf[8];
           long long int random;

           int length = 0;

           while(length < sizeof(buf)){

               ssize_t result = read(fd, buf, 8);
               
               length = length + result;
           }
           
           close(fd);

           for(int i = 0 ; i < 8; i++){
               random = random << 8;
               random = random | buf[i];
           }

           printf("Random number %d: %lld\n",k+1,random);

           syscall(SYS_writer, random);
           
           sleep(1);
       }
    }    
   return 0;
}
