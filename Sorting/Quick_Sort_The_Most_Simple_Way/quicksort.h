#if !defined(QUICK_SORT_H)
#define QUICK_SORT_H

#include <stdlib.h>

extern void __quick_sort(char *base,size_t size,size_t l,size_t r,int (*compar)(const void *,const void *));

extern size_t partition(char *base,size_t size,size_t l,size_t r,int (*compar)(const void *,const void *));

extern void q_sort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));

extern void swap(void *arg1,void *arg2,size_t size);

#endif // QUICK_SORT_H
