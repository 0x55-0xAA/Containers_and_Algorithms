#ifndef VECTOR_H
#define VECTOR_H
#include <stdarg.h>

#define VECTOR_INIT(vec_ptr,type,val_type,capa,memberSizeName,memberCapaName,memberArrName) do { \
    (vec_ptr) = (type*)malloc(sizeof(type)); \
    if ((vec_ptr))  {  \
        (vec_ptr)->memberArrName = (val_type*)malloc(sizeof(val_type) * capa);  \ 
        (vec_ptr)->memberSizeName = 0; \
        (vec_ptr)->memberCapaName = capa; \
    } \
} while (0)

#define VECTOR_ENSURE_CAPACITY(vec_ptr,val_type,memberSizeName,memberCapaName,memberArrName,capa) do {    \
    if (((vec_ptr)->memberCapaName) < (capa)) { \
        int newCapacity = capa * 2; \
        if ((newCapacity) < (capa)) {   \
            newCapacity = capa; \
        }   \
        val_type* newArr = (val_type*)malloc(sizeof(val_type) * newCapacity);   \
        if (newArr != NULL) {   \
            memcpy(newArr,(vec_ptr)->memberArrName,sizeof(val_type) * (vec_ptr)->memberSizeName);   \
            (vec_ptr)->memberArrName = newArr;  \
            (vec_ptr)->memberCapaName = newCapacity;    \
        }   \
        if (newArr == NULL) {   \
            exit(1);   \
        }   \
    }   \
} while (0)

#define VECTOR_PUSH_BACK(vec_ptr,type,memberSizeName,memberArrName,val)  do {    \
    (vec_ptr)->memberArrName[((vec_ptr)->memberSizeName)++] = (val);    \
} while (0)

#define VECTOR_POP_BACK(vec_ptr,type,memberSizeName,memberArrName,val)  do {    \
    (val) = (vec_ptr)->memberArrName[--((vec_ptr)->memberSizeName)];  \
} while(0)

#endif