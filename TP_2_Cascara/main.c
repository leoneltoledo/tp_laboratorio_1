#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main() {
    char seguir='s';
    int opcion=0;
    ePersona listaPersonas[20];
    inicializarEstados(listaPersonas, TAM);

    while(seguir=='s') {
        system("cls");
        printf("###################################\n");
        printf("      TP2 -- Leonel Toledo 1B\n");
        printf("###################################\n");

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                agregarPersona(listaPersonas, TAM);
                system("pause");
                break;
            case 2:
                borrarPersona(listaPersonas, TAM);
                system("pause");
                break;
            case 3:
                ordenarPersonas(listaPersonas, TAM);
                mostrarPersonas(listaPersonas, TAM);
                system("pause");
                break;
            case 4:
                graficoPersonas(listaPersonas, TAM);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
