#ifndef FUNCIONES_C
#define FUNCIONES_C
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20

void agregarPersona(ePersona lista[], int tam) {
    int i;
    for(i=0;i<TAM;i++) {
            if(lista[i].estado==0) {
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(lista[i].nombre);
                printf("Ingrese edad: ");
                scanf("%d", &lista[i].edad);
                printf("Ingrese dni: ");
                scanf("%d", &lista[i].dni);

                lista[i].estado = 1;

                break;
            }
    }
}

void borrarPersona(ePersona lista[], int tam) {
    int i;
    int dni;
    char seguir;

    printf("Ingrese el dni: ");
    scanf("%d", &dni);

    for(i=0;i<tam;i++) {
        if (lista[i].dni == dni) {
            printf("%s--%d--%d\n", lista[i].nombre, lista[i].dni, lista[i].edad);

            printf("Desea eliminar la persona? (s/n)\n");
            fflush(stdin);
            scanf("%c", &seguir);

            if(seguir == 's') {
                lista[i].estado = 0;
            }
            else {
                printf("No se elimino a la persona\n");
            }

        }
    }
}


#endif // FUNCIONES_C
