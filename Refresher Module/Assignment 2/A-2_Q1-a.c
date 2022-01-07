#include<stdlib.h>
#include<stdio.h>

void main(){
    
    
    int** arr = (int **)malloc(sizeof(int *)*6);
    int size[6] = {7,4,6,3,7,2};
    printf("Required Array [as in question] :");
    for (int i = 0; i < 6; i++){
        arr[i] = (int *)malloc(sizeof(int)*size[i]);
        for (int j = 0; j < size[i]; j++){
            arr[i][j] = rand()%10;
        }
    }

    printf("\n\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < size[i]; j++){
            printf("%u ",arr[i][j]);
        }
        printf("\n");
    }
}