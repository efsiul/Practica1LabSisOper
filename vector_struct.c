#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include "base_struct.h"
#include "report.h"

clock_t inicio1, fin1;
double tiempo1;

// Función para generar un reporte de la cantidad de personas por cada ciudad
void report_by_city_v(item_t *items, size_t num_items)
{
    inicio1 = clock();
    FILE *fp = fopen(name_report, "a");

    int count[9] = {0};

    for (int i = 0; i < num_items; i++)
    {
        count[items[i].city]++;
    }

    printf("\nLa cantidad de personas por ciudad es: \n");
    fprintf(fp, "La cantidad de personas por ciudad es: \n");
    for (int i = 0; i <= 8; i++)
    {
        printf("%s: %d\n", city_names[i], count[i]);
        fprintf(fp, "%s: %d\n", city_names[i], count[i]);
    }

    fin1 = clock();
    tiempo1 = (double)(fin1 - inicio1) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución para el Numeral 1 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 1 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}

/*Función para obtener el promedio de ingresos de todas las personas que viven
en una determinada ciudad y que tienen entre X y Y años (X y Y incluidos).
*/

void avg_income_by_city_age_v(item_t *items, size_t num_items, char *city_name, int min_age, int max_age)
{
    inicio1 = clock();
    FILE *fp = fopen(name_report, "a");

    int count_people = 0;
    float sum = 0, mean_income = 0;

    // city_t city = get_city_t(city_name);
    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(city_names[items[i].city], city_name) == 0)
        {
            if (items[i].age >= min_age && items[i].age <= max_age)
            {
                count_people = count_people + 1;
                sum += items[i].income;
            }
        }
    }

    if (count_people > 0)
    {

        mean_income = sum / count_people;
        printf("\nEl promedio de ingresos de las personas de la ciudad de %s que tienen entre %d y %d es igual: %.2f\n",
               city_name, min_age, max_age, mean_income);
        fprintf(fp, "El promedio de ingresos de las personas de la ciudad de %s que tienen entre %d y %d es igual: %.2f\n",
                city_name, min_age, max_age, mean_income);
    }
    else
    {
        printf("No people found for the given arguments\n");
        fprintf(fp, "No people found for the given arguments\n");
    }

    printf("Tiempo de ejecución para el Numeral 2 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 2 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}

void probability_ill_v(item_t *items, size_t num_items, int age)
{
    inicio1 = clock();
    FILE *fp = fopen(name_report, "a");

    int count_illness = 0;
    int count_age = 0;

    for (int i = 0; i < num_items; i++)
    {
        if (items[i].age >= age)
        {
            count_age++;
            if (items[i].illness == true)
            {
                count_illness++;
            }
        }
    }

    printf("\nLa probabilidad de estar enfermo en la edad o mayor a %d es de: %.2f%%\n", age, (float)(count_illness * 100) / count_age);
    fprintf(fp, "La probabilidad de estar enfermo en la edad o mayor a %d es de: %.2f%%\n", age, (float)(count_illness * 100) / count_age);

    fin1 = clock();
    tiempo1 = (double)(fin1 - inicio1) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución para el Numeral 3 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 3 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}

// Obtener elemento de la lista enlazada por su ID
void get_element_by_id_v(item_t *items, size_t num_items, int id)
{
    inicio1 = clock();
    FILE *fp = fopen(name_report, "a");

    printf("\nId consultado: %d\nEdad: %d\nCiudad: %s\nGenero: %s\nEnfermedad: %s\nIngresos: %d\n",
           items[id - 1].id, items[id - 1].age, city_names[items[id - 1].city], gender_names[items[id - 1].gender],
           illness_values[items[id - 1].illness], items[id - 1].income);

    fprintf(fp, "Id consultado: %d\nEdad: %d\nCiudad: %s\nGenero: %s\nEnfermedad: %s\nIngresos: %d\n",
            items[id - 1].id, items[id - 1].age, city_names[items[id - 1].city], gender_names[items[id - 1].gender],
            illness_values[items[id - 1].illness], items[id - 1].income);

    fin1 = clock();
    tiempo1 = (double)(fin1 - inicio1) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución para el Numeral 4 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 4 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}

// Insertar un nuevo elemento en la mitad
void inser_in_half_v(item_t *items, size_t num_items, item_t element)
{
    inicio1 = clock();
    FILE *fp = fopen(name_report, "a");

    element.id = 75000;
    items = realloc(items, (num_items + 1) * sizeof(item_t));
    memmove(&items[75000], &items[74999], (num_items - 74999) * sizeof(item_t));

    for (int i = num_items; i >= 75000; i--)
    {
        items[i].id = items[i].id + 1;
    }
    items[74999] = element;

    printf("\nElemento insertado correctamente con los siguientes datos:\n");
    printf("Id: %d\nEdad: %d\nCiudad: %s\nGenero: %s\nEnfermedad: %s\nIngresos: %d\n",
           element.id, element.age, city_names[element.city], gender_names[element.gender],
           illness_values[element.illness], element.income);

    fprintf(fp, "Elemento insertado correctamente con los siguientes datos:\n");
    fprintf(fp, "Id: %d\nEdad: %d\nCiudad: %s\nGenero: %s\nEnfermedad: %s\nIngresos: %d\n",
            element.id, element.age, city_names[element.city], gender_names[element.gender],
            illness_values[element.illness], element.income);

    printf("Tiempo de ejecución para el Numeral 5 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 5 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}

void report_by_city_age_v(item_t *items, size_t num_items, int edad_consulta)
{
    inicio1 = clock();
    FILE *fp = fopen(name_report, "a");

    int count_p[9] = {0};

    for (int i = 0; i < num_items; i++)
    {
        if (items[i].age == edad_consulta)
        {
            count_p[items[i].city]++;
        }
    }

    printf("\número de personas de %d años por ciudad:\n", edad_consulta);
    fprintf(fp, "\nNúmero de personas de %d años por ciudad:\n", edad_consulta);
    for (int i = 0; i <= 8; i++)
    {
        printf("%s: %d\n", city_names[i], count_p[i]);
        fprintf(fp, "%s: %d\n", city_names[i], count_p[i]);
    }

    fin1 = clock();
    tiempo1 = (double)(fin1 - inicio1) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución para el Numeral 6 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 6 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}