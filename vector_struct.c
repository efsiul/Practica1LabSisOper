#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include "base_struct.h"

clock_t inicio1, fin1;
double tiempo1;

// Función para generar un reporte de la cantidad de personas por cada ciudad
void report_by_city_v(item_t *items, size_t num_items)
{   
    inicio1=clock();
    FILE *fp = fopen("reporte.txt", "a");
    
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
    FILE *fp = fopen("reporte.txt", "a");

    
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
    FILE *fp = fopen("reporte.txt", "a");
    
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
    FILE *fp = fopen("reporte.txt", "a");


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

// Insertar un nuevo elemento en la mitad
void inser_in_half_v(item_t *items, size_t num_items)
{   
    inicio1=clock();
    FILE *fp = fopen("reporte.txt", "a");

    char city_elem;
    char gender_elem;
    unsigned int age_elem;
    char illness_elem;
    int income_elem;

    printf("\nIngresa nuevo elemento");

    printf("\nIngrese ciudad");
        scanf("%s", &city_elem);
    printf("\nIngresa genero");
        scanf("%s", &gender_elem);
    printf("\nIngresa edad");
        scanf("%d", &age_elem);
    printf("\nIngresa enfermo?");
        scanf("%s", &illness_elem);
    printf("\nIngresa sueldo");
        scanf("%d", &income_elem);

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
    items[75000].city= result_city= get_city_t(&city_elem);
    items[75000].gender= result_gender=get_gender_t(&gender_elem);
    items[75000].illness= result_illness=get_illness_t(&illness_elem);
    items[75000].income=income_elem;

    printf("Dato insertado correctamente\n");
    fprintf(fp, "Dato insertado correctamente\n");

    fin1=clock();
    tiempo1=(double)(fin1 - inicio1)/ CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecución para el Numeral 5 - Vector, es de: %.9f segundos.\n", tiempo1);
    fprintf(fp, "Tiempo de ejecución para el Numeral 5 - Vector, es de: %.9f segundos.\n----------------------------------------------------\n", tiempo1);

    fclose(fp);

}

void report_by_city_age_v(item_t *items, size_t num_items, int edad_consulta)
{   
    inicio1=clock();
    FILE *fp = fopen("reporte.txt", "a");
    
    int count_p[9]={0};

    
        for(int i=0; i=num_items; i++){
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