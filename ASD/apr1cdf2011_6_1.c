#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define STACK_SIZE 100

struct stack {
    int A[STACK_SIZE+1];
    int top;
}T;

/*stack functions*/

bool S_EMPT(struct stack T){
    if(T.top==0)
        return true;
    else
        return false;
}

void S_PUSH(struct stack* T, int x, int* errcode){
    if(T->top<STACK_SIZE){
        T->top++;
        T->A[T->top]=x;
    } else {
        *errcode=1;
    }
}

int S_POP(struct stack* T, int* errcode){
    if(S_EMPT(*T))
        *errcode=1;
    else {
        T->top--;
        return T->A[T->top+1];
    }
}

/* stack functions end */

int main(){
    int errcode=0;
    T.top=0;
    while(true){
        int num=0;
        char op[5];
        scanf("%s", op);
        if(strcmp(op, "PUSH")==0){
            scanf("%d", &num);
            S_PUSH(&T, num, &errcode);
        } else if(strcmp(op, "POP")==0) {
            S_POP(&T, &errcode);
        } else
            break;
    }
    if(errcode==1){
        printf("error\n");
        exit(0);
    } else {
        for(int i=T.top; i>0; i--){
            printf("%d\n", T.A[i]);
        }
    }
    return 0;
}