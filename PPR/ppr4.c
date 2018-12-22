#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,x;
    scanf("%d %d/n",&a,&b);
    scanf("%d",&x);
    unsigned int c;
    if(x>=a&&x<=b)
        printf("BINGO");
    else if (x<a){
        c=a-x;
        printf("%d",c);
    } else {
        c=x-b;
        printf("%d",c);
    }
    return 0;
}

