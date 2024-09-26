#include <stdlib.h>
#include <stdio.h>
#include "insertion_sort.c"

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
    int arr[2] = {1};
    int key = 4;
    printf("%llu\n",upper_bound((char*)arr,0,0,4,&key,cmp));
    return 0;
}
