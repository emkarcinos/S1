#include <stdio.h>
#include <stdlib.h>
int OD(int x){
    if(x>0){
        printf("%d",x%10);
        OD(x/10);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    OD(a);
    return 0;
}

