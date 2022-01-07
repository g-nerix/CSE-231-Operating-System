#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

double scoreArray[6] = {0,0,0,0,0,0};
int secACount = 0;
int secBCount = 0;
double scoreArrayB[6] = {0,0,0,0,0,0};

void* sectionA(){
    {
        
        int fp = 0;
        char ch = 'a';
        char s[3];
        int newlineCount = 0;
        int commaCount = 0;
        int isA = -1;
        int aCount = 0;
        int temp = 0;
        
        
        fp = open("student_record.csv",O_RDONLY);
        
        if (fp < 1){
            printf("Error in opening the file\n");
        }
        else{
            
            while(read(fp,&ch,1)){
                
                if (newlineCount > 0){
    
                    while ((ch!='\n') && (ch != '\r')){
                    
                        if (commaCount == 1 && ch == 'A'){
                            isA = 1;
                            aCount++;
                        }

                        if (ch == ','){
                            if (commaCount > 1){
                                
                                scoreArray[commaCount-2] += temp;
                                temp = 0;
                            }     
                            commaCount++;
                        }

                        if (isA == 1 && commaCount > 1 && ch != ','){
                            temp = 10*temp + ch - '0';
                            
                        }
                        ch = '\n';
                        read(fp,&ch,1);

                    }
                    
                    scoreArray[commaCount-2] += temp;
                    temp = 0;
                    isA = -1;
                    commaCount = 0;
                }
                if (ch =='\n'){
                    newlineCount++;
                }
            }  
            secACount = aCount;
        }
        close(fp);
    }
}

void* sectionB(){
        
        int fp = 0;
        char ch = 'a';
        char s[3];
        int newlineCount = 0;
        int commaCount = 0;
        int isA = -1;
        int aCount = 0;
        int temp = 0;
        
        
        fp = open("student_record.csv",O_RDONLY);
        
        if (fp < 1){
            printf("Error in opening the file\n");
        }
        else{
            
            while(read(fp,&ch,1)){
                
                if (newlineCount > 0){
    
                    while ((ch!='\n') && (ch != '\r')){
                    
                        if (commaCount == 1 && ch == 'B'){
                            isA = 1;
                            aCount++;
                        }

                        if (ch == ','){
                            if (commaCount > 1){
                                
                                scoreArrayB[commaCount-2] += temp;
                                temp = 0;
                            }
                            
                            commaCount++;
                        }

                        if (isA == 1 && commaCount > 1 && ch != ','){
                            temp = 10*temp + ch - '0';
                            
                        }
                        ch = '\n';
                        read(fp,&ch,1);
            
                    }
                   
                    scoreArrayB[commaCount-2] += temp;
                    temp = 0;
                    isA = -1;
                    commaCount = 0;
                }
                if (ch =='\n'){
                    newlineCount++;
                }

            }
            secBCount = aCount;        
        }
        close(fp);
    } 

int main(){
    pthread_t t1, t2;
    
    if (pthread_create(&t1, NULL, sectionA, NULL)!= 0){
        printf("Error in creating Thread for Section-A\n");
        exit(1);
    }
    
    if (pthread_create(&t2, NULL, sectionB, NULL) != 0){
        printf("Error in creating Thread for Section-B\n");
        exit(1);
    }
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("====================================================\n");
    printf("[Calculating grades for Section A]\n");
    printf("====================================================\n");

    for (int i = 0; i < 6; i++){
        printf("[SECTION A]Average score for Assignment %d is %f\n",i+1,scoreArray[i]/secACount);
    }
    
    printf("\n\n====================================================\n");
    printf("[Calculating grades for Section B]\n");
    printf("====================================================\n");
    
    for (int i = 0; i < 6; i++){
        printf("[SECTION B]Average score for Assignment %d is %f\n",i+1,scoreArrayB[i]/secBCount);
    }

    printf("\nCOMBINED RESULT OF SECTION A AND SECTION B\n");

    for (int i = 0; i < 6; i++){
        printf("Average score for Assignment %d is %f\n",i+1,(scoreArrayB[i]+scoreArray[i])/(secACount+secBCount));
    }
    
    return 0;
}