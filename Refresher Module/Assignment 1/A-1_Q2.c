
#include<stdio.h>

#include<string.h>

int longDivision(char *number, int len, char *a, int divisor)
{
    
    int i=0;
	int idx = 0;
	int temp = number[idx] - '0';
    if(idx < (len - 1)){
	while (temp < divisor){
        temp = temp * 10 + (number[++idx] - '0');
    }
    }
    else 
        idx++;
        while (len > idx) {
            
        a[i++]= (temp / divisor) + '0';

        if (idx == len-1){
            break;
        }
		temp = (temp % divisor) * 10 + number[++idx] - '0';
	}
    
    if (i == 0)
        a = "0";

    return temp%divisor;

}

int main()
{   printf("Enter 1st number [MAX 78 digits]: ");

    char number1[100];
    for(int j=0; j<100; j++)
        number1[j] = 0;
    scanf("%s",number1);
    printf("Enter 2nd number [MAX 78 digits]: ");

    char number2[100];
    for(int j=0; j<100; j++)
        number2[j] = 0;

    scanf("%s",number2);

    char add[100];
    for(int j=0; j<100; j++)
        add[j] = 0;
    // add[0] = ((number1[0]-'0'+number2[0]-'0')%10)+'0';
    // for(int k = 1; k<100;k++){
    //     add[k] = ((number1[k]-'0'+number2[k]-'0')%10+(number1[k-1]-'0'+number2[k-1]-'0')%10)+'0';
    // }
    unsigned char save1[32]; 
    char ans1[100];
    unsigned char save2[32]; 
    char ans2[100];

    for(int j=0; j<32; j++)
        save1[j] = 0;
    for(int j=0; j<32; j++)
        save2[j] = 0;

	int divisor = 256;

    int i = 0, j=0;
    
    while(strlen(number1) > 0)
    {
        for(j=0; j<100; j++)
            ans1[j] = 0;
        save1[i++] = longDivision(number1,strlen(number1), ans1, divisor);
        for(j=0; j<100; j++)
            number1[j] = 0;
          strcpy(number1, ans1);
    }

    i=0;
    j=0;
    while(strlen(number2) > 0)
    {
        for(j=0; j<100; j++)
            ans2[j] = 0;
        save2[i++] = longDivision(number2,strlen(number2), ans2, divisor);
        for(j=0; j<100; j++)
            number2[j] = 0;
          strcpy(number2, ans2);
    }
    printf("Number 1 in 32bit char array: \n");
    for(j=31; j>=0; j--)
        printf("%u ", save1[j]);
    printf("\n\n");
    printf("Number 2 in 32bit char array: \n");
    for(j=31; j>=0; j--)
        printf("%u ", save2[j]);
    
    add[0] = (save1[0]+save2[0])%256;
    for(int k = 1; k<32;k++){
        add[k] = (save1[k]+save2[k])%256+(save1[k-1]+save2[k-1])/256;
    }

    printf("\n\n");
    printf("SUM in 32bit char array:\n");
    for(j=31; j>=0; j--)
        printf("%u ", add[j]);
	return 0;
}
