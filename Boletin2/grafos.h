//
// Created by alex_ on 30/11/2018.
//

#ifndef BOLETIN2_GRAFOS_H
#define BOLETIN2_GRAFOS_H

int alcanzable(int *solucion, int etapa,int tamano_grafo, int grafo[tamano_grafo][tamano_grafo]);
void procesarSolucion(int solucion[],int etapa);
void traducir_solucion(int solucion[], int etapa);
int GrafoRec(int *solucion, int etapa, int tamano_grafo, int tamano_colores, int grafo[tamano_grafo][tamano_grafo]);
void iniciar();


#endif //BOLETIN2_GRAFOS_H
