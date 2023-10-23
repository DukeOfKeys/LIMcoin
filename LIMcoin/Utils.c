#include "Utils.h"
void itoc(int num, char* in){
    char str[(int)((ceil(log10((num != 0) ? num : 1))+1)*sizeof(char))];
    sprintf(str, "%d", num);
    strcpy(in, str);
}
void compare(char a[],char b[])  
{  
    int i=0;
    while(a[i]!='\0' &&b[i]!='\0')  
    {  
       if(a[i]!=b[i])  
       {  
           printf("symbols: a: %c b:%c\n", a[i],b[i]);
       }  
       i++;  
    }    
} 
void ltoc(long num, char* in){
    char str[(long)((ceil(log10((num != 0) ? num : 1))+1)*sizeof(char))];
    sprintf(str, "%ld", num);
    strcpy(in, str);
}
int compareZeros(char* str, int num){
    int numberZ = 0;
    for(int counter = 0; counter<num&&counter<strlen(str); counter++){
        if(str[counter] == '0'){
            numberZ ++;
            if(numberZ >= num){
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    return 0;
}
