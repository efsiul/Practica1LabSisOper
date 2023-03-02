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
void print_list(node_t *head);
char* report_by_city(node_t *head);
float avg_income_by_city_age(node_t *head, char *city_name, int min_age, int max_age);
float probability_ill(node_t *head, int age);
char* get_element_by_id(node_t *head, int id);
void inser_in_half(node_t *head, item_t data);
char *report_by_city_age(node_t *head, int age);

#endif