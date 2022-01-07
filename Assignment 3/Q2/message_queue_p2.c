#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 5
  
struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
    int id;
    char c;
} message;
  
int main()
{
    key_t key;
    int msgid;

    key = ftok("/Assignment_3", 'a');

    msgid = msgget(key, 0666 | IPC_CREAT);
    
    for(int i = 1; i <= 50; i++){
 
        msgrcv(msgid, &message, sizeof(message), 1, 0);

        printf("#%d Data Received is : %s \tID:%d\t%c\n",message.id, message.mesg_text,i,message.mesg_text[4]);
        if (i%5==0){
            sleep(2);
            msgsnd(msgid, &message, sizeof(message), 0);
            printf("Sent : %d\n",message.id);
        }
        
    } 
    
    msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}