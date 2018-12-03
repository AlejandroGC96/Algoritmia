//
// Created by alex_ on 30/11/2018.
//

#include "grafos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define VERDE 0
#define ROJO 1
#define AZUL 2
#define AMARILLO 3
#define  NEGRO 4

int alcanzable(int *solucion, int etapa,int tamano_grafo, int grafo[tamano_grafo][tamano_grafo]) {


    for(int i=0; i< etapa; i++){

        if(grafo[etapa][i]==1){

            if(solucion[etapa] == solucion[i]){

                return 0;
            }

        }


    }

    return 1;

}

void procesarSolucion(int solucion[],int etapa){

    for(int i=0; i<etapa; i++){
        printf(" %d ",solucion[i]);

    }

}

int GrafoRec(int *solucion, int etapa, int tamano_grafo, int tamano_colores, int grafo[tamano_grafo][tamano_grafo]){

    int exito=0;
    if(etapa>tamano_grafo-1)return exito;

    int valor_actual = 0; // valor_actual = 0, primer color seleccionable

    for(valor_actual ; valor_actual<=tamano_colores; valor_actual++){

        solucion[etapa]=valor_actual;

            if ((alcanzable(&solucion[tamano_grafo], etapa,tamano_grafo ,grafo))==1){
            if(etapa==tamano_grafo-1){
                printf("Solucion: ");
                procesarSolucion(&solucion[tamano_grafo],etapa);
                exito=1;
                return exito;
            }else{

               exito = GrafoRec(&solucion[tamano_grafo], etapa+1, tamano_grafo, tamano_colores, grafo);
            }

        }

    }

    solucion[etapa]= -1;
    return  exito;
}


void iniciar(){

    int x, y=0;
    int tamano_grafo=0;
    int tamano_colores=0;
    char buffer[25];
    char *nombre_fichero;
    char *token;
    int etapa=0;



    nombre_fichero = (char*)malloc( 50 * sizeof(char) );
    //    printf("Elige el fichero que indique el tamaño de los nodos que va a tener tu grafo(2-5):\n");
    //  gets(nombre_fichero);

    FILE *fp;
    fp = fopen("GrafoPrueba.txt", "r"); // read mode

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        return;
    }

    printf("The contents of %s file are:\n", nombre_fichero);

    fscanf (fp, "%d", &tamano_grafo);
    int grafo[tamano_grafo][tamano_grafo];
    int solucion[tamano_grafo];
    fscanf(fp, "%c", buffer);

    for(x=0;x<tamano_grafo;x++) {
        fgets(buffer, 250, fp);
        buffer[strcspn(buffer, "\n")] = 0;
            token = strtok(buffer, ",");
            y=0;
            while (token != NULL) {
                grafo[x][y] =  atoi(token);
                token = strtok(NULL, ",");
                y++;
            }

    }

    fclose(fp);


    for(int i=0; i<tamano_grafo;i++){

        for (int j = 0; j <tamano_grafo ; ++j) {
            printf("%d ",grafo[i][j]);

        }
        printf("\n");
    }


    fflush(stdin);
    printf("Elige la cantidad de colores que quieres(2-5):\n");
    scanf("%d", &tamano_colores);
    fflush(stdin);

    // Inciamos el array de soluciones a -1
    for(int i=0;i<tamano_grafo;i++){
        solucion[i]=-1;
    }


    GrafoRec(&solucion[tamano_grafo], etapa, tamano_grafo, tamano_colores,  grafo);




}




