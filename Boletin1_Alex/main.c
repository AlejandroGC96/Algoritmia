#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"

#define TAM 500
#define TAM2 512 //Necesario para asegurar el recorrido completo

int main() {

    actores actor[TAM];
    actores actor2[TAM2];

    init(actor, TAM);//Iniciarmos el array vacio
    init(actor2, TAM2);
    char *nombre;
    char *apellidos;
    int posicion=0;
    int opcion = 0;

    nombre=malloc(150* sizeof(char));
    apellidos=malloc(150* sizeof(char));

    do {

        printf("###Menu###\n");
        printf("1. Cargar datos del fichero prueba lineal\n");
        printf("2. Cargar datos del fichero prueba dependiente de clave\n");
        printf("3. Buscar datos de la tabla insertada de manera lineal\n");
        printf("4. Buscar datos de la tabla insertada depiendo de la clave\n");
        printf("5. Eliminar datos de la tabla insertada de manera lineal\n");
        printf("6. Eliminar datos de la tabla insertada dependiendo de la clave\n");
        printf("7. Ver datos de la tabla insertada dependiendo de la clave\n");
        printf("8. Ver datos de la tabla insertada de manera lineal\n");
        printf("9. Punto 3\n");
        printf("10. Salir\n");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion) {

            case 1:

                iniciar(actor, TAM);
                system("PAUSE");
                system("cls");
                break;

            case 2:

                iniciar_dependiente_clave(actor2, TAM2);
                system("PAUSE");
                system("cls");
                break;

            case 3:

                printf("Nombre del actor a buscar\n");
                scanf("%s",nombre);
                fflush(stdin);
                printf("Introduce el apellido del actor\n");
                scanf("%s",apellidos);
                fflush(stdin);
                posicion=buscar(actor,strlen(nombre)+strlen(apellidos),TAM, nombre, apellidos);

                if(posicion==-1){

                    break;

                }else{


                    printf(" \nNombre: %s\n Apellidos: %s\n Edad: %d\n Goya: %c\n Cache: %ld\n",
                            actor[posicion].nombre, actor[posicion].apellidos, actor[posicion].edad, actor[posicion].goya, actor[posicion].cache);


                }


                break;

            case 4:

                printf("Nombre del actor a buscar\n");
                scanf("%s",nombre);
                fflush(stdin);
                printf("Introduce el apellido del actor\n");
                scanf("%s",apellidos);
                fflush(stdin);
                posicion=buscar_pediente_clave(actor2,strlen(nombre)+strlen(apellidos),TAM2, nombre, apellidos);

                if(posicion==-1){

                    break;

                }else{


                    printf(" \nNombre: %s\n Apellidos: %s\n Edad: %d\n Goya: %c\n Cache: %ld\n",
                           actor2[posicion].nombre, actor2[posicion].apellidos, actor2[posicion].edad, actor2[posicion].goya, actor2[posicion].cache);


                }

                break;

            case 5:
                printf("Nombre del actor a eliminar\n");
                scanf("%s",nombre);
                fflush(stdin);
                printf("Introduce el apellido del actor\n");
                scanf("%s",apellidos);
                fflush(stdin);
                eliminar(actor,strlen(nombre)+strlen(apellidos),TAM, nombre, apellidos);
                break;


            case 6:
                printf("Nombre del actor a eliminar\n");
                scanf("%s",nombre);
                fflush(stdin);
                printf("Introduce el apellido del actor\n");
                scanf("%s",apellidos);
                fflush(stdin);
                eliminar_pendiente_clave(actor2,strlen(nombre)+strlen(apellidos),TAM2, nombre, apellidos);

                break;

            case 7:
                show(actor2, TAM);

                break;

            case 8:
                show(actor, TAM);

                break;
            case 9:

                break;
            default:
                break;


        }


    } while (opcion != 10);


    return 0;
}
