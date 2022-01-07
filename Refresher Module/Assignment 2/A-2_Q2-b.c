#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// name, rollno. , year of joining and enrolled academic program

struct Node {
        char name[20];
        int roll;
        int year;
        char program[20];
        struct Node *next;
        struct Node *prev;
    };

struct Node *head;

void insert(char name[20],int sn, int roll, int year, char program[20], int sp){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        memcpy(temp->name ,name ,sn);
        temp->roll = roll;
        temp->year = year;
        memcpy(temp->program ,program ,sp);
        temp->next = NULL;

    if(head == NULL){
        head = temp;
        head->prev = NULL;
    }
    else{
        struct Node *t = head;
        while(t->next!=NULL){
            t = t->next;
        } 
        t->next = temp; 
        temp->prev = t;      
    }
}

void print(){
    if(head == NULL){
        printf("EMPTY!!\n");
        return;
    }
    
    struct Node *temp = head;
    while (temp!=NULL){
        printf("==========================\n");
        printf("Name = %s\nRoll No = %d\nYear of Joining = %d\nProgram = %s\n",temp->name,temp->roll,temp->year,temp->program);
        temp = temp->next;
    }
}

void search(int roll){
    struct Node *temp = head;
    while (temp!=NULL){
        if(temp->roll == roll){
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Record NOT FOUND !!\n");
    }
    else{
        printf("++++++++++++++++++++++++++\n");
        printf("Record Found :\n");
        printf("Name = %s\nRoll No = %d\nYear of Joining = %d\nProgram = %s\n",temp->name,temp->roll,temp->year,temp->program);
        printf("++++++++++++++++++++++++++\n");
    }
}

void main(){
    head = NULL;
    
    insert("abc",sizeof("abc"),10,2020,"def", sizeof("def"));
    insert("abc",sizeof("abc"),11,2020,"def", sizeof("def"));
    search(11);
    print();

}