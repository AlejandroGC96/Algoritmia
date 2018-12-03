#include <stdio.h>
#include "grafos.h"
#include "casting.h"

int main() {

    int opcion=0;
    actores actor[10];


    do {
        printf("####Backtracking####\n");
        printf("1.Ejercicio 1\n");
        printf("2.Ejercicio 2\n");
        printf("3.Salir\n");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                iniciar();
                break;
            case 2:
                init(actor, 10);
                leer_casting(actor, 10);
                break;
            case 3:
                break;


            default:
                break;
        }

    }while(opcion!=3);
    return 0;
}