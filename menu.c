#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "base_struct.h"
#include "vector_struct.h"
#include "linkedlist.h"

char reporte[5000];

void selectMenu(char *submenu, item_t *items, size_t num_items, linked_list_t *list)
{
    int opcion;

    do
    {
        printf("\n"\
                "1. Consulte la cantidad de personas por ciudad\n");
        printf( "2. Promedio de ingresos de personas por ciudad\n");
        printf( "3. Calcular la probabilidad de personas por edad\n");
        printf( "4. Recuperar un elemento del listado de acuerdo a su ID\n");
        printf( "5. Insertar un elemento en la mitad de todos los datos\n");
        printf( "6. Calcular la cantidad de personas por edad que viven en una ciudad\n");
        printf( "7. Generar reportes de actividades realizadas en este programa\n");
        printf( "8. Atras\n"\
                "\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Consulte la cantidad de personas por ciudad.\n");
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
            printf("Promedio de ingresos de personas por ciudad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral2Vector
                printf("función para vector\n");
                char *ciudades[8] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston", "Washington D.C.", "San Diego", "Austin"};
    
                // Pedir al usuario que seleccione una ciudad
                int opcion;
                printf("Seleccione una ciudad:\n");
                for (int i = 0; i < 8; i++) {
                    printf("%d. %s\n", i + 1, ciudades[i]);
                }
                scanf("%d", &opcion);
    
                char *ciudad_seleccionada = ciudades[opcion - 1];
                int min_age, max_age;

                printf("Ingrese la edad mínima: ");
                scanf("%d", &min_age);

                printf("Ingrese la edad máxima: ");
                scanf("%d", &max_age);


                avg_income_by_city_age_v(items, num_items, ciudad_seleccionada, min_age, max_age);



             }
            else
            {
                /// Opción para numeral2LL
                printf("función para LL\n");
                char *ciudades[8] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston", "Washington D.C.", "San Diego", "Austin"};
    
                // Pedir al usuario que seleccione una ciudad
                int opcion;
                printf("Seleccione una ciudad:\n");
                for (int i = 0; i < 8; i++) {
                    printf("%d. %s\n", i + 1, ciudades[i]);
                }
                scanf("%d", &opcion);
    
                char *ciudad_seleccionada = ciudades[opcion - 1];
                int min_age, max_age;

                printf("Ingrese la edad mínima: ");
                scanf("%d", &min_age);

                printf("Ingrese la edad máxima: ");
                scanf("%d", &max_age);
                
                node_t *head_node = get_head(list);
                avg_income_by_city_age(head_node, ciudad_seleccionada, min_age, max_age);
            }
            break;
        case 3:
            printf("Calcular la probalidad de enfermedad por edad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral3Vector
                printf("función para vector\n");
                int age;
                printf("Ingrese la edad: ");
                scanf("%d", &age);
                
                probability_ill_v(items, num_items, age);//3
        
            }
            else
            {
                /// Opción para numeral3LL
                printf("función para LL\n");
                int age;
                printf("Ingrese la edad: ");
                scanf("%d", &age);

                node_t *head_node = get_head(list);
                probability_ill(head_node, age);//3

           }
            break;
        case 4:
            printf("Recuperar un elemento del listado de acuerdo a su ID\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
               // Opción para numeral4Vector
                printf("función para vector\n");
                int id;
                printf("Ingrese id a buscar: ");
                scanf("%d", &id);

                get_element_by_id_v(items, num_items, id);//3


}
            else
            {
                /// Opción para numeral4LL
                printf("función para LL\n");
                int id;
                printf("Ingrese id a buscar: ");
                scanf("%d", &id);

                node_t *head_node = get_head(list);
                get_element_by_id(head_node, id);//3

         }
            break;
        case 5:
            printf("Insertar un elemento en la mitad de todos los datos\n");
            if (strcmp(submenu, "Vectores") == 0)
            {

                // Opción para numeral5Vector
                printf("función para vector\n");

                
                inser_in_half_v(items, num_items);//5
}
            else
            {
                /// Opción para numeral5LL
          
                printf("función para LL\n");
                node_t *head_node = get_head(list);
                item_t data;
                inser_in_half(head_node, data);//5


 }
            break;
        case 6:
            printf("Calcular la cantidad de personas por edad de una ciudad\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                // Opción para numeral6Vector
               
                printf("función para vector\n");

                int age;
                printf("Ingrese la edad: ");
                scanf("%d", &age);

                report_by_city_age_v(items, num_items, age);//3

}
            else
            {
                /// Opción para numeral6LL
             
                printf("función para LL\n");

                int age;

                printf("Ingrese la edad: ");
                scanf("%d", &age);

                node_t *head_node = get_head(list);
                report_by_city_age(head_node, age);//3


 }
            break;

        case 7:
            printf("Reporte de los eventos realizados en el programa\n");
           
            FILE *fp = fopen("reporte.txt", "r");

            fseek(fp, 0, SEEK_END);  // Mover el indicador de posición al final del archivo
            long size = ftell(fp);   // Obtener la posición actual

            if (size == 0) {
                printf("Error. Todavía no se puede generar un reporte\n");

            } else {
                printf("El reporte se genera automáticamente, puede revisar el archivo reporte.txt en el directorio raiz\n");
            }

    fclose(fp);

            break;
        default:
            printf("Opcion invalida. Por favor, selecciona una opcion valida.\n");
            break;
        }
    } while (opcion != 8);
}

/*

void numeral1Vector(item_t *items, size_t num_items){
    inicio=clock();


    inicio=clock();

    fin=clock();
    tiempo=(double)(fin - inicio)/ CLOCKS_PER_SEC;
    sprintf(reporte, "Tiempo de ejecución para el Numeral 1 - VECTOR, es de: %.9f segundos.\n", tiempo);
    //printf("Tiempo de ejecución para el Numeral 1 - VECTOR, es de: %.9f segundos.\n", tiempo);


    //Recorriendo todo el vector
    for (int i = 0; i < num_items; i++) {
  	
	printf("id= %d\n", items[i].id);
	
	printf("-----------------------------------------------------\n\n");
	}

    fin=clock();
    tiempo=(double)(fin - inicio)/ CLOCKS_PER_SEC;
    sprintf(reporte, "Tiempo de ejecución para el Numeral 1 - VECTOR, es de: %.9f segundos.\n", tiempo);
    //printf("Tiempo de ejecución para el Numeral 1 - VECTOR, es de: %.9f segundos.\n", tiempo);



}

*/
