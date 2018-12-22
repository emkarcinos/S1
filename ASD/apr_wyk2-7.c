#include <stdio.h>
#include <stdlib.h>

int main(){
    int a=0;
    scanf("%d", &a);
    for(int z=0; z<a; z++){
        int b=0,c=0;
        scanf("%d %d", &b, &c);
        int T[c][b];
        for(int j=0; j<b; j++){
            for(int i=0; i<c; i++){
                scanf("%d", &T[i][j]);
            }
        }
        for(int j=0; j<b; j++){
            for(int i=0; i<c; i++){
                if(T[i][j]%2!=0){
                    printf("%d (%d,%d)\n", T[i][j], i+1, j+1);
                }
            }
        }
    }
    return 0;
}

