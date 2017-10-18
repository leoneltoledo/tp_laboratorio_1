#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>
#include "funciones.h"
#define TAM 15


int main()
{
    eMovie movies[TAM];
    char nombre[15];
    char seguir = 's';
    char guardar = 's';
    int opcion = 0;

    inicializarEstados(movies);

    if(cargarArchivo(movies)) {
		printf("No se pudo abrir el fichero\n");
	}
	else {
		printf("Se cargaron las estructuras con exito\n");
	}

    system("pause");

    while(seguir=='s') {
        system("cls");
        printf("###################################\n");
        printf("      TP3 -- Leonel Toledo 1B\n");
        printf("###################################\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(movies);
                break;
            case 2:
                system("cls");
                borrarPelicula(movies);
                break;
            case 3:
                system("cls");
                modificarPelicula(movies);
                break;
            case 4:
                system("cls");
                printf("Ingrese el nombre del archivo: \n");
                fflush(stdin);
                gets(nombre);

                generarPagina(movies, nombre);
                system("pause");
                break;
            case 5:
                system("cls");
                printf("Guardar cambios?: (s/n)\n");
                scanf(" %c", &guardar);

				if(guardar=='s') {
					if(guardarArchivo(movies)) {
						printf("\nNo se pudo abrir el fichero\n");
						system("pause");
					}
					else {
						printf("\nSe guardo la informacion con exito\n");
						system("pause");
					}
				}

                seguir = 'n';
                break;
        }
    }

    return 0;
}
