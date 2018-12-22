#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,z,x; //z is height, x is index number
    scanf("%d", &n);
    int T[n];
    for(int i=0; i<n; ++i){
        scanf("%d", &T[i]);
        if(i==0){
            z=T[i];
            x=i+1;
        } else if (T[i]>z){
            z=T[i];
            x=i+1;
        }
    }
    printf("%d %d", z,x);
    return 0;
}