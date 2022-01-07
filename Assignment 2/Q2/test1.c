#define _GNU_SOURCE

#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

#define SYS_kernel_2d_memcpy 449


int main(int argc, char **argv)
{

	float matrix1[2][3];
    float matrix2[2][3];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            matrix1[i][j] = 1;
        }
    }

	printf("calling kernel_2d_memcpy system call...\n");
	long res = syscall(SYS_kernel_2d_memcpy, matrix1, matrix2);
	printf("system call returned : %ld.\n",res);

    printf("matrix2...\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("%f\t",matrix2[i][j]);
            
        }
        printf("\n");
    }

	return 0;
}