#include <stdio.h>
#include <string.h>
int *wordCount(char *filename, int *Num);
int main(int argc,char *argv[]){   //ͨ��main�����������ļ��Ϳ��Ʋ������뱣��
    char *filename = argv[2];
    char *control = argv[1];
    
    
    int Num[2] = { 0, 0};//ʹ�����鴢���ַ��͵�������
    
    if(wordCount(filename, Num)){
        if(strcmp(control,"-c")==0) printf("%d�ַ�",Num[0]); //ifѡ��ṹʵ�ָ��ݲ�ͬ���Ʋ������ز�ͬ��ֵ
        else printf("%dword",Num[1]);
        
    }else{
        printf("Error!\n");
    }
    return 0;
}

int *wordCount(char *filename, int *Num){
    FILE *fp;  
    char buffer[1000];  
    int Len;  
    int i; 
    char c;  
    int wordIdentifier = 0;  
    int charNum = 0;  
    int wordNum = 0; 
    if( (fp=fopen(filename, "rb")) == NULL ){  //�ļ��������������
        perror(filename);
        return NULL;
    }
   
    while(fgets(buffer, 1003, fp) != NULL){ //ʹ��fgets�������л�ȡ�ַ���������
        charNum = strlen(buffer);
        
        for(i=0; i<charNum; i++){ //�������������ַ�
            c = buffer[i];
            if( c==' ' || c=='\t'|| c==','){  //�����ո�Ͷ���ʱ�����ж��Ƿ���ڶ���ո�Ͷ���
                !wordIdentifier && wordNum++;  
                
                wordIdentifier = 1;
            }
            else{
                wordIdentifier = 0;
            }
        }
        
       
        Num[0] += charNum;  // ���ַ���
        Num[1] += wordNum;  // �ܵ�����
       
        charNum = 0;
        wordNum = 0;
    }
    return Num;
}