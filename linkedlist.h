#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "base_struct.h"

typedef struct node
{
    item_t data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} linked_list_t;

void init_list(linked_list_t *list);
node_t *create_node(item_t data);
void append_node(linked_list_t *list, item_t data);
void print_list(linked_list_t *list);
void report_by_city(node_t *head);

#endif