#include <stdio.h>
#include <stdlib.h>
void swap(int T[],int j){
   int a=T[j], b=T[j+1];
   T[j]=b;
   T[j+1]=a;
}

void sort(int T[], int N){
    int i=N-1;
    while(i!=0){
        int k=0;
        for (int j=0; j<i; j++){
            if(T[j]>T[j+1]){
                swap(T, j);
                k=j;
            }
        }
        i=k;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int *T=malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d", &T[i]);
    }
    sort(T, N);
    for(int i=N-1; i>=0; i--){
        printf("%d ", T[i]);
    }
return 0;
}