#include "quicksort.h"
#include <string.h>

void
swap(void *arg1,void *arg2,size_t size) {
    char tmp[size];
    memcpy(tmp,arg1,size);
    memcpy(arg1,arg2,size);
    memcpy(arg2,tmp,size);
}

size_t 
partition(char *base,size_t size,size_t l,size_t r,int (*compar)(const void *,const void *)) {
    size_t i = l + 1,j = r - 1;
    void *pivot = base + l * size;
    while (i < j && compar(base + i * size,pivot) < 0) {
        i++;
    }
    while (i < j && compar(pivot,base + j * size) < 0) {
        j--;
    }
    swap(base + i * size,base + j * size,size);
    swap(base + l * size,base + j * size,size);
    return j;
}

void 
__quick_sort(char *base,size_t size,size_t l,size_t r,int (*compar)(const void *,const void *)) {
    if (l >= r) {
        return ;
    }
    size_t partition_index = partition(base,size,l,r,compar);
    __quick_sort(base,size,l,partition_index - 1,compar);
    __quick_sort(base,size,partition_index + 1,r,compar);
}

void 
q_sort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *)) {
    char *arr = (char*)base;

    __quick_sort(arr,size,0,nmemb - 1,compar);
}



