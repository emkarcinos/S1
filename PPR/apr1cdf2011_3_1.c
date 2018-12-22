#include <stdio.h>
#include <stdlib.h>

int SL(int x){
    if(x==0){
       x=1;
       return x;
    } else {
      x=x*SL(x-1);
      return x;
    }
}

int main(){
    int a;
    scanf("%d", &a);
    printf("%d", SL(a));
    return 0;
}