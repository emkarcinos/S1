#include <stdio.h>
#include <stdlib.h>

void swap(int T[], int a, int b){
    int x=T[a], y=T[b];
    T[a]=y;
    T[b]=x;
}

int divide(int T[], int p, int r){
    int x=T[r];
    int i=p-1;
    for(int j=p; j<=r-1; j++){
        if(T[j]<=x){
            i++;
            swap(T, i, j);
        }
    }
    swap(T, i+1, r);
    return i+1;
}

void quicksort(int T[], int p, int r){
    if(p<r){
        int q=divide(T, p, r);
        quicksort(T, p, q-1);
        quicksort(T, q+1, r);
    }
}

int main(){
    int t_length;
    scanf("%d", &t_length);
    int *T=malloc(sizeof(int)*(unsigned)t_length);
    for(int i=0; i<t_length; i++)
        scanf("%d", &T[i]);
    quicksort(T, 0, t_length-1);
    for(int i=0; i<t_length; i++)
        printf("%d\n", T[i]); //output
    return 0;
}