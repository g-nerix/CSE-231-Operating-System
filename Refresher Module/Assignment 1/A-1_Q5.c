#include<stdio.h>

// int arr[10]={1,4,8,9,20,22,24,30,33,35};
int b_search(int v, int l, int r,int arr[]){
    int mid = l + (r-l)/2;
    if (arr[mid]==v){
        return mid;
    }
    if (r>=l){
        if (arr[mid]>v){
            b_search(v,l,mid-1,arr);
        }
        else{
            b_search(v,mid+1,r,arr);
        }
    }
    else{
        return -1;
    }   
}
void main(){
    printf("Enter length of arrar :");
    const int size;
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter element #%d of the array :",i+1);
        int ele;
        scanf("%d",&ele);
        arr[i] = ele;
    }
    printf("\nEnter the element to search :");
    int t;
    scanf("%d",&t);
    printf("OUTPUT :%d",b_search(t,0,(int)(sizeof(arr)/4),arr));
}
