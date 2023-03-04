#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "menu.h"
#include "base_struct.h"
#include "vector_struct.h"
#include "linkedlist.h"
#include "report.h"

char *ciudades[8] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston", "Washington D.C.", "San Diego", "Austin"};
item_t select_data()
{
    item_t data;
    int tmp;

    char *genders[3] = {"Male", "Female", "No"};
    char *ill[3] = {"No", "Yes", "Not defined"};

    // Pedir al usuario que seleccione una ciudad
    printf("Seleccione una ciudad:\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d. %s\n", i + 1, ciudades[i]);
    }
    scanf("%d", &tmp);
    data.city = get_city_t(ciudades[tmp - 1]);

    printf("\nIngrese la edad:\n");
    scanf("%u", &data.age);

    do
    {
        printf("\nSeleccione el genero: \n");
        printf("1. Male\n2. Female\n3. NO\n");
        scanf("%d", &tmp);
    } while (tmp != 1 && tmp != 2 && tmp != 3);

    data.gender = get_gender_t(genders[tmp - 1]);
    do
    {
        printf("\nSeleccione un estado de enfermedad: \n");
        printf("1. Yes\n2. No\n3. Not defined\n");
        scanf("%d", &tmp);
    } while (tmp != 1 && tmp != 2 && tmp != 3);

    data.illness = get_illness_t(ill[tmp - 1]);

    printf("\nDigile el valor de ingresos: \n");
    scanf("%d", &data.income);

    return data;
}

void selectMenu(char *submenu, item_t *items, size_t num_items, linked_list_t *list)
{
    int opcion;
    int resultado;
    do
    {
        printf("\n"
               "1. Consulte la cantidad de personas por ciudad\n");
        printf("2. Promedio de ingresos de personas por ciudad\n");
        printf("3. Probabilidad de que una personas esté enferma cuando tiene X o más edad\n");
        printf("4. Recuperar un elemento del listado de acuerdo a su ID\n");
        printf("5. Insertar un elemento en la mitad de todos los datos\n");
        printf("6. Calcular la cantidad de personas por edad que viven en una ciudad\n");
        printf("7. Generar reportes de actividades realizadas en este programa\n");
        printf("8. Atras\n"
               "\n");

        printf("Seleccione una opcion: ");
        while (scanf("%d", &opcion) != 1)
        {
            // Si el valor ingresado no es un entero, se repite la solicitud
            printf("Ingrese un valor entero valido: ");
            while (getchar() != '\n')
                ; // Limpia el buffer del teclado
        }

        switch (opcion)
        {
        case 1:
            printf("\nConsulte la cantidad de personas por ciudad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral1Vector
                printf("función para vector\n");

                report_by_city_v(items, num_items);
            }
            else
            {
                /// Opción para numeral1LL
                printf("función para LL\n");

                node_t *head_node = get_head(list);
                report_by_city(head_node);
            }
            break;
        case 2:
            printf("\nPromedio de ingresos de personas por ciudad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral2Vector
                printf("función para vector\n");

                // Pedir al usuario que seleccione una ciudad
                int opcion;
                printf("Seleccione una ciudad:\n");
                for (int i = 0; i < 8; i++)
                {
                    printf("%d. %s\n", i + 1, ciudades[i]);
                }
                scanf("%d", &opcion);

                char *ciudad_seleccionada = ciudades[opcion - 1];
                int min_age, max_age;

                printf("\nIngrese la edad mínima: ");
                scanf("%d", &min_age);

                printf("\nIngrese la edad máxima: ");
                scanf("%d", &max_age);

                avg_income_by_city_age_v(items, num_items, ciudad_seleccionada, min_age, max_age);
            }
            else
            {
                /// Opción para numeral2LL
                printf("función para LL\n");

                // Pedir al usuario que seleccione una ciudad
                int opcion;
                printf("Seleccione una ciudad:\n");
                for (int i = 0; i < 8; i++)
                {
                    printf("%d. %s\n", i + 1, ciudades[i]);
                }
                scanf("%d", &opcion);

                char *ciudad_seleccionada = ciudades[opcion - 1];
                int min_age, max_age;

                printf("\nIngrese la edad mínima: ");
                scanf("%d", &min_age);

                printf("\nIngrese la edad máxima: ");
                scanf("%d", &max_age);

                node_t *head_node = get_head(list);
                avg_income_by_city_age(head_node, ciudad_seleccionada, min_age, max_age);
            }
            break;
        case 3:
            printf("\nCalcular la probalidad de enfermedad por edad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral3Vector
                printf("función para vector\n\n");
                int age;
                printf("Ingrese la edad: ");
                scanf("%d", &age);

                probability_ill_v(items, num_items, age); // 3
            }
            else
            {
                /// Opción para numeral3LL
                printf("función para LL\n\n");
                int age;
                printf("Ingrese la edad: ");
                scanf("%d", &age);

                node_t *head_node = get_head(list);
                probability_ill(head_node, age); // 3
            }
            break;
        case 4:
            printf("\nRecuperar un elemento del listado de acuerdo a su ID\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral4Vector
                printf("función para vector\n\n");
                int id;
                printf("Ingrese id a buscar: ");
                scanf("%d", &id);

                get_element_by_id_v(items, num_items, id); // 3
            }
            else
            {
                /// Opción para numeral4LL
                printf("función para LL\n\n");
                int id;
                printf("Ingrese id a buscar: ");
                scanf("%d", &id);

                node_t *head_node = get_head(list);
                get_element_by_id(head_node, id); // 3
            }
            break;
        case 5:
            printf("\nInsertar un elemento en la mitad de todos los datos\n");
            if (strcmp(submenu, "Vectores") == 0)
            {

                // Opción para numeral5Vector
                printf("función para vector\n\n");
                item_t data = select_data();
                inser_in_half_v(items, num_items, data); // 5
                num_items++;
            }
            else
            {
                /// Opción para numeral5LL

                printf("función para LL\n\n");
                node_t *head_node = get_head(list);
                item_t data = select_data();
                inser_in_half(head_node, data); // 5
            }
            break;
        case 6:
            printf("\nCalcular la cantidad de personas por edad de una ciudad\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral6Vector

                printf("función para vector\n\n");

                int age;
                printf("Ingrese la edad: ");
                scanf("%d", &age);

                report_by_city_age_v(items, num_items, age); // 3
            }
            else
            {
                /// Opción para numeral6LL

                printf("función para LL\n");

                int age;

                printf("Ingrese la edad: ");
                scanf("%d", &age);

                node_t *head_node = get_head(list);
                report_by_city_age(head_node, age); // 3
            }
            break;

        case 7:
            printf("\nReporte de los eventos realizados en el programa\n");

            FILE *fp = fopen(name_report, "r");
            if (fp != NULL)
            {
                printf("El reporte se genera automáticamente, puede revisar el archivo %s en el directorio raiz\n", name_report);
                fclose(fp);
            }
            else
            {
                printf("\nNo hay información para reportar\n");
            }

            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            sprintf(name_report, "reporte_%d-%02d-%02d_%02d-%02d-%02d.txt",
                    tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

            break;
        default:
            printf("Opcion invalida. Por favor, selecciona una opcion valida.\n");
            break;
        }
    } while (opcion != 8);
}
