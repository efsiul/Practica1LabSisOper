#ifndef _VECTOR_STRUCT_H_
#define _VECTOR_STRUCT_H_
#include "base_struct.h"

void report_by_city_v(item_t *items, size_t num_items);                                                    // 1
void avg_income_by_city_age_v(item_t *items, size_t num_items, char *city_name, int min_age, int max_age); // 2
void probability_ill_v(item_t *items, size_t num_items, int age);                                          // 3
void get_element_by_id_v(item_t *items, size_t num_items, int id);                                         // 4
void inser_in_half_v(item_t *items, size_t num_items, item_t element);                                     // 5
void report_by_city_age_v(item_t *items, size_t num_items, int age);                                       // 6

#endif