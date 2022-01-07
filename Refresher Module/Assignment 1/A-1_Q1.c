#include<stdio.h>
#include <string.h>
void main(){
    FILE* f_s;
    FILE* f_d;
    
    char buffer;
    char str_s[100];
    char str_d[100];

    printf("ENTER ADDRESS OF THE SOURCE FILE :");
    scanf("%s",str_s);
    
    
    f_s = fopen(str_s, "rb");
    
    if(f_s == NULL)
    {
        printf("\n ERROR: File NOT Found !!\n");
        return;
    }

    printf("ENTER ADDRESS OF THE DESTINATION FILE :");
    scanf("%s",str_d);
    
    f_d = fopen(str_d, "wb");
    
    if(f_d == NULL)
    {
        printf("\n ERROR: Unable to copy to the Directory !!\n");
        return;
    }
    
    while(fread(&buffer, sizeof(buffer), 1, f_s)==1)
    {
        fwrite(&buffer,sizeof(buffer), 1, f_d);
    }
}
