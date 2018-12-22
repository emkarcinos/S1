#include <stdio.h>
#include <stdlib.h>

int printer(int x){
    printf("B");
    for(int i=0; i<x; i++){
        printf("I");
    }
    printf("G B");
    for(int i=0; i<x; i++){
        printf("O");
    }
    printf("M");
    for(int i=0; i<x; i++){
        printf("!");
    }
    printf("\n");
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int char_count=0;
        scanf("%d",&char_count);
        printer(char_count);
    }
    return 0;
}
