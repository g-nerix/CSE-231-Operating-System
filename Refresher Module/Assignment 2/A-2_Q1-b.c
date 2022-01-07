#include<stdlib.h>
#include<stdio.h>

void main(){
    
    
    int** arr = (int **)malloc(sizeof(int *)*6);
    int size[6] = {7,4,6,3,7,2};
    for (int i = 0; i < 6; i++){
        arr[i] = (int *)malloc(sizeof(int)*size[i]);
        for (int j = 0; j < size[i]; j++){
            arr[i][j] = rand()%10;
        }
    }

    printf("Original Array :\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < size[i]; j++){
            printf("%u ",arr[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter array # to resize {1,2,3,4,5,6} : ");
    int index = 0;
    scanf("%d",&index);
    printf("\nEnter the new size for array #%d : ",index);
    scanf("%d",&size[index-1]);
    arr[index - 1] = (int *)realloc(arr[index-1],sizeof(int)*size[index -1]);
    for (int j = 0; j < size[index-1]; j++){
            arr[index -1][j] = rand()%10;
    }
        
    printf("\nAltered Array :\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < size[i]; j++){
            printf("%u ",arr[i][j]);
        }
        printf("\n");
    }
}