#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>		
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 5

struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
    int id;
    char c;
} message;

void main() {
    char Array[50][14];

    char creator[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n=strlen(creator);

    char the_string[MAX];

    key_t key;
    int msgid;

    key = ftok("/Assignment_3", 'a');

    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    for (int j = 1; j <= 50; j++) {
    
        for (int i = 0; i < MAX; i++) {
            
            int k = rand() % 52;
            the_string[i] = creator[k];
            message.mesg_text[i] = the_string[i];
            

        }

        message.id = j;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("#%d Data sent is : %s \n",j, message.mesg_text);
        if (j%5 == 0){
            sleep(1);
            msgrcv(msgid, &message, sizeof(message), 1, 0);
            printf("ID Received is : %d\n", message.id);
        }
        

    }
}