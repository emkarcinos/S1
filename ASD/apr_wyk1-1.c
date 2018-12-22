#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,n;
    scanf("%d %d", &a, &n);
    int x=1;
    for(int i=0; i<n; i++){
        x=x*a;
    }
    printf("%d", x);
    return 0;
}
