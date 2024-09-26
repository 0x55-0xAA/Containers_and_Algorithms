#if !defined(SELECTION_SORT_H)
#define SELECTION_SORT_H
#include <stdlib.h>

extern void swap(void *a,void *b,size_t size);

extern void ssort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));

#endif // SELECTION_SORT_H
