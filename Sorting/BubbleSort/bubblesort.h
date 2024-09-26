#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdlib.h>

extern void swap(void *a,void *b,size_t size);

extern void bsort(void *base,size_t nmemb,size_t size,int (*compar)(const void*,const void*));

#endif