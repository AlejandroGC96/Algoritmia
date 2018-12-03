//
// Created by alex_ on 03/12/2018.
//

#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "casting.h"


void init(actores actor[], int tam) {

    int i = 0;

    for (; i < tam; i++) {

        actor[i].nombre = malloc(150 * sizeof(int));
        actor[i].apellidos = malloc(150 * sizeof(int));
        actor[i].estado = FREE;


    }


}

void leer_casting(actores actor[], int tam) {


    char linea[tam]; // Para guardar la linea de cada fichero
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

            token = strtok(NULL, ";");

            i++;
        }
        printf("%s %s \n", actoractual.nombre, actoractual.apellidos);
        int intentos = 0;
        for (; intentos < tam; intentos++) {


            if (actor[intentos].estado == FREE || actor[intentos].estado == DELETED) {
                actor[intentos] = actoractual;

            }
        }

    }
}
