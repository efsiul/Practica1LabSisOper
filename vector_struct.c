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
    inicio1=clock();
    FILE *fp = fopen(name_report, "a");
    
    int count[9] = {0};
    for (int i = 0; i < num_items; i++) {
        if(strcmp(city_names[items[i].city] , "Dallas")==0){
            count[0]++;
            }
        if(strcmp(city_names[items[i].city], "New York City")==0){
            count[1]++;
            }
        if(strcmp(city_names[items[i].city], "Los Angeles")==0){
            count[2]++;
            }
        if(strcmp(city_names[items[i].city],"Mountain View")==0){
            count[3]++;
            }
        if(strcmp(city_names[items[i].city],"Boston")==0){
            count[4]++;
            }
        if(strcmp(city_names[items[i].city],"Washington D.C.")==0){
            count[5]++;
            }
        if(strcmp(city_names[items[i].city],"San Diego")==0){
            count[6]++;
            }
        if(strcmp(city_names[items[i].city],"Austin")==0){
            count[7]++;
            }
        if(strcmp(city_names[items[i].city],"Not found")==0){
            count[8]++;
            }
    }   
    printf("La cantidad de personas por cada ciudad:");
    printf("\nDallas:  %d" , count[0]);
    printf("\nNew York City: %d", count[1]);
    printf("\nLos Angeles: %d", count[2]);
    printf("\nMountain View: %d", count[3]);
    printf("\nBoston: %d", count[4]);
    printf("\nWashington D.C.: %d", count[5]);
    printf("\nSan Diego: %d", count[6]);
    printf("\nAustin: %d", count[7]);
    printf("\nError: %d \n", count[8]);

    fprintf(fp, "La cantidad de personas por cada ciudad:");
    fprintf(fp, "\nDallas:  %d" , count[0]);
    fprintf(fp, "\nNew York City: %d", count[1]);
    fprintf(fp, "\nLos Angeles: %d", count[2]);
    fprintf(fp, "\nMountain View: %d", count[3]);
    fprintf(fp, "\nBoston: %d", count[4]);
    fprintf(fp, "\nWashington D.C.: %d", count[5]);
    fprintf(fp, "\nSan Diego: %d", count[6]);
    fprintf(fp, "\nAustin: %d", count[7]);
    fprintf(fp, "\nError: %d\n", count[8]);

    fin1=clock();
    tiempo1=(double)(fin1 - inicio1)/ CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución para el Numeral 1 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 1 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}

/*Función para obtener el promedio de ingresos de todas las personas que viven
en una determinada ciudad y que tienen entre X y Y años (X y Y incluidos).
*/

void avg_income_by_city_age_v(item_t *items, size_t num_items, char *city_name, int min_age, int max_age)
{   
    inicio1=clock();
    FILE *fp = fopen(name_report, "a");

    
    int count_people=0; 
    float sum=0, mean_income = 0;
    
    //city_t city = get_city_t(city_name);
    for (int i = 0; i < num_items; i++) {
        if(strcmp(city_names[items[i].city], city_name) == 0){
            if(items[i].age >= min_age && items[i].age<=max_age){
                count_people = count_people+1;
                sum = items[i].income;
            }
        }
    }

    if (count_people > 0) {

        mean_income = sum/count_people;
        printf("El promedio de ingresos de las personas de la ciudad de %s que tienen entre %d y %d es igual: %.2f\n",
        city_name, min_age, max_age, mean_income);
        fprintf(fp, "El promedio de ingresos de las personas de la ciudad de %s que tienen entre %d y %d es igual: %.2f\n",
        city_name, min_age, max_age, mean_income);

    } else {
            printf("No people found for the given arguments\n");
            fprintf(fp, "No people found for the given arguments\n");
            
    }

    printf("Tiempo de ejecución para el Numeral 2 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 2 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);

}

void probability_ill_v(item_t *items, size_t num_items, int age)
{   
    inicio1=clock();
    FILE *fp = fopen(name_report "a");
    
    int count_illness=0;
    int count_age=0;


    for (int i = 0; i < num_items; i++) {
        if(items[i].age >= age){
            count_age++;
            if(items[i].illness == true){
                count_illness++;
            }
        
        }
    }   
    
    printf("La probabilidad de estar enfermo en la edad o mayor a %d es de: %d%%\n", age, (count_illness * 100) / count_age);
    fprintf(fp, "La probabilidad de estar enfermo en la edad o mayor a %d es de: %d%%\n", age, (count_illness * 100) / count_age);

    fin1=clock();
    tiempo1=(double)(fin1 - inicio1)/ CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución para el Numeral 3 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 3 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);

}

// Obtener elemento de la lista enlazada por su ID
void get_element_by_id_v(item_t *items, size_t num_items, int id)
{
    inicio1=clock();
    FILE *fp = fopen(name_report, "a");


    printf("Id consultado: %d\n",id);
    printf("La edad: %d\n",items[id+1].age);
    printf("Ciudad: %s\n",city_names[items[id+1].city]);
    printf("Genero: %s\n",gender_names[items[id+1].gender]);
    printf("Enfermedad: %s\n",illness_values[items[id+1].illness]);
    printf("Ingresos: %d\n",items[id+1].income);

    fprintf(fp, "Id consultado: %d\n",id);
    fprintf(fp, "La edad: %d\n",items[id+1].age);
    fprintf(fp, "Ciudad: %s\n",city_names[items[id+1].city]);
    fprintf(fp, "Genero: %s\n",gender_names[items[id+1].gender]);
    fprintf(fp, "Enfermedad: %s\n",illness_values[items[id+1].illness]);
    fprintf(fp, "Ingresos: %d\n",items[id+1].income);

    fin1=clock();
    tiempo1=(double)(fin1 - inicio1)/ CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución para el Numeral 4 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 4 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);
    
    fclose(fp);
}
/*
void inser_in_half_v(item_t **items, size_t num_items){
    // Crear un nuevo vector
    item_t *new_items = malloc((num_items + 1) * sizeof(item_t));
    
    memcpy(new_items, *items, (num_items / 2) * sizeof(item_t));
    
    // Insertar la nueva estructura, solo como prueba
    new_items[num_items / 2].id = 75000;
    new_items[num_items / 2].city = D;
    new_items[num_items / 2].age = 30;
    new_items[num_items / 2].gender = FEMALE;
    new_items[num_items / 2].income = 50000;
    new_items[num_items / 2].illness = true;
    
    // Copiar los elementos desde la segunda mitad del vector original al final del nuevo vector
    for (int i = num_items / 2 + 1; i <= num_items; i++) {
        new_items[i].id = (*items)[i-1].id + 1;
        new_items[i].city = (*items)[i-1].city;
        new_items[i].age = (*items)[i-1].age;
        new_items[i].gender = (*items)[i-1].gender;
        new_items[i].income = (*items)[i-1].income;
        new_items[i].illness = (*items)[i-1].illness;
    }
    
    // Actualizar el tamaño del nuevo vector
    num_items++;
    
    // Liberar la memoria asignada al vector original
    free(*items);
    
   
    *items = new_items;
    
}
/*


// Insertar un nuevo elemento en la mitad
/*
void inser_in_half_v(item_t *items, size_t num_items)
{   
    inicio1=clock();
    FILE *fp = fopen("reporte.txt", "a");

    unsigned int age_elem;
    
    int income_elem;

    printf("\nIngresa nuevo elemento");

    char *ciudades[8] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston", "Washington D.C.", "San Diego", "Austin"};
    char *generos[3] = {"FEMALE", "MALE", "NO"};
    char *illness[3] = {"false", "true", "fuzzy"};


    // Pedir al usuario que seleccione una ciudad
    int opcion;
    printf("Seleccione una ciudad:\n");
    for (int i = 0; i < 8; i++) {
        printf("%d. %s\n", i + 1, ciudades[i]);
    }
    scanf("%d", &opcion);
    char *city_elem = ciudades[opcion - 1];

    // Pedir al usuario que seleccione la edad
    printf("\nIngresa edad");
    scanf("%d", &age_elem);

    // Pedir al usuario que seleccione una genero
    opcion;
    printf("Seleccione el genero:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, generos[i]);
    }
    scanf("%d", &opcion);
    char *gender_elem= generos[opcion - 1];

    // Pedir al usuario que ingrese sueldo
    printf("\nIngresa sueldo");
    scanf("%d", &income_elem);

    // Pedir al usuario que seleccione si está enfermo
    opcion;
    printf("Seleccione si está enfermo:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, illness[i]);
    }
    scanf("%d", &opcion);
    char *illness_elem= illness[opcion - 1];


/*
    for (int i=150001; i==75000; i--){
        items[i].id = items[i].id;
        items[i].age = items[i-1].age;
        items[i].city = items[i-1].city;
        items[i].gender = items[i-1].gender;
        items[i].illness= items[i-1].illness;
        items[i].income= items[i-1].income;

        
        //items[i-1].age = 0;
        //items[i-1].city = "";
        //items[i-1].gender= "";
        //items[i-1].illness= "";
        //items[i-1].income= 0;
    }

    city_t result_city;
	gender_t result_gender;
	bool_t result_illness;

    items[75000].age = age_elem;
    items[75000].city= result_city= get_city_t(city_elem);
    items[75000].gender= result_gender=get_gender_t(gender_elem);
    items[75000].illness= result_illness=get_illness_t(illness_elem);
    items[75000].income=income_elem;
    
    
    printf("Dato insertado correctamente\n");
    fprintf(fp, "Dato insertado correctamente\n");

    fin1=clock();
    tiempo1=(double)(fin1 - inicio1)/ CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución para el Numeral 5 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 5 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);

}
*/

void report_by_city_age_v(item_t *items, size_t num_items, int edad_consulta)
{   
    inicio1=clock();
    FILE *fp = fopen(name_report "a");
    
    int count_p[9]={0};

    
    for(int i=0; i < num_items; i++){
        if(strcmp(city_names[items[i].city],"Dallas")==0){
            if(items[i].age == edad_consulta){
                count_p[0]++;
            }	
        }
        if(strcmp(city_names[items[i].city],"New York City")==0){
            if(items[i].age == edad_consulta){
                count_p[1]++;		
            }
        }
        if(strcmp(city_names[items[i].city],"Los Angeles")==0){
            if(items[i].age == edad_consulta){
                count_p[2]++;
            }
        }
        if(strcmp(city_names[items[i].city],"Mountain View")==0){
            if(items[i].age == edad_consulta){
                count_p[3]++;
            }
        }
        if(strcmp(city_names[items[i].city], "Boston")==0){
            if(items[i].age == edad_consulta){
                count_p[4]++;
            }
        }
        if(strcmp(city_names[items[i].city],"Washington D.C.")==0){
            if(items[i].age == edad_consulta){
                count_p[5]++;
            }
        }
        if(strcmp(city_names[items[i].city],"San Diego")==0){
            if(items[i].age == edad_consulta){
                count_p[6]++;
            }
        }
        if(strcmp(city_names[items[i].city],"Austin")==0){
            if(items[i].age == edad_consulta){
                count_p[7]++;
            }
        }
        if(strcmp(city_names[items[i].city],"Not found")==0){
            if(items[i].age == edad_consulta){
                count_p[8]++;
            }
        }
    }
    printf("La cantidad de personas por ciudad en la edad de: %d\n", edad_consulta );
    printf("Dallas %d\n", count_p[0]);
    printf("New York City %d\n", count_p[1]);
    printf("Los Angeles %d\n", count_p[2]);
    printf("Mountain View %d\n", count_p[3]);
    printf("Boston %d\n", count_p[4]);
    printf("Washington D.C. %d", count_p[5]);
    printf("San Diego %d\n", count_p[6]);
    printf("Austin %d\n", count_p[7]);
    printf("Not found %d\n", count_p[8]);

    fprintf(fp, "La cantidad de personas por ciudad en la edad de: %d\n", edad_consulta );
    fprintf(fp, "Dallas %d\n", count_p[0]);
    fprintf(fp, "New York City %d\n", count_p[1]);
    fprintf(fp, "Los Angeles %d\n", count_p[2]);
    fprintf(fp, "Mountain View %d\n", count_p[3]);
    fprintf(fp, "Boston %d\n", count_p[4]);
    fprintf(fp, "Washington D.C. %d\n", count_p[5]);
    fprintf(fp, "San Diego %d\n", count_p[6]);
    fprintf(fp, "Austin %d\n", count_p[7]);
    fprintf(fp, "Not found %d\n", count_p[8]);

    fin1=clock();
    tiempo1=(double)(fin1 - inicio1)/ CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución para el Numeral 6 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 6 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);
}