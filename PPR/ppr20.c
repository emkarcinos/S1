#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counter(char T[], int *word, int *num, int *letter){
    *word=(int)strlen(T);
    int length=strlen(T);
    for (int i=0; i<length; i++){
        if(((int)T[i]>=65 && (int)T[i]<=90) || ((int)T[i]>=97 && (int)T[i]<=122))
            ++*letter;
        else if((int)T[i]>=48 && (int)T[i]<=57)
            ++*num;
       }
}

int main(){
    int lines;
    scanf("%d\n", &lines);
    for (int i=0; i<lines; i++){
        char str[31]={};
        scanf("%[^\n]%*c",str);
        int word_count=0, nums_count=0, char_count=0;
        counter(str, &word_count, &nums_count, &char_count);
        printf("%d %d %d\n", word_count, char_count, nums_count);
    }
    return 0;
}