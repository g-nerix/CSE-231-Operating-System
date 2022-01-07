#include<stdio.h>
#include<stdlib.h>

struct Node {
        int data;
        struct Node *next;
    };

struct Node *top;

void push(int v){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = v;
        temp->next = top;
        top = temp;
}
int pop(){
    struct Node *temp = top;

    if (temp == NULL){
        printf("Empty!! ");
        return -1;
    }

    top = top->next;
    temp->next = NULL;
    int x = temp->data;
    free(temp);
    return x;
}

void main(){
    top = NULL;
    push(10);
    push(20);
    push(30);
    printf("%d \n",pop());
    printf("%d \n",pop());
    printf("%d \n",pop());
    printf("%d \n",pop());

}