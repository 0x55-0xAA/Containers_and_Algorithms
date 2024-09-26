#include "quick_sort.c"
#include <stdio.h>

int cmp(const void *a,const void *b) {
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;

    if (arg1 > arg2) {
        return -1;
    }else if (arg1 < arg2){
        return 1;
    }else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {5,3,2,1,12};
    qsort(arr,5,4,cmp);
    for (int i = 0;i < 5;i++) {
        printf("%d ",*(arr + i));
    }
    return 0;
}