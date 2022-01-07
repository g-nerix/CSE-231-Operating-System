#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node *next; 
};
struct Node *front, *rear;
void enqueue(int v){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;

    if (front == NULL){
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue(){
    if (front == NULL){
        printf("EMPTY!!");
        return -1;
    }
    
    struct Node *temp = front;

    int x = temp->data;
    front = temp->next;

    if (front == NULL){
        rear = NULL;
    }
    
    free(temp);

    return x;
}

void main(){
    front = NULL;
    rear = NULL;

    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
}