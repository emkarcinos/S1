#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int d=(2*a*b)+(2*b*c)+(2*a*c);
    printf("%d",d);
    return 0;
}
