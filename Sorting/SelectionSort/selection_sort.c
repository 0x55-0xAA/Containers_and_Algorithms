#include "selectionsort.h"
#include <string.h>

void swap(void *a,void *b,size_t size) {
    char tmp[size];
    memcpy(tmp,a,size);
    memcpy(a,b,size);
    memcpy(b,tmp,size);
}

void ssort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *)) {
    char *arr = (char*)base;

    for (size_t i = 0;i < nmemb;i++) {
        size_t max_or_min = i;
        for(size_t j = i + 1;j < nmemb;j++) {
            if (compar(arr + j * size,arr + max_or_min * size) < 0) {
                max_or_min = j;
            }
        }
        swap(arr + i * size,arr + max_or_min * size,size);
    }
}