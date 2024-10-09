#include "quick_sort_three_ways.h"

void __quick_sort(char *base,size_t size,size_t lo,size_t hi,int (*compar)(const void *,const void *)) {

    if (hi <= lo) {
        return ;
    }

    size_t lt = lo,i = lo + 1,gt = hi;
    void *pivot = base + lo * size;
    while (i <= gt) {
        int cmp = compar(base + i * size,pivot);
        if (cmp < 0) {
            SWAP(base + lt * size,base + i * size,size);
            lt++;
            i++;
        }else if (cmp > 0) {
            SWAP(base + gt * size,base + i * size,size);
            gt--;
        }else {
            i++;
        }

    }
    __quick_sort(base,size,lo,lt - 1,compar);
    __quick_sort(base,size,gt + 1,hi,compar); 

    
}

void qsort_threeways(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *)) {
    __quick_sort((char*)base,size,0,nmemb - 1,compar);
}