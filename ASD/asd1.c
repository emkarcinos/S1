#include <stdio.h>
#include <stdlib.h>

int main(){
    int d,n1,n2;
    //input start
    scanf("%d", &d);
    for(int j=0; j<d; j++){
        scanf("%d", &n1);
        int A[100000]={};
        for(int i=n1-1; i>=0; i--){
            scanf("%d", &A[i]);
        }
        scanf("%d", &n2);
        int B[100000]={};
        for(int i=n2-1; i>=0; i--){
            scanf("%d", &B[i]);
        }
        //input end
        int p=0, X;
        if(n1>=n2){
            X=n1;
        } else {
            X=n2;
        }
        int C[100001]={};
        for(int i=0; i<X; i++){
                if(A[i]!=0 && A[i]!=1)
                    A[i]=0;
                if(B[i]!=0 && B[i]!=1)
                    B[i]=0;
            C[i]=(A[i]+B[i]+p)%2;
            p=(A[i]+B[i]+p)/2;
        }
        C[X]=p;
        //output start
        int D=0;
        if(C[X]==1){
            D=X;
        } else {
            D=X-1;
        }
        for(int i=D; i>=0; i--){
            printf("%d", C[i]);
        }
        printf("\n");
    }// output end
    return 0;
}