#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "linkedlist.h"
#include "base_struct.h"
#include "menu.h"

const int SIZE = 150000;

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 0;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	// Creación de la estructura
	item_t element;

	// Creación de la LL
	linked_list_t list;
	init_list(&list);

	// Creación del vector
	item_t items[SIZE];
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line_number > 0)
		{
			char *token;
			char *s = NULL;
			int i = 0;
			while ((token = strtok_r(line, ",", &line)))
			{
				city_t result_city;
				gender_t result_gender;
				bool_t result_illness;
				switch (i)
				{
				case 0:
					element.id = atoi(token);
					break;
				case 1:
					result_city = get_city_t(token);
					if (result_city == E)
						printf("City not defined\n");
					element.city = result_city;
					break;
				case 2:
					result_gender = get_gender_t(token);
					if (result_gender == NO)
						printf("Gender not defined\n");
					element.gender = result_gender;
					break;
				case 3:
					element.age = atoi(token);
					break;
				case 4:
					element.income = atoi(token);
					break;
				case 5:
					s = token;
					while (*s != '\n')
					{
						++s;
					}
					*s = '\0';
					result_illness = get_illness_t(token);
					if (result_illness == fuzzy)
						printf("Value not defined\n");
					element.illness = result_illness;
					break;
				}
				i++;
			}
			// Una vez estraído el elemento del dataset, y haberlo construido en un nueva estructura, lo guardamos en el vector y la LL
			items[line_number - 1] = element; // Vector

			append_node(&list, element); // LL
		}
		line = NULL;
		line_number++;
	}
	
	/*
	//Si deseo imprimir todo el vector
	
	for (int i = 0; i < SIZE; i++) {
  	printf("Imprimiendo el sujeto:%d\n", i+1);
	printf("id= %d\n", items[i].id);
	printf("city= %s\n", city_names[items[i].city]);
	printf("Gender= %s\n", gender_names[items[i].gender]);
	printf("Age = %d\n", items[i].age);
	printf("Income %d\n", items[i].income);
	printf("Illness = %s\n", illness_values[items[i].illness]);
	printf("-----------------------------------------------------\n\n");
	}
	*/
	
	//Si deseo imprimir toda la ListaL
	//print_list(&list);
	
	//INTRODUCCIÓN AL MENÚ DE OPCIONES
	int opcion;
	char *submenu = malloc(12);
	size_t num_items = sizeof(items) / sizeof(element);//En caso de recalcular el tamaño del vector
	
	do{
		printf("     MENU PRINCIPAL\n"\
		"\n"\
		"################################\n"\
		"#    SELECCIONE UNA OPCIÓN     #\n"\
		"################################\n"
		"\n");
		printf("1. Menu para trabajar con Vectores \n");
		printf("2. Menu para trabajar con Listas Ligadas \n");
		printf("3. SALIR \n");

		scanf("%d", &opcion);
		if (opcion==1){
			strcpy(submenu, "Vectores");
		}
		else{
			strcpy(submenu, "ListaLigada");
		}

		switch (opcion)
		{
			
			case 1:
				printf("\n"\
				"####################################\n"\
				"#           MENU VECTORES          #\n"\
				"####################################\n"\
				"\n"\
				);
				selectMenu(submenu, items, num_items);
				break;
			case 2:
				printf("\n"\
				"####################################\n"\
				"#        MENU LISTAS LIGADAS       #\n"\
				"####################################\n"\
				"\n"\
				);
				selectMenu(submenu, items, num_items);
				break;
			case 3:
				printf("Saliendo del programa...\n");
				break;
			default:
				printf("ERROR. Opcion Inválida\n");
		}
	}while (opcion != 3);
		
			fclose(fp);
			if (line)
				free(line);
			exit(EXIT_SUCCESS);
}
