#include <stdio.h>
#include <stdlib.h>

void printer(int T[], int j){
    for(int i=0; i<j; i++)
        printf("%d ", T[i]);
    printf("\n");
}

float counter(int T[], int j){
    int sum=0;
    for(int i=0; i<j; i++){
        if(T[i]>1){
            sum+=T[i];
        }
    }
    return (float)sum/j;
}

int main(){
    int T[1010]={};
    int i=0,x;
    while(1){
        scanf("%d", &x);
        if(x==0){
            printer(T,i);
        } else if(x==-1) {
            return 0;
        } else if(x==1){
            printf("%.2f\n", counter(T,i));
        } else {
            T[i]=x;
            i++;
        }
    }
    return 0;
}
