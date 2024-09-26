#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct ShortVector {
    int size;
    int defaultCapacity;
    short *arr;
};

struct IntVector {
    int size;
    int defaultCapacity;
    int *arr;
};

struct LongVector {
    int size;
    int defaultCapacity;
    long *arr;
};

struct LongLongVector {
    int size;
    int defaultCapacity;
    long long *arr;
};

struct UnsignedVector {
    int size;
    int defaultCapacity;
    unsigned *arr;
};

struct UlVector {
    int size;
    int defaultCapacity;
    unsigned long *arr;
};

struct UllVector {
    int size;
    int defaultCapacity;
    unsigned long long *arr;
};

struct FloatVector {
    int size;
    int defaultCapacity;
    float *arr;
};

struct DoubleVector {
    int size;
    int defaultCapacity;
    double *arr;
};

struct LongDoubleVector {
    int size;
    int defaultCapacity;
    long double *arr;
};

struct CharVector {
    int size;
    int defaultCapacity;
    char *arr;
};

struct StringVector {
    int size;
    int defaultCapacity;
    char **arr;
};

struct IntVector* intVectorInit(int capacity) {
    struct IntVector* intVector = NULL;
    VECTOR_INIT(intVector,struct IntVector,int,capacity,size,defaultCapacity,arr);
    return intVector;
}

void ensureCapacity(struct IntVector *intVector,int capacity) {
    VECTOR_ENSURE_CAPACITY(intVector,int,size,defaultCapacity,arr,capacity);
}

void push_back(struct IntVector *intVector,int val) {
    ensureCapacity(intVector,intVector->size + 1);
    VECTOR_PUSH_BACK(intVector,int,size,arr,val);
}

int pop_back(struct IntVector *intVector) {
    if (intVector->size == 0) {
        exit(1);
    }
    int element;
    VECTOR_POP_BACK(intVector,int,size,arr,element);
    return element;
}

int main(int argc, char const *argv[])
{
    struct IntVector *intVector = intVectorInit(5);
    push_back(intVector,1);
    push_back(intVector,2);
    push_back(intVector,3);
    push_back(intVector,4);
    push_back(intVector,5);
    push_back(intVector,6);
    printf("%d\n",intVector->size);
    printf("%d\n",pop_back(intVector));
    printf("%d\n",pop_back(intVector));
    printf("%d\n",pop_back(intVector));
    printf("%d\n",pop_back(intVector));
    printf("%d\n",pop_back(intVector));
    printf("%d\n",intVector->size);
    return 0;
}
