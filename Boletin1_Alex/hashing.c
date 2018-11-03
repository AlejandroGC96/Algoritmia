//
// Created by alex_ on 03/11/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"

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


void iniciar(actores actor[], int tam) {

    char linea[500]; // Para guardar la linea de cada fichero
    char *token;
    actores actoractual;

    //Abrimos el fichero
    FILE *fp = fopen("listaActores.csv", "r");

    // Comprobar que no hay error al abrir
    if (fp == NULL) {
        printf("Error de lectura del archivo");
    }

    // Recorremos cada linea del fichero
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

            // printf("%s\n",token);
            token = strtok(NULL, ";");

            i++;
        }
        int intentos = 0;

        for (; intentos < 500; intentos++) {

            int pos;

            pos = H(actoractual.edad, intentos, tam);

            if (actor[pos].estado == FREE || actor[pos].estado == DELETED) {

                actor[pos] = actoractual;

                break;

            } else {

                //  printf("Colision Numero:%d\n",intentos+1);


            }
        }

    }

}

int buscar(actores actor[], int id, int intentos, int tam) {

    int pos;

    pos = H(id, intentos, tam);


    if (actor[pos].estado == FREE)
        return -1;//PUTA MIERDA NO EXISTE

    if (actor[pos].estado == id)
        return pos;
    else {

        printf("Colision");
        return -1; //Cambiar comvenientemente segun tu estrategia

    }


}

int eliminar(actores actor[], int id, int intentos, int tam) {
    int pos;
    pos = buscar(actor, id, intentos, tam);

    if (pos != -1) {

        actor[pos].estado = DELETED;
        return 1;

    } else
        return 0;
}

float factorcarga(actores actor[], int tam) {

    int n_ocupadas = 0;
    int i;
    for (i = 0; i < tam; i++) {

        if (actor[i].estado != DELETED && actor[i].estado != FREE) {
            i++;
        }
    }
    return ((float) n_ocupadas / tam);

}


void show(actores actor[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {


        printf("\n%s %s numero:%d ", actor[i].nombre, actor[i].apellidos, i+1);

    }
    printf("\n");


}