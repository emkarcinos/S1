#include <stdio.h>
#include <stdlib.h>

int counter(int T[],int a,int b){
    int count=0;
    for(int i=a-1; i<b; i++){
        count+=T[i];
    }
return count;
}

int main(){
    int box_count, ask_count;
    scanf("%d", &box_count);
    int T[box_count];        //ilosc skarbow w boxie
    for(int i=0; i<box_count; i++){
        scanf("%d ", &T[i]);
    }
    scanf("%d", &ask_count);
    for(int i=0; i<ask_count; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        printf("%d\n", counter(T,a,b));
    }
    return 0;
}
