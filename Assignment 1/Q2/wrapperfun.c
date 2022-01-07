#include <stdio.h>
extern void b1();
union data{
        long x;
        char arr[8];
    };

void wrapperfun(long i){
    union data u;
    u.x = i;

    for (int k =0; k < 8; k++){
        printf("%c",u.arr[k]);
    }
    b1();
}
