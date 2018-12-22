#include <stdio.h>
#include <stdlib.h>

int rec(int n){
    if (n==0 || n==1 || n==2)
        return 1;
    return 2*rec(n-3)+rec(n-1);
}

int main(){
    int t,n;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        printf("%d\n", rec(n));
    }
    return 0;
}
