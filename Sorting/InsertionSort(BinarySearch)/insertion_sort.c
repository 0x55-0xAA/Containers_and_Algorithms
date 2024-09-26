#include "insertionsort.h"
#include <string.h>

size_t upper_bound(char *base,size_t l,size_t r,size_t size,const void *target,int (*compar)(const void *,const void *)) {
    long long left = l;
    long long right = r;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        const void *mid_element = base + mid * size;
        if (compar(mid_element,target) <= 0) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return left;
}


void isort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *)) {
    char *arr = (char*)base;
    for (size_t i = 1;i < nmemb;i++) {
        const void *target = arr + i * size;
        char key[size];
        memcpy(key,target,size);
        size_t insert_location = upper_bound(arr,0,i - 1,size,target,compar);
        for (size_t j = i;j > insert_location;j--) {
            char tmp[size];
            memcpy(tmp,arr + (j - 1) * size,size);
            memcpy(arr + j * size,tmp,size);
        }
        memcpy(arr + insert_location * size,key,size);
    }
}