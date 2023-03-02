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
void print_list(node_t *head)
{
    node_t *current = head;
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
char *report_by_city(node_t *head)
{
    int count[9] = {0}; // Inicializa el contador de cada ciudad en 0
    node_t *current = head;
    char *buffer = malloc(300 * sizeof(char)); // Define un buffer para almacenar los datos
    sprintf(buffer, "Report by City:\n");      // Agrega el encabezado al buffer

    // Recorre la lista y aumenta el contador de la ciudad correspondiente por cada nodo
    while (current != NULL)
    {
        count[current->data.city]++;
        current = current->next;
    }

    for (int i = 0; i <= 8; i++)
    {
        sprintf(buffer + strlen(buffer), "%s: %d\n", city_names[i], count[i]);
    }

    return buffer; // Retorna el buffer con los datos almacenados
}

/*Función para obtener el promedio de ingresos de todas las personas que viven
en una determinada ciudad y que tienen entre X y Y años (X y Y incluidos).
*/

float avg_income_by_city_age(node_t *head, char *city_name, int min_age, int max_age)
{
    int total_income = 0;
    int count = 0;

    // Validar si la ciudad es válida
    city_t city = get_city_t(city_name);
    if (city == E)
    {
        printf("Invalid city name\n");
        return -1;
    }

    // Iterar sobre todos los nodos de la lista enlazada
    node_t *current = head;
    while (current != NULL)
    {
        // Seleccionar aquellos que cumplan con las condiciones de edad y ciudad
        item_t data = current->data;
        if (data.city == city && data.age >= min_age && data.age <= max_age)
        {
            total_income += data.income;
            count++;
        }
        current = current->next;
    }

    // Calcular el promedio de ingresos
    if (count > 0)
    {
        return (float)total_income / count;
    }
    else
    {
        printf("No people found for the given arguments\n");
        return -1;
    }
}

float probability_ill(node_t *head, int age)
{
    node_t *current = head;
    int count = 0;
    int ill = 0;

    // Iterar sobre todos los nodos de la lista enlazada
    while (current != NULL)
    {
        // Seleccionar aquellos que cumplan con las condiciones
        item_t data = current->data;
        if (data.age >= age)
        {
            count++;
            if (data.illness == true)
            {
                ill++;
            }
        }
        current = current->next;
    }

    // Calcular probabilidad
    if (count > 0)
    {
        return (float)ill / count * 100;
    }
    else
    {
        printf("No people found for the given argument\n");
        return -1;
    }
}

// Obtener elemento de la lista enlazada por su ID
char* get_element_by_id(node_t *head, int id)
{

    node_t *current = head;
    int count = 0;
    char *buffer = malloc(300 * sizeof(char));
    sprintf(buffer, "the requested item is:\n"); // Agrega el encabezado al buffer

    while (current != NULL && count < id - 1)
    {
        current = current->next;
        count++;
    }

    sprintf(buffer + strlen(buffer), "ID: %u\nCity: %s\nAge: %u\nGender: %s\nIncome: %d\nIllness: %s\n",
           current->data.id, city_names[current->data.city], current->data.age,
           gender_names[current->data.gender], current->data.income,
           illness_values[current->data.illness]);
    return buffer;
}

// Insertar un nuevo elemento en la mitad
void inser_in_half(node_t *head, item_t data)
{
    node_t *current, *previous;
    int half = 75000;
    int count = 0;

    current = head;

    while (current != NULL && count < half - 1)
    {
        previous = current;
        current = current->next;
        count++;
    }
    data.id = half;
    node_t *new_node = create_node(data);
    previous->next = new_node;
    new_node->next = current;

    // Recalcular id's de elementos posteriores
    while (current != NULL)
    {
        current->data.id = current->data.id + 1;
        current = current->next;
    }
}

char *report_by_city_age(node_t *head, int age)
{
    int count[9] = {0}; // Inicializa el contador de cada ciudad en 0
    node_t *current = head;
    char *buffer = malloc(300 * sizeof(char));
    sprintf(buffer, "Report of %d years old person by City:\n", age); // Agrega el encabezado al buffer

    // Recorre la lista y aumenta el contador de la ciudad correspondiente por cada nodo
    while (current != NULL)
    {
        if (current->data.age == age)
        {
            count[current->data.city]++;
            current = current->next;
        }
        else
        {
            current = current->next;
        }
    }

    // Imprime el reporte
    for (int i = 0; i <= 8; i++)
    {
        sprintf(buffer + strlen(buffer), "%s: %d\n", city_names[i], count[i]);
    }

    return buffer; // Retorna el buffer con los datos almacenados
}