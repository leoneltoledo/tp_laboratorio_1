#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>
#include "funciones.h"
#ifndef FUNCIONES_C
#define FUNCIONES_C
#define TAM 15

void inicializarEstados(eMovie pelicula[]) {
    int i;
    for(i=0;i<TAM;i++) {
        pelicula[i].estado = 0;
    }
}

int buscarLibre(eMovie pelicula[]) {
	int index = -1;
	int i;
	for(i=0;i<TAM;i++) {
        if(pelicula[i].estado==0){
            index=i;
            break;
        }
	}
	return index;
}

int cargarArchivo(eMovie pelicula[]) {
	int flag = 0;
	FILE *f;

	f = fopen("bin.dat", "rb");

	if(f==NULL) {
		f = fopen("bin.dat", "wb");
		if(f==NULL) {
			return 1;
		}
		flag = 1;
	}

	if(flag==0) {
        fread(pelicula,sizeof(eMovie),TAM,f);
    }

	fclose(f);
	return 0;

}

int guardarArchivo(eMovie pelicula[]) {
    int i, aux;
    FILE *f;

    //Necesito que solo se guarden las estructuras con el estado en 1.

    for(i=0;i<TAM;i++) {
        if(pelicula[i].estado==0) {
            aux = i;
        }
    }

    f = fopen("bin.dat","wb");
    if(f==NULL) {
        return 1;
    }

    fwrite(pelicula,sizeof(eMovie),aux,f);
    fclose(f);

	return 0;
}

int agregarPelicula(eMovie pelicula[]) {
    int index;

	/*Buscamos cual es el primer indice libre dentro del array*/
	index=buscarLibre(pelicula);
	if(index!=-1) { //si hay lugar:
        printf("INGRESO DE DATOS:\n");
        printf("Ingrese Titulo: \n");
        fflush(stdin);
        gets(pelicula[index].titulo);
        printf("Ingrese genero: ");
        fflush(stdin);
        gets(pelicula[index].genero);
        printf("Ingrese duracion: ");
        scanf("%d", &pelicula[index].duracion);
        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(pelicula[index].descripcion);
        printf("Ingrese puntaje: ");
        scanf("%d", &pelicula[index].puntaje);
        printf("Ingrese link de la imagen: ");
        fflush(stdin);
        gets(pelicula[index].linkImagen);
        pelicula[index].estado = 1;
        system("cls");

        return 1;
    }

	else
	{
		printf("No queda espacio");
		getch();

		return 0;
	}

}

int borrarPelicula(eMovie pelicula[]) {
    char titulo[20];
    int i;
    char seguir;

    printf("Ingrese titulo de la pelicula\n");
    fflush(stdin);
    gets(titulo);

    for(i=0;i<TAM;i++) {
        if(strcmp(titulo, pelicula[i].titulo) == 0) {
            printf("%s\t%s\t%d\n", pelicula[i].titulo, pelicula[i].genero, pelicula[i].puntaje);
            printf("Desea eliminar? (s/n)\n");
            scanf(" %c", &seguir);
            if(seguir=='s') {
                pelicula[i].estado = 0;
                return 1;
            }
            else {
                printf("No se elimino la pelicula\n");
                return 0;
            }
        }
    }

    printf("No se encontro la pelicula\n");
    return 0;

}

void modificarPelicula(eMovie pelicula[]) {
    int i, opcion, duracion, puntaje;
    char titulo[20];
    char seguir = 's';

    printf("Ingrese titulo de la pelicula: \n");
    fflush(stdin);
    gets(titulo);

    for(i=0;i<TAM;i++) {
        if(strcmp(titulo, pelicula[i].titulo) == 0) {
            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink imagen: %s\n\n", pelicula[i].titulo, pelicula[i].genero, pelicula[i].duracion, pelicula[i].descripcion, pelicula[i].puntaje, pelicula[i].linkImagen);

            while(seguir=='s') {
                printf("Seleccione opcion segun dato a modificar: \n");
                printf("Titulo(1)--Genero(2)--Duracion(3)--Descripcion(4)--Puntaje(5)--LinkImg(6)--Salir(7)\n");
                scanf("%d", &opcion);

                switch(opcion) {
                    case 1:
                        printf("Ingrese titulo: \n");
                        fflush(stdin);
                        gets(pelicula[i].titulo);
                        break;
                    case 2:
                        printf("Ingrese genero: \n");
                        fflush(stdin);
                        gets(pelicula[i].genero);
                        break;
                    case 3:
                        printf("Ingrese duracion: \n");
                        scanf("%d", &duracion);
                        pelicula[i].duracion = duracion;
                        break;
                    case 4:
                        printf("Ingrese descripcion: \n");
                        fflush(stdin);
                        gets(pelicula[i].descripcion);
                        break;
                    case 5:
                        printf("Ingrese puntaje: \n");
                        scanf("%d", &puntaje);
                        pelicula[i].puntaje = puntaje;
                        break;
                    case 6:
                        printf("Ingrese link imagen: \n");
                        fflush(stdin);
                        gets(pelicula[i].linkImagen);
                        break;
                    case 7:
                        seguir = 'n';
                        break;
                }
            }
        }
    }
}

/*void generarPagina(eMovie lista[], char nombre[]) {
    FILE *archivo;
    char buffer[1080];

    strcat(buffer,"");
    strcat(buffer,variable);

    archivo = fopen("index.html","w");

    if(archivo==NULL) {
        printf("No se pudo abrir el archivo\n");
    }
    else {
        fprintf(archivo,buffer);
        printf("Pagina generada con exito\n");
    }

    fclose(archivo);
}*/

#endif // FUNCIONES_C
