#include <stdio.h>
#include <stdlib.h>

int main(){
    int d,n,x;
    scanf("%d", &d);
    for(int j=0; j<d; j++){
        scanf("%d", &n);
        int T[n-1];
        for(int i=0; i<n; i++){
            scanf("%d", &T[i]);
        }
        scanf("%d", &x);
        for(int i=0; i<n; i++){
            if(T[i]==x){
                printf("%d\n", i+1);
                break;
            } else if (i+1==n && T[i]!=x) {
                printf("BRAK\n");
            }
        }
    }
    return 0;
}
