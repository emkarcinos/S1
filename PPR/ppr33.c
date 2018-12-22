#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct man {
    char fname[50], lname[50];
    int age;
    float height;
};

int main(){
    int h_count;
    scanf("%d", &h_count);
    struct man list[1000];
    for (int i=0; i<h_count; i++){
        scanf("%s", list[i].fname);
        scanf("%s", list[i].lname);
        scanf("%d", &list[i].age);
        scanf("%f", &list[i].height);
    }
    int age_thresh;
    float height_thresh;
    scanf("%d", &age_thresh);
    scanf("%f", &height_thresh);
    for (int i=0; i<h_count; i++){
        if(list[i].age>age_thresh)
            printf("%s %s\n", list[i].fname, list[i].lname);
    }
    printf("----\n");
    for (int i=0; i<h_count; i++){
        if(list[i].height<height_thresh)
            printf("%s %s\n", list[i].fname, list[i].lname);
    }
    return 0;
}
