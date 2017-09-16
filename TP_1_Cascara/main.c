#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int A,B,resultado;
    int flagA = 0;
    int flagB = 0;

    while(seguir=='s') {
        system("cls");
        printf("###################################\n");
        printf("        TP1: Calculadora 1B\n");
        printf("###################################\n");

        if (flagA == 0) {
                printf("1- Ingresar 1er operando (A=x)\n");
        }
        else {
            printf("1- Ingresar 1er operando (A=%d)\n", A);
        }
        if (flagB == 0) {
                printf("2- Ingresar 2do operando (B=y)\n");
        }
        else {
            printf("2- Ingresar 2do operando (B=%d)\n", B);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d", &A);
                flagA = 1;
                break;
            case 2:
                printf("Ingrese un numero: ");
                scanf("%d", &B);
                flagB = 1;
                break;
            case 3:
                resultado = sumar(A,B);
                printf("La suma de los numeros es: %d\n", resultado);
                system("pause");
                break;
            case 4:
                resultado = restar(A,B);
                printf("La resta de los numeros es: %d\n", resultado);
                system("pause");
                break;
            case 5:
                if (B == 0) {
                    printf("No es posible dividir por 0, reingrese otro numero B\n");
                    system("pause");
                }
                else {
                    resultado = dividir(A,B);
                printf("La division de los numeros es: %d\n", resultado);
                system("pause");
                }
                break;
            case 6:
                resultado = multiplicar(A,B);
                printf("La multiplicacion de los numeros es: %d\n", resultado);
                system("pause");
                break;
            case 7:
                resultado = factorial(A);
                printf("El factorial del numero es: %d\n", resultado);
                system("pause");
                break;
            case 8:
                resultado = sumar(A,B);
                printf("La suma de los numeros es: %d\n", resultado);
                resultado = restar(A,B);
                printf("La resta de los numeros es: %d\n", resultado);
                if (B == 0) {
                    printf("No es posible dividir por 0, reingrese otro numero B\n");
                }
                else {
                    resultado = dividir(A,B);
                    printf("La division de los numeros es: %d\n", resultado);
                }
                resultado = multiplicar(A,B);
                printf("La multiplicacion de los numeros es: %d\n", resultado);
                resultado = factorial(A);
                printf("El factorial del numero es: %d\n", resultado);
                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
