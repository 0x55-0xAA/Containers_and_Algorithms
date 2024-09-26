#if !defined(INSERTION_SORT_H)
#define INSERTION_SORT_H
#include <stdlib.h>


extern void isort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));

#endif // INSERTION_SORT_H
