#ifndef FUNCIONES_C
#define FUNCIONES_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void ordenarPersonas(ePersona lista[], int tam) {
    int i, j;
    ePersona auxPersona;

    for(i=0; i<tam-1; i++) {
        for(j=i+1; j<tam; j++) {
                if(stricmp(lista[i].nombre, lista[j].nombre)>0) {
                    auxPersona=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxPersona;
                }
        }
    }
}

void mostrarPersonas(ePersona lista[], int tam) {
    int i;
    for(i=0; i<tam; i++) {
        if(lista[i].estado==1) {
            printf("%s -- %d -- %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
}

void inicializarEstados(ePersona lista[], int tam) {
    int i;

    for(i=0; i<tam; i++) {
        lista[i].estado = 0;
    }
}

void graficoPersonas(ePersona lista[], int tam) {
    int menores = 0;
    int mayores = 0;
    int viejos = 0;
    int i;
    int mayor=0;
    int flag=0;

    for(i=0;i<tam;i++) {
        if(lista[i].estado == 1) {
            if(lista[i].edad < 18 ) {
            menores++;
            }
            if(lista[i].edad > 17 && lista[i].edad < 36) {
                    mayores++;
            }
            if(lista[i].edad > 35) {
                        viejos++;
            }
        }
    }

    if(menores > mayores && menores > viejos) {
        mayor = menores;
    }
    else {
        if( mayores > menores && mayores >= viejos) {
            mayor = mayores;
        }
        else {
            mayor = viejos;
        }
    }

    for(i=mayor; i>0; i--) {
        if(i<=menores) {
            printf("*");
        }
        if(i<=mayores) {
            flag=1;
            printf("\t*");
        }
        if(i<=viejos) {
            if(flag==0) {
                printf("\t\t*");
            }
            if(flag==1) {
                printf("\t*");
            }
        }

        printf("\n");
    }
    printf("<18\t18-35\t>35\n");

}


#endif // FUNCIONES_C
