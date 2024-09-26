#include "list.h"

void list_init(struct List_Structure *list) {
    list->next = list;
    list->prev = list;
}

void list_insert_after(struct List_Structure *list,struct List_Structure *node) {
    list->next->prev = node;
    node->next = list->next;
    list->next = node;
    node->prev = list;
}

void list_insert_before(struct List_Structure *list,struct List_Structure *node) {
    list->prev->next = node;
    node->prev = list->prev;
    list->prev = node;
    node->next = list; 
}

void list_remove(struct List_Structure *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

int list_isempty(const struct List_Structure *list) {
    return list->next == list;
}

unsigned long list_len(struct List_Structure *list) {
    unsigned long len = 0;
    const struct List_Structure *tmp = list;
    while (tmp->next != list) {
        len++;
        tmp = tmp->next;
    }
    return len;
}


