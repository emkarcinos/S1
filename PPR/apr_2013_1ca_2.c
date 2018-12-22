/* poorly written */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum (char num1[], char num2[], char num3[]){
    int c=0;
    int num_length=(int)strlen(num2);
    for(int i=0; i<num_length; i++){
        if(num1[i]!=0) {
            num3[i]=((((int)num1[i]-48)+((int)num2[i]-48)+c)%10)+48;
            c=((((int)num1[i]-48)+((int)num2[i]-48)+c)/10);
        } else {
            num3[i]=((((int)num1[i])+((int)num2[i]-48)+c)%10)+48;
            c=((((int)num1[i])+((int)num2[i]-48)+c)/10);
        }
    }
    if (c!=0)
        num3[num_length]=(char)c+48;
    while(num3[strlen(num3)-1]==48){
            num3[strlen(num3)-1]=0;
    }
}

int main(){
    char num1[50]={}, num2[50]={}, num3[51]={};
    scanf("%s", num1);
    scanf("%s", num2);
    sum(num1, num2, num3);
    printf("%s\n", num3);
    return 0;
}
