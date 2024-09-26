#include "list_s.h"
#include "node.h"
#include <stdlib.h>

#if !defined(LIST_H)
#define LIST_H
#define offset_of(type,member)      ((unsigned long) &((type*)0)->member )

// (type*)0: 这是一个类型转换，它将整数值0转换为一个指向type类型结构体的指针。由于0地址通常是不可访问的，这个表达式本身并不尝试访问内存，而只是创建了一个指向type类型结构体的假指针。
// ((type*)0)->member: 这是一个结构体成员访问表达式。尽管它看起来像是在尝试访问内存地址0处的结构体成员，但实际上，编译器只计算member相对于结构体开头的偏移量，并不实际访问内存。
// &(((type*)0)->member): 这是取地址操作符，它取上面表达式的结果（即member的偏移量）的地址。在大多数情况下，编译器会将这个操作优化为简单地返回偏移量，而不是实际的地址。
// (unsigned long) &(((type*)0)->member): 最后，这是一个类型转换，它将偏移量转换为一个unsigned long类型的整数值。

#define container_of(ptr, type, member) ({                      \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offset_of(type,member) );})

// ​通过结构体和类型，结构体成员的地址来获取结构体的首地址​
// 它首先将传入的指针 ptr 强制转换为指向成员的指针，
// 然后使用 offset_of 宏计算出成员相对于结构体的偏移量。
// 最后，通过从成员地址减去偏移量的方式，得到结构体的首地址。
// 这样我们就可以通过成员恢复这个结构体，从而去倒退链表的值

struct List_Structure list_s;

#define LIST_HEAD_INIT(name) {&(name),&(name)}
#define List_HEAD(name) list_s name = LIST_HEAD_INIT(name)

#define list_entry(node,type,member)    \
    container_of(node,type,member)

#define list_for_each(pos,head)     \
    for (pos = (head)->next;pos != (head);pos = pos->next)

#define list_for_each_safe(pos,n,head)  \
    for (pos = (head)->next,n = (pos)->next;pos != (head);  \
    pos = n,n = (pos)->next)

// 安全删除节点

// extern void list_init(struct List_Structure *list);
// extern void list_insert_after(struct List_Structure *list,struct List_Structure *node);
// extern void list_insert_before(struct List_Structure *list,struct List_Structure *node);
// extern void list_remove(struct List_Structure *node);
// extern int list_isempty(const struct List_Structure *list);
// extern unsigned long list_len(struct List_Structure *list);
#endif // LIST_H
