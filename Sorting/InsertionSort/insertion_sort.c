#include "insertionsort.h"
#include <string.h>

void swap(void *a,void *b,size_t size) {
    char tmp[size];
    memcpy(tmp,a,size);
    memcpy(a,b,size);
    memcpy(b,tmp,size);
}

void isort(void *base,size_t nmemb,size_t size,int (*compar)(const void*,const void*)) {
    char *arr = (char*)base;

    for (size_t i = 1;i < nmemb;i++) {
        size_t j = i;
        while (j > 0 && compar(arr + j * size,arr + (j - 1) * size) < 0) {
            swap(arr + j * size, arr + (j - 1) * size,size);
            j--;
        }
    }
}