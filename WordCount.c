#include <stdio.h>
#include <string.h>
int *wordCount(char *filename, int *Num);
int main(int argc,char *argv[]){   //通过main函数参数将文件和控制参数传入保存
    char *filename = argv[2];
    char *control = argv[1];
    
    
    int Num[2] = { 0, 0};//使用数组储存字符和单词数量
    
    if(wordCount(filename, Num)){
        if(strcmp(control,"-c")==0) printf("%d字符",Num[0]); //if选择结构实现根据不同控制参数返回不同的值
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
    if( (fp=fopen(filename, "rb")) == NULL ){  //文件输入输出流操作
        perror(filename);
        return NULL;
    }
   
    while(fgets(buffer, 1003, fp) != NULL){ //使用fgets函数分行获取字符到缓冲区
        charNum = strlen(buffer);
        
        for(i=0; i<charNum; i++){ //遍历缓冲区的字符
            c = buffer[i];
            if( c==' ' || c=='\t'|| c==','){  //遇到空格和逗号时进行判断是否存在多余空格和逗号
                !wordIdentifier && wordNum++;  
                
                wordIdentifier = 1;
            }
            else{
                wordIdentifier = 0;
            }
        }
        
       
        Num[0] += charNum;  // 总字符数
        Num[1] += wordNum;  // 总单词数
       
        charNum = 0;
        wordNum = 0;
    }
    return Num;
}