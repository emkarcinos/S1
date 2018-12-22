#include <stdio.h>
#include <stdlib.h>

int sort(int n, int T[], int j,int k){
    if (j>k)
        return 0;
    int z=(j+k)/2;
    if(T[z]==n)
        return z+1;
    if(T[z]<n)
        return sort(n, T, z+1, k);
    else
        return sort(n, T, j, z-1);
}

int main(){
    int std_count;
    scanf("%d", &std_count);
    int *T=malloc(sizeof(int)*(unsigned)std_count);
    for(int i=0; i<std_count; i++){
        scanf("%d", &T[i]);
    }
    int ask_count;
    scanf("%d", &ask_count);
    for(int i=0; i<ask_count; i++){
        int num;
        scanf("%d", &num);
        int result=sort(num, T, 0, std_count-1);
        if(result==0)
            printf("NIEOBECNY\n");
        else
            printf("%d\n", result);
    }
    return 0;
}
