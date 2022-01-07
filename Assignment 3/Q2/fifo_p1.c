#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 5
#define PERMISSION 0666

int main()
{
    char creator[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str[MAX];
    int fd;

    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, PERMISSION);

    int m = 1;
    printf("Sending Data through FIFO...\n");
    while (m<=50)
    {   
        m++;

        fd = open(myfifo, O_WRONLY);
        
        printf("#%d\tData sent is :\t",m-1);
        
        for (int i = 0; i < 5; i++) {   
            str[i] = creator[rand() % 52];
            printf("%c",str[i]);
        }
        printf("\n");
        
        usleep(100);
        
        write(fd, str, sizeof(str));
        
        close(fd);
// testing...
        fd = open(myfifo, O_RDONLY);
        int data[1];
        
        read(fd, data, sizeof(data));

        if (data[0]<=50&&data[0]%5==0){
            printf("Read id: %d\n",data[0]);
        }
        
        close(fd);
        
    }
    printf("Terminating...\n");
    return 0;
}