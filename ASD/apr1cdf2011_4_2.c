#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,s=0;
    scanf("%d", &a);
    for(int i=1; i<a; i++){
        if(a%i==0){
            s=s+i;
        }
    }
    if(s==a){
        printf("tak");
    } else {
        printf("nie");
    }
    return 0;
}