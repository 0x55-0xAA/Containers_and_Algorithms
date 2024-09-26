#include "bottom_up_merge_sort.c"
#include <stdio.h>

int cmp(const void *a,const void *b) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;

    if (arg1 > arg2) {
        return -1;
    }else if (arg1 < arg2) {
        return 1;
    }else {
        return 0;
    }
}

int char_cmp(const void *a,const void *b) {
    const char arg1 = *(const char*)a;
    const char arg2 = *(const char*)b;

    if (arg1 > arg2) {
        return -1;
    }else if (arg1 < arg2) {
        return 1;
    }else {
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,3,5,4,2};
    msort(arr,5,4,cmp);
    for (int i = 0;i < 5;i++) {
        printf("%d ",*(arr + i));
    }
    printf("\n");
    char arr1[] = {'a','b','c','d','e'};
    msort(arr1,5,1,char_cmp);
    for (int i = 0;i < 5;i++) {
        printf("%c ",*(arr1 + i));
    }
    return 0;
}