#include <stdio.h>
#include <stdlib.h>

struct astronaut {
    char name[200];
    int height, mass, age;
};

int comparator(const void* num1, const void* num2){
    struct astronaut a=*(struct astronaut*)num1;
    struct astronaut b=*(struct astronaut*)num2;
    float score_a=((float)a.mass*(float)a.height)/(float)a.age;
    float score_b=((float)b.mass*(float)b.height)/(float)b.age;
    if (score_a<score_b)
        return -1;
    else if (score_a==score_b)
        return 0;
    else
        return 1;
}

int main(){
    int a_count;
    scanf("%d", &a_count);
    struct astronaut *T=malloc(sizeof(struct astronaut)*a_count);
    for(int i=0; i<a_count; i++){
        scanf("%s", T[i].name);
        scanf("%d", &T[i].height);
        scanf("%d", &T[i].mass);
        scanf("%d", &T[i].age);

    }
    qsort(T, a_count, sizeof(struct astronaut), comparator);
    for(int i=0; i<a_count; i++){
        printf("%s\n", T[i].name);
    }
    free(T);
    return 0;
}
