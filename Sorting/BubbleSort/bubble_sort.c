#include "bubblesort.h"
#include <string.h>

void swap(void *a,void *b,size_t size) {
    char tmp[size];
    memcpy(tmp,a,size);
    memcpy(a,b,size);
    memcpy(b,tmp,size);
}

void bsort(void *base,size_t nmemb,size_t size,int (*compar)(const void*,const void*)) {
    char *arr = (char*)base;

    for (size_t i = 0;i < nmemb - 1;i++) {
        for (size_t j = 0;j < nmemb - i - 1;j++) {
            if (compar(arr + j * size,arr + (j + 1) * size) > 0) {
                swap(arr + j * size,arr + (j + 1) * size,size);
            }
        }
    }
}