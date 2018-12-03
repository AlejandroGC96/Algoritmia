//
// Created by alex_ on 03/12/2018.
//

#ifndef BOLETIN2_CASTING_H
#define BOLETIN2_CASTING_H

#define FREE -1
#define DELETED -2
#define BUSY 1

typedef struct actor {

    char *apellidos;
    char *nombre;
    int edad;
    char goya;
    long int cache;
    int estado;

} actores;


void init(actores actor[], int tam);
void leer_casting(actores actor[], int tam);





#endif //BOLETIN2_CASTING_H
