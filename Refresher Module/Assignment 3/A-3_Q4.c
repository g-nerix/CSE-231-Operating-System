#include<stdio.h>

void print(int arr[],int len){
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int len){
    int min = arr[0];
    int index = 0;
    int temp = 0;
    
    for (int i = 0; i < len-1; i++){
        
        min = arr[i];
        index  = i;

        for (int j = i+1; j < len; j++){
            if(arr[j] <= min){
                min = arr[j];
                index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

void bubbleSort(int arr[], int len){
    int min = arr[0];
    int temp = 0;

    for(int i = 0; i < len; i++){
        for (int j = 0; j < len-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void main(){
    int size = 0;

    printf("Enter size of array [MAX = 100]: ");
    scanf("%d",&size);
    
    int len = size;
    static int arr[100];
    int k = 0;

    for(int i = 0; i < size; i++){
        printf("Enter element #%d :",i+1);
        scanf("%d",&k);
        arr[i] = k;
    }

    int method = 0;
    
    printf("Enter the method to sort [1 or 2] \n1.Bubble Sort \n2.Insertion Sort \n-> ");
    scanf("%d",&method);
    
    if (method == 1){
        bubbleSort(arr,len);
    }
    else if (method == 2){
        selection_sort(arr,len);
    }
    else{
        printf("INVALID SELECTION");
        return;
    }
    printf("Sorted Array: ");
    print(arr,len);
}