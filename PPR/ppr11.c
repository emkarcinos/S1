#include <stdio.h>
#include <stdlib.h>

int a=1,b=1,c=1,s=0;
int euk(int x, int y){
    int r;
    while(y!=0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main(){
    while(a!=0){
        scanf("%d", &a);
        if(a==1){
            s=s+euk(b,c);
        } else {
        c=b;
        b=a;
        }
    }
    printf("%d", s);
    return 0;
}