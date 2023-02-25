#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "linkedlist.h"

// Inicializar una lista enlazada vacía
void init_list(linked_list_t *list)
{
    list->head = NULL;
    list->tail = NULL;
}

// Crear un nuevo nodo con los datos proporcionados
node_t *create_node(item_t data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Agregar un nuevo nodo al final de la lista enlazada
void append_node(linked_list_t *list, item_t data)
{
    node_t *new_node = create_node(data);
    if (list->tail == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Imprimir los elementos de la lista enlazada
void print_list(linked_list_t *list)
{
    node_t *current = list->head;
    while (current != NULL)
    {
        printf("ID: %u, City: %s, Age: %u, Gender: %s, Income: %d, Illness: %s\n",
               current->data.id, city_names[current->data.city], current->data.age,
               gender_names[current->data.gender], current->data.income,
               illness_values[current->data.illness]);
        current = current->next;
    }
}

// Función para generar un reporte de la cantidad de personas por cada ciudad
void report_by_city(node_t *head)
{
    int count[9] = {0}; // Inicializa el contador de cada ciudad en 0
    node_t *current = head;

    // Recorre la lista y aumenta el contador de la ciudad correspondiente por cada nodo
    while (current != NULL)
    {
        count[current->data.city]++;
        current = current->next;
    }

    // Imprime el reporte
    printf("Report by City:\n");
    for (int i = 0; i <= 8; i++)
    {
        printf("%s: %d\n", city_names[i], count[i]);
    }
}

// int main()
// {
//     item_t person = {1, get_city_t("New York City"), 25, get_gender_t("Male"), 50000, get_illness_t("No")};
//     linked_list_t list;
//     init_list(&list);
//     append_node(&list, person);
//     print_list(&list);
// }