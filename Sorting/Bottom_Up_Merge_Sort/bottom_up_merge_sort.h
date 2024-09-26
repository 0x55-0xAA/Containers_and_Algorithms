#if !defined(BOTTOM_UP_MERGE_SORT_H)
#define BOTTOM_UP_MERGE_SORT_H

#include <stdlib.h>

extern void merge(char *arr,char *tmp,size_t l,size_t m,size_t r,size_t size,int (*compar)(const void*,const void*));

extern void sort(char *arr,char *tmp,size_t l,size_t r,size_t size,int (*compar)(const void*,const void*));

extern void msort(void *base,size_t nmemb,size_t size,int (*compar)(const void*,const void*));

#endif // BOTTOM_UP_MERGE_SORT_H
