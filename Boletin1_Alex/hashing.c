//
// Created by alex_ on 03/11/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"
#include <windows.h>

void init(actores actor[], int tam) {

    int i = 0;

    for (; i < tam; i++) {

        actor[i].nombre = malloc(150 * sizeof(int));
        actor[i].apellidos = malloc(150 * sizeof(int));
        actor[i].estado = FREE;


    }


}

int H(int id, int intentos, int tam) {


//H(k)=k mod n
//G(k,i)=(H(k)+i)mod n ->i numero de intentos

    return ((id + intentos) % tam);

}

int H_dependiente_clave(int id, int intentos, int tam) {


//H(k)=k mod n
//G(k,i)=(H(k)+d*i)mod n ->i numero de intentos
int valor= id%tam;
if( valor % 2 == 0){        //Asi obtenemos que el numero sea impar para asegurar un recorrido completo

    valor++;

}

    return ((id % tam) + valor * intentos) % tam;

}


void iniciar(actores actor[], int tam) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;
    char linea[tam]; // Para guardar la linea de cada fichero
    char *token;
    int colisiones_totales=0;
    actores actoractual;

    //Abrimos el fichero
    FILE *fp = fopen("listaActores.csv", "r");

    // Comprobar que no hay error al abrir
    if (fp == NULL) {
        printf("Error de lectura del archivo");
    }

    // Recorremos cada linea del fichero
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    while (fgets(linea, 500, fp) != NULL) {
        actoractual.nombre = malloc(150 * sizeof(char));
        actoractual.apellidos = malloc(150 * sizeof(char));
        // printf("Linea leida: %s\n", linea);
        token = strtok(linea, ";");// Separamos cada linea por ","
        int i = 0;
        while (token != NULL) {

            if (i == 0) {

                strcpy(actoractual.apellidos, token);

            }

            if (i == 1) {

                strcpy(actoractual.nombre, token);

            }

            if (i == 2) {

                actoractual.edad = atoi(token);
            }
            if (i == 3) {

                actoractual.goya = token[0];

            }

            if (i == 4) {

                actoractual.cache = atoi(token);
                actoractual.estado = BUSY;

            }

            token = strtok(NULL, ";");

            i++;
        }
        printf("%s %s \n", actoractual.nombre, actoractual.apellidos);
        int intentos = 0;

        for (; intentos < tam; intentos++) {

            int pos;

            pos = H(strlen(actoractual.nombre)+strlen(actoractual.apellidos), intentos, tam);

            if (actor[pos].estado == FREE || actor[pos].estado == DELETED) {

                actor[pos] = actoractual;
                printf("Numero de colisiones: %d\n", intentos);
                printf("El factor de carga de la tabla es del %0.2f%% \n",(factorcarga(actor,tam))*100);
                printf("/*******************************/\n");


                break;

            }
            colisiones_totales++;
        }

    }
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("TIEMPO TRANSCURRIDO: %f\n", interval);
    printf("COLISIONES TOTALES: %d\n",colisiones_totales);

}
void iniciar_dependiente_clave(actores actor[], int tam) {

    char linea[500]; // Para guardar la linea de cada fichero
    char *token;
    actores actoractual;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;
    int colisiones_totales=0;

    //Abrimos el fichero
    FILE *fp = fopen("listaActores.csv", "r");

    // Comprobar que no hay error al abrir
    if (fp == NULL) {
        printf("Error de lectura del archivo");
    }

    // Recorremos cada linea del fichero

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    while (fgets(linea, 500, fp) != NULL) {
        actoractual.nombre = malloc(150 * sizeof(char));
        actoractual.apellidos = malloc(150 * sizeof(char));
        // printf("Linea leida: %s\n", linea);
        token = strtok(linea, ";");// Separamos cada linea por ","
        int i = 0;
        while (token != NULL) {

            if (i == 0) {

                strcpy(actoractual.apellidos, token);

            }

            if (i == 1) {

                strcpy(actoractual.nombre, token);

            }

            if (i == 2) {

                actoractual.edad = atoi(token);
            }
            if (i == 3) {

                actoractual.goya = token[0];

            }

            if (i == 4) {

                actoractual.cache = atoi(token);
                actoractual.estado = BUSY;

            }

            token = strtok(NULL, ";");

            i++;
        }
        printf("%s %s \n", actoractual.nombre, actoractual.apellidos);
        int intentos = 0;

        for (; intentos < tam; intentos++) {

            int pos;

            pos = H_dependiente_clave(strlen(actoractual.nombre)+strlen(actoractual.apellidos), intentos, tam);

            if (actor[pos].estado == FREE || actor[pos].estado == DELETED) {

                actor[pos] = actoractual;
                printf("Numero de colisiones: %d\n", intentos);
                printf("El factor de carga de la tabla es del %0.2f%% \n",(factorcarga(actor,tam))*100);
                printf("/*******************************/\n");


                break;

            }
            colisiones_totales++;
        }

    }
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("TIEMPO TRANSCURRIDO: %f\n", interval);
    printf("COLISIONES TOTALES: %d\n", colisiones_totales);


}

int buscar(actores actor[], int id, int tam, char* nombre, char* apellidos) {

    int pos;
    int intentos=0;

    for(; intentos<tam ; intentos++)
    {
        pos = H(id, intentos, tam);


        if (actor[pos].estado == FREE) {
            printf("No existe\n");
            return -1;// NO EXISTE
        }
        if (strlen(actor[pos].nombre)+strlen(actor[pos].apellidos) == id && strcmp(actor[pos].nombre, nombre)==0 && strcmp(actor[pos].apellidos,apellidos)==0) {

            printf("Encontrado\n");
            printf("Numero de busquedas: %d\n", intentos);
            return pos;

        }
    }
    printf("No econtrado. Numero de busquedas: %d\n", intentos);
    return -1;
}

int buscar_pediente_clave(actores actor[], int id, int tam, char* nombre, char* apellidos) {

    int pos;
    int intentos=0;

    for(intentos; intentos<512 ; intentos++)
    {
        pos = H_dependiente_clave(id, intentos, tam);


        if (actor[pos].estado == FREE) {
            printf("No existe\n");
            return -1;// NO EXISTE
        }
        if (strlen(actor[pos].nombre)+strlen(actor[pos].apellidos) == id && strcmp(actor[pos].nombre, nombre)==0 && strcmp(actor[pos].apellidos,apellidos)==0 ) {

            printf("Encontrado\n");
            printf("Numero de busquedas: %d\n", intentos);
            return pos;
        }

    }
    printf("No econtrado. Numero de busquedas: %d\n", intentos);
    return -1;
}

int eliminar(actores actor[], int id,int tam, char* nombre, char* apellidos) {
    int pos;
    pos = buscar(actor, id, tam, nombre, apellidos);

    if (pos != -1) {

        actor[pos].estado = DELETED;
        printf("El factor de carga de la tabla es del %0.2f%% \n",(factorcarga(actor,tam))*100);

        return 1;

    } else
        return 0;
}
int eliminar_pendiente_clave(actores actor[], int id,int tam, char* nombre, char* apellidos) {
    int pos;
    pos = buscar_pediente_clave(actor, id, tam, nombre, apellidos);

    if (pos != -1) {

        actor[pos].estado = DELETED;
        printf("El factor de carga de la tabla es del %0.2f%% \n",(factorcarga(actor,tam))*100);

        return 1;

    } else
        return 0;
}

float factorcarga(actores actor[], int tam) {

    int n_ocupadas = 0;
    int i;
    for (i = 0; i < tam; i++) {

        if (actor[i].estado != DELETED && actor[i].estado != FREE) {
            n_ocupadas++;
        }
    }
    return ((float) n_ocupadas / tam);

}


void show(actores actor[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if(actor[i].estado == BUSY) {
            printf("\n%d. %s %s  ", i + 1, actor[i].nombre, actor[i].apellidos);
        }
    }
    printf("\n");


}