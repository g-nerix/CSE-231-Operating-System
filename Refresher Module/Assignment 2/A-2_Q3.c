#include <stdio.h>
// #include <math.h>
int power(int a, int b){
    int op =1;
    for (int i = b; i >=0; i--){
        op = op*a;
    }
    return op;
}
void main(){

    void add(int a, int b, int *c){
        *c = a+b;
    }
    void sub(int a, int b, int *c){
        *c = a-b;
    }
    void mul(int a, int b, int *c){
        *c = a*b;
    }
    void div(int a, int b, int *c){
        *c = a/b;
    }
    void exp(int a, int b, int *c){
        *c = power(a,b);
    }

    void (*arr[5])(int,int,int*) = {add,sub,mul,div,exp};
    int a = 4, b =2, c = 0;
    printf("Enter Argument 1 :");
    scanf("%d",&a);
    printf("Enter Argument 2 :");
    scanf("%d",&b);
    printf("For a = %d, b = %d :\n",a,b);
    printf("Sum\tSub\tMul\tDiv\tExp\n");
    for (int i = 0; i < 5; i++){
        (* arr[i])(a,b,&c);
        printf("%d\t",c);
    } 
}
