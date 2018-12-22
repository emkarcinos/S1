#include <stdio.h>
#include <stdlib.h>

int powa(int n, int k){
    if(n<k)
        return 1;
    else {
        return n*powa(n-k,k);
    }
}

int main (){
    int test_count;
    scanf("%d", &test_count);
    for(int i=0; i<test_count; i++){
        int n,k;
        scanf("%d %d", &n, &k);
        if(n<k)
            printf("1");
        else {
            printf("%d\n", powa(n,k));
        }

    }
    return 0;
}