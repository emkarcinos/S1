#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int post_count;
    scanf("%d", &post_count);
    char T[100][21];
    for(int i=0; i<post_count; i++){
        scanf("%s", T[i]);
    }
    char spammer[10];
    scanf("%s", spammer);
    int count=0;
    for(int i=0; i<post_count; i++){
        if(T[i][0] && strcmp(T[i], spammer)==00)
            count++;
    }
    printf("%d\n", count);
    return 0;
}
