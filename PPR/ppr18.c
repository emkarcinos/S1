#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip(char T[]) {
    int j=strlen(T);
    char *Ta=malloc(sizeof(char)*(j+1));
    for (int i=0; i<(int)strlen(T); i++){
        Ta[j-1]=T[i];
        j--;
    }
    return Ta;
}

int main() {
    int a;
    scanf("%d", &a);
    for (int i=0; i<a; i++){
        char word[31]={};
        scanf("%s", word);
        char* flipped=flip(word);
        if (strcmp(word, flipped)==0)
            printf("%s==%s\n", word, word);
        else {
            printf("%s!=%s\n", word, flipped);
        }
        free(flipped);
    }
    return 0;
}
