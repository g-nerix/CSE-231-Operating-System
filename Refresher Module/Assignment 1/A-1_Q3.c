#include<stdio.h>
// void swap_variable(int *x, int *y){
//     *x = *x + *y;
//     *y = *x - *y;
//     *x = *x - *y; 
// }
void swap(int arr1[], int arr2[], int len){
    
    int temp = 0;
    for (int i = 0; i < len; i++){
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }

}
void print(int arr[],int len){
    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void main(){
    printf("Enter the operation to perform :\n1.Swap variable\n2.Swap Array\n");
    int in;
    scanf("%d",&in);
    if (in == 1){
        int a = 0, b = 0;
        printf("\nEnter value of first variable (a) : ");
        scanf("%d",&a);
        printf("\nEnter value of second variable (b): ");
        scanf("%d",&b);
        printf("\nInitially:\ta:%d\tb:%d\n",a,b);
        int len = sizeof(a)/sizeof(int);
        swap(&a,&b,len);
        printf("Finally:\ta:%d\tb:%d\n\n",a,b);
        return;
    }
    else if (in == 2){
        const int a_len;
        printf("\nEnter length of array : ");
        scanf("%d",&a_len);
        int arr1[a_len];
        for (int i = 0; i < a_len; i++){
            printf("\nEnter element #%d of first array (arr1) : ",i+1);
            int temp = 0;
            scanf("%d",&temp);
            arr1[i] = temp;
        }

        int arr2[a_len];
        for (int i = 0; i < a_len; i++){
            printf("\nEnter element #%d of second array (arr2) : ",i+1);
            int temp = 0;
            scanf("%d",&temp);
            arr2[i] = temp;
        }
        int len = sizeof(arr1)/sizeof(int);

        printf("Initially: \narr1: ");
        print(arr1,len);
        printf("arr2: ");
        print(arr2,len);

        swap(arr1,arr2,len);
        
        printf("Finally: \narr1: ");
        print(arr1,len);
        printf("arr2: ");
        print(arr2,len);

    }   
    else{
        printf("\nINVALID SELECTION !!");
    }
}
