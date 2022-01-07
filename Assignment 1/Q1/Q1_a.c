#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

void main(){
    
    int pid = fork();
    int status = 0;
    
    if (pid == 0){
        
        printf("====================================================\n");
        printf("In child process [Calculating grades for Section A]\n");
        printf("====================================================\n");
        
        int fp = 0;
        char ch = 'a';
        char s[3];
        int newlineCount = 0;
        int commaCount = 0;
        double scoreArray[6] = {0,0,0,0,0,0};
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
        

            printf("Number of lines processed = %d\n",newlineCount);
            printf("Number of Student in section A = %d\n",aCount);
            
            for (int i = 0; i < 6; i++){
                printf("Average score for Assignment %d is %f\n",i+1,scoreArray[i]/aCount);
            }
            
            exit(0);
        }
    }
    else{
        waitpid(pid,&status,0);
        
        printf("\n\n====================================================\n");
        printf("In parent process [Calculating grades for Section B]\n");
        printf("====================================================\n");
        
        printf("EXIT STATUS OF CHILD PROCESS = %X\n",status);
        
        int fp = 0;
        char ch = 'a';
        char s[3];
        int newlineCount = 0;
        int commaCount = 0;
        double scoreArray[6] = {0,0,0,0,0,0};
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

            printf("Number of lines processed = %d\n",newlineCount);
            printf("Number of Student in section B = %d\n",aCount);
            
            for (int i = 0; i < 6; i++){
                printf("Average score for Assignment %d is %f\n",i+1,scoreArray[i]/aCount);
            }         
        }
    }       
}