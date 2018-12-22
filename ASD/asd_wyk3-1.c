#include <stdio.h>
#include <stdlib.h>
static int inv=0;

void merge(int T[], int p, int q, int r){
    int n=q-p+1, m=r-q;
    int *T1=malloc(sizeof(int)*((unsigned)n+1)), *T2=malloc(sizeof(int)*((unsigned)m+1));
    for(int i=0; i<n; i++)
        T1[i]=T[p+i];
    for(int i=0; i<m; i++)
        T2[i]=T[q+i+1];
    int i=0, j=0;
    T1[n]=1001;
    T2[m]=1001;
    for(int k=p; k<=r; k++){
        if(T1[i]<=T2[j]){
            T[k]=T1[i];
            i++;
        } else {
            T[k]=T2[j];
            j++;
            inv+=(n-i);
        }
    }
    free(T1); free(T2);
}

void ss(int T[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        ss(T, p, q);
        ss(T, q+1, r);
        merge(T, p, q, r);
    }
}

int main(){
    int arr_count;
    scanf("%d", &arr_count);
    for(int i=0; i<arr_count; i++){
        int t_length;
        scanf("%d", &t_length);
        int *T=malloc(sizeof(int)*(unsigned)t_length);
        for(int j=0; j<t_length; j++)
            scanf("%d", &T[j]);
        ss(T, 0, t_length-1);
        printf("%d\n", inv);
        free(T);
        inv=0;
    }
    return 0;
}