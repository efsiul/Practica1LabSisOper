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

/*Función para obtener el promedio de ingresos de todas las personas que viven
en una determinada ciudad y que tienen entre X y Y años (X y Y incluidos).
*/

float avg_income_by_city_age(linked_list_t* list, char* city_name, int min_age, int max_age) {
    int total_income = 0;
    int count = 0;

    // Validar si la ciudad es válida
    city_t city = get_city_t(city_name);
    if (city == E) {
        printf("Invalid city name\n");
        return -1;
    }

    // Iterar sobre todos los nodos de la lista enlazada
    node_t* current = list->head;
    while (current != NULL) {
        // Seleccionar aquellos que cumplan con las condiciones de edad y ciudad
        item_t data = current->data;
        if (data.city == city && data.age >= min_age && data.age <= max_age) {
            total_income += data.income;
            count++;
        }
        current = current->next;
    }

    // Calcular el promedio de ingresos
    if (count > 0) {
        return (float) total_income / count;
    } else {
        printf("No people found for the given arguments\n");
        return -1;
    }
}

float probability_ill(node_t *head, int age)
{
    node_t *current = head;
    int count=0;
    int ill=0;

    // Iterar sobre todos los nodos de la lista enlazada
    while(current != NULL){
        // Seleccionar aquellos que cumplan con las condiciones
        item_t data = current->data;
        if(data.age>=age){
            count++;
            if(data.illness == true){
                ill++;
            }
        }
        current = current->next;
    }

    // Calcular probabilidad
    if(count>0){
        return (float) ill / count*100;
    }else{
        printf("No people found for the given argument\n");
        return -1;
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