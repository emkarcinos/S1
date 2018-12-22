#include <stdio.h>
#include <stdlib.h>

void rit(int x, int* flower, int* leaf, int* step){
    while(x!=1){
        if (x%2==0){
            ++*flower;
            ++*step;
            x/=2;
        } else if (x==1) {
            return;
        } else {
            ++*leaf;
            ++*step;
            x=x*3+1;
        }
    }
}

int main() {
    int x;
    while(1) {
        scanf("%d", &x);
        if (x>0){
            int flower_count=0, leaves_count=0, steps_count=0;
            rit(x, &flower_count, &leaves_count, &steps_count);
            if (steps_count<=15){
                printf("TAK %d %d\n", flower_count, leaves_count);
            } else {
                printf("NIE\n");
            }
        } else {
            return 0;
        }
    }
    return 0;
}
