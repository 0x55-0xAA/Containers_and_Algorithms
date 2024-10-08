#ifndef  QUICK_SORT_THREE_WAYS_H
#define QUiCK_SORT_THREE_WAYS_H

#include <stdlib.h>

// #ifndef SWAP(a,b,size) 
#define SWAP(a,b,size) do{  \
    size_t __size = (size);    \
    char *__a = (a),*__b = (b);     \
    do  \
    {   \
        char temp = *__a;    \
        *__a++ = *__b;    \
        *__b++ = temp;    \
    } while (--__size > 0);     \
} while (0)

// #endif //SWAP(a,b,size)

extern void __quick_sort(char *base,size_t size,size_t lo,size_t hi,int (*compar)(const void *,const void *));

extern void qsort_threeways(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));

#endif // QUICK_SORT_THREE_WAYS_H