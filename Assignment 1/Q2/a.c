#include <stdio.h>
#include <stdlib.h>
extern void wrapperfun(long);
void a(){
    long x=0;
    printf("In function A\n");
    printf("Enter a 64 bit interger: ");
    scanf("%ld", &x);
    
    wrapperfun(x);
}
