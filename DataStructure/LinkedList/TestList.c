#include "list.c"
#include <stdio.h>
int main(int argc, char const *argv[]) {
    struct nodeInt head;
    list_init(&head.list_linker);
    struct nodeDouble node1;
    node1.val = 1.1;
    list_init(&node1.list_linker);
    struct nodeChar node2;
    node2.val = 'A';
    list_init(&node2.list_linker);
    list_insert_after(&head.list_linker,&node1.list_linker);
    list_insert_after(&node1.list_linker,&node2.list_linker);
    printf("%lu\n",list_len(&head.list_linker));
    struct List_Structure *n1 = &node1.list_linker;
    struct nodeDouble *tmp = list_entry(n1,struct nodeDouble,list_linker);
    printf("%f\n",tmp->val);
    return 0;

}
