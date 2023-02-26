#include <stdio.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "base_struct.h"
#include "linkedlist.h"

clock_t inicio, fin;
double tiempo;
char reporte[1000];



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



