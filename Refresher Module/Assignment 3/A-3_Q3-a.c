#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node *lc;
    struct Node *rc; 
};
void insert(struct Node **n,int v){
    
    if ((*n) == NULL){
        (*n) = (struct Node *)malloc(sizeof(struct Node));
        (*n)->key = v;
        (*n)->lc = NULL;
        (*n)->rc = NULL;
        return;
    }
    if((*n)->key > v){
        insert(&((*n)->lc),v);
    }
    else if((*n)->key < v){
        insert(&((*n)->rc),v);
    }
    else{
        printf("\nDuplicate Value %d !! ",v);
        return;
    }
}
// int successor(struct Node *n){
//     if (n->lc==NULL){
//         return n->key;
//     }
//     while (n->lc!=NULL)
//     {
//         n = n->lc;
//     }
//     return n->key;
// }
int successor(struct Node *n){
            if (n->lc->rc==NULL){
                return n->rc->key;
            }
            n = n->rc;
            while (n->lc!=NULL){
                n = n->lc;
            }
            return n->key;
        }

struct Node* delete(struct Node **n,int v){
    if ((*n) == NULL){
        return (*n);
    }
    if ((*n)->key > v){
        (*n)->lc = delete(&((*n)->lc),v);
    }
    else if ((*n)->key < v){
        (*n)->rc = delete(&((*n)->rc),v);
    }
   else{
        if ((*n)->lc == NULL){
            return (*n)->rc;
        }
        else if ((*n)->rc == NULL){
            return (*n)->lc;
        }
        printf(" x111 ");
        (*n)->key = successor((*n));
        printf("%d",(*n)->key);
        (*n)->rc = delete(&((*n)->rc),(*n)->key);
   }
//  printf(" ??? %d &&&&", *n);
    return (*n);
}
void print(struct Node *n){
    // printf("Hello");
    if(n!=NULL){
        print(n->lc);
        printf("%d->",n->key);
        print(n->rc);
    }
}
void main(){
    struct Node *root = NULL;
// printf("%d ->",root);
    
    insert(&root,50);
    insert(&root,20);
    insert(&root,80);
    insert(&root,10);
    insert(&root,30);
    insert(&root,5);
    insert(&root,15);
    insert(&root,25);
    insert(&root,40);
    insert(&root,60);
    insert(&root,90);
    insert(&root,100);
    print(root);
//  printf("   %d>>>   ", root);
    root = delete(&root,80);
    printf("\n");
    print(root);
    // printf("   %d****   ", root);
}