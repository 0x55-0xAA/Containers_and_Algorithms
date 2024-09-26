#include "shell_sort.h"
#include <string.h>

void swap(void *a,void *b,size_t size) {
    char tmp[size];
    memcpy(tmp,a,size);
    memcpy(a,b,size);
    memcpy(b,tmp,size);
}

void ssort(void *base,size_t nmemb,size_t size,int (*compar)(const void*,const void*)) {
    char *arr = (char*)base;
    size_t h = 1;
    while (h < nmemb) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (size_t i = h;i < nmemb;i++) {
            for (size_t j = i;j >= h && compar(arr + j * size,arr + (j - h) * size) < 0;j -= h) {
                swap(arr + j * size ,arr + (j - h) * size,size);
            }
        }
        h >>= 1;
    }
}