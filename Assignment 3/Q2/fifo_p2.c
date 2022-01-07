#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);

    char buff[5];
    int m = 0;
    printf("Recieveing Data through FIFO...\n");
    while (m<50)
    {
        m++;
 
        fd1 = open(myfifo,O_RDONLY);

        read(fd1, buff, 5);
        
        printf("#%d\tData recieved from FIFO :\t%s\n",m, buff);
        
        close(fd1);

       
        int id[1];
        id[0] = m;
        fd1 = open(myfifo,O_WRONLY);
    
        write(fd1, id, sizeof(id));
        if (m%5==0){
            printf("Sent id: %d\n",id[0]);

        }
        close(fd1);
    }
    printf("Terminating...\n");
    return 0;
}