#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


int menu() {
int condicion;
  do{
        system("cls");
        printf("**********************************************\n");
        printf("\t\tMENU PRINCIPAL\n");
        printf("**********************************************\n");
        printf("\n1. Insertar datos del fichero en tabla-Prueba lineal");
        printf("\n2. Insertar datos del fichero en tabla-Prueba dependiente de clave");
        printf("\n3. alternativaaaa");
        printf("\n4. Comparacióm Empírica\n");
        printf("\n5. Salir\n");
        printf("\nEscoger opcion\n");
        fflush(stdin);
        scanf("%d", &condicion);

        switch (condicion){
            case 1:
                printf("hola");
                break;
            case 2:
                printf("hola");
                break;
            case 3:
                printf("hola");
                break;
            case 4:
                printf("hola");
                break;
            default:
                break;
        }
    }while(condicion!=5);
    system("pause");
    return (EXIT_SUCCESS);


}

int leerFichero(char *nombre_fichero) {

    char linea[500]; // Para guardar la linea de cada fichero
    char *token;     // Para cada token de cada linea

    //Abrimos el fichero
    FILE *fp = fopen(nombre_fichero,"r");

    // Comprobar que no hay error al abrir
    if(fp == NULL){
            printf("Error de lectura del archivo");
            return -1;
    }

    // Recorremos cada linea del fichero
    while(fgets(linea,500,fp)!=NULL){
           printf("Linea leida: %s\n", linea);
           token = strtok(linea,";"); // Separamos cada linea por ","
           while (token != NULL){
                 printf("%s\n",token);
                 token = strtok(NULL, ";");  // Siguiente token en la linea (si quedan)
           }
           system("PAUSE");     // COMENTAR PARA EJECUCION REAL
    }
    return 0;
}

medir_tiempo() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    // code to be measured

    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("%f\n", interval);

    return 0;

}


int main(int argc, char *argv[])
{
menu();
  leerFichero("listaActores.csv");
  system("PAUSE");
  return 0;
}
