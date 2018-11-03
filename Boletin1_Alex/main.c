#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"

#define TAM 500

int main() {
    int opcion = 0;


    actores actor[TAM];
    init(actor, TAM);



    // eliminar(actor, 10, TAM);
    // int pos= buscar(actor,11,TAM);
    //printf("El valor 11 esta en la pos %d de la tabla\n",pos);

    do {

        printf("###Menu###\n");
        printf("1. Cargar datos del fichero prueba lineal\n");
        printf("2. Cargar datos del fichero prueba dependiente de clave\n");
        printf("3. Punto 3\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion) {

            case 1:

                iniciar(actor, TAM);
                show(actor, TAM);
                system("PAUSE");
                system("cls");
                break;

            case 2:
                break;

            case 3:
                break;

            default:
                break;


        }


    } while (opcion != 4);


    return 0;
}
