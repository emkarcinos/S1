#include <stdio.h>
#include <stdlib.h>

int main(){
    int d;
    scanf("%d", &d);
    int T[d-1];
    for(int i=0; i<d; i++){
        scanf("%d", &T[i]);
    }
    for(int i=0; i<d; i++){
        for(int j=2; j<=T[i]; j++){
            if(T[i]==j){
                printf("PIERWSZA\n");
                break;
            } else if (T[i]%j==0){
                printf("ZLOZONA\n");
                break;
            }
        }
    }
    return 0;
}
