#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SERVER_PATH "tpf_unix_sock.server"
#define CLIENT_PATH "tpf_unix_sock.client"

int main(void){

    int client_sock, rc, len;
    struct sockaddr_un server_sockaddr; 
    struct sockaddr_un client_sockaddr; 

    memset(&server_sockaddr, 0, sizeof(struct sockaddr_un));
    memset(&client_sockaddr, 0, sizeof(struct sockaddr_un));
     
    client_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_sock == -1) {
        printf("SOCKET ERROR = \n");
        exit(1);
    }

    client_sockaddr.sun_family = AF_UNIX;   
    strcpy(client_sockaddr.sun_path, CLIENT_PATH); 
    len = sizeof(client_sockaddr);
    
    unlink(CLIENT_PATH);
    rc = bind(client_sock, (struct sockaddr *) &client_sockaddr, len);
    if (rc == -1){
        printf("BIND ERROR: \n");
        close(client_sock);
        exit(1);
    }
    
    server_sockaddr.sun_family = AF_UNIX;
    strcpy(server_sockaddr.sun_path, SERVER_PATH);
    rc = connect(client_sock, (struct sockaddr *) &server_sockaddr, len);
    if(rc == -1){
        printf("CONNECT ERROR = \n" );
        close(client_sock);
        exit(1);
    }

	char str[50][6] = {{0}};                                      
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 50; j++){
            str[j][i] = rand() % 26 + 65; 
			
        }	
    }
	for (int i =1; i< 50;i++){
		printf("Data sent :%s\n",str[i]);
		send(client_sock, str[i-1], sizeof(str[i-1]), 0);
		usleep(100000);
		if (i%5==0&& i>0){
			printf("Index recieved :%d\n",i);
		}
	}
	
    close(client_sock);
    
    return 0;
}