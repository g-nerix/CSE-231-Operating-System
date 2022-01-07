#include<stdio.h>
void main(){
    printf("Enter size of string:");
    const int size;
    scanf("%d",&size);
    printf("\nEnter the string to reverse :");
    char str[size];
    scanf("%s",str);
    // char str[11] ="hello there";
    int len = sizeof(str)/sizeof(str[0]);
    for (int i = 0; i <= len/2; i++){
        int temp = str[i];
        str[i] = str[len - i -1];
        str[len - i - 1] = temp;
    }
    printf("%s",str);
}