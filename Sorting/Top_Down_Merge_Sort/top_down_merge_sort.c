#include "top_down_merge_sort.h"
#include <string.h>

void merge(char *arr,char *tmp,size_t l,size_t m,size_t r,size_t size,int (*compar)(const void*,const void*)) {
    size_t i = l,j = m + 1;

    for (size_t k = l;k <= r;k++) {
        memcpy(tmp + k * size,arr + k * size,size);
    }

    for (size_t k = l;k <= r;k++) {
        if (i > m) {
            memcpy(arr + k * size,tmp + j * size,size);
            j++;
        }else if (j > r) {
            memcpy(arr + k * size,tmp + i * size,size);
            i++;
        }else if (compar(tmp + j * size,tmp + i * size) < 0) {
            memcpy(arr + k * size,tmp + j * size,size);
            j++;
        }else {
            memcpy(arr + k * size,tmp + i * size,size);
            i++;
        }
    }
}

void sort(char *arr,char *tmp,size_t l,size_t r,size_t size, int (*compar)(const void*,const void*)) {
    if (l >= r) {
        return ;
    }
    size_t m = l + (r - l) / 2;
    sort(arr,tmp,l,m,size,compar);
    sort(arr,tmp,m + 1,r,size,compar);
    merge(arr,tmp,l,m,r,size,compar);
}

void msort(void *base,size_t nmemb,size_t size,int (*compar)(const void*,const void*)) {
    char *arr = (char*)base;

    char *tmp = (char*)malloc(nmemb * size);

    sort(arr,tmp,0,nmemb - 1,size,compar);
}