#include <stdio.h>
#include <stdlib.h>

int noty(int cand, int T[], int length){
    int count=0;
    for (int i=0; i<length; i++){
        if(cand%T[i]==0)
            count++;
    }
    return count;
}

int main(){
    int list_length, candidate_count;
    scanf("%d", &list_length);
    int *T=malloc(sizeof(int)*list_length);
    for (int i=0; i<list_length; i++)
        scanf("%d", &T[i]);
    scanf("%d", &candidate_count);
    for (int i=0; i<candidate_count; i++){
        int cand;
        scanf("%d", &cand);
        printf("%d\n", noty(cand, T, list_length));
    }
    return 0;
}