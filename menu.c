#include <stdio.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "base_struct.h"
#include "linkedlist.h"

clock_t inicio, fin;
double tiempo;
char reporte[1000];

void selectMenu(char *submenu, item_t *items, size_t num_items)
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
        printf( "8. Salir\n"\
                "\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Consulte la cantidad de personas por ciudad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                numeral1Vector(items, num_items);
            }
            else
            {
                //Opción para numerlLL
                printf("función Lista Ligada\n");
            }
            break;
        case 2:
            printf("Promedio de ingresos de personas por ciudad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                printf("función para vector\n");
            }
            else
            {
                // Opción para numerlLL
                printf("función Lista Ligada\n");
            }
            break;
        case 3:
            printf("Calcular la probalidad de enfermedad por edad.\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                printf("función para vector\n");
            }
            else
            {
                // Opción para numerlLL
                printf("función Lista Ligada\n");
            }
            break;
        case 4:
            printf("Recuperar un elemento del listado de acuerdo a su ID\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                printf("función para vector\n");
            }
            else
            {
                // Opción para numerlLL
                printf("función Lista Ligada\n");
            }
            break;
        case 5:
            printf("Insertar un elemento en la mitad de todos los datos\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                printf("función para vector\n");
            }
            else
            {
                // Opción para numerlLL
                printf("función Lista Ligada\n");
            }
            break;
        case 6:
            printf("Calcular la cantidad de personas por edad de una ciudad\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                printf("función para vector\n");
            }
            else
            {
                // Opción para numerlLL
                printf("función Lista Ligada\n");
            }
            break;

        case 7:
            printf("Reporte de los eventos realizados en el programa\n");
            if (strcmp(submenu, "Vectores") == 0)
            {
                printf("función para vector\n");
            }
            else
            {
                // Opción para numerlLL
                printf("función Lista Ligada\n","\n");
            }
            break;
        default:
            printf("Opcion invalida. Por favor, selecciona una opcion valida.\n");
            break;
        }
    } while (opcion != 8);
}

void numeral1Vector(item_t *items, size_t num_items){
    inicio=clock();

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
void numeral1LL(){


}
void numeral2Vector(){


}
void numeral2LL(){


}
void numeral3Vector(){


}
void numeral3LL(){


}
void numeral4Vector(){


}
void numeral4LL(){


}
void numeral5Vector(){


}
void numeral15LL(){


}
void numeral6Vector(){


}
void numeral6LL(){


}

void generarReporte(){
    FILE *archivoSalida;
    archivoSalida=fopen("reporte.txt", "w");
    fprintf(archivoSalida, "%s", reporte);
    fclose(archivoSalida);

    reporte[0] = '\0';


}



