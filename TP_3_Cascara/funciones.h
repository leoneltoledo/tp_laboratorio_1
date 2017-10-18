#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define TAM 15

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[200];
    int estado;
}eMovie;


/**
 *  Agrega una pelicula con todos sus datos al archivo binario.
 *  @param Array de peliculas eMovie.
 *  @return Retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no.
 */
int agregarPelicula(eMovie pelicula[]);

/**
 *  Borra una pelicula del archivo binario.
 *  @param Array de peliculas eMovie.
 *  @return Retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no.
 */
int borrarPelicula(eMovie pelicula[]);

/**
 *  Modifica los datos de una pelicula del archivo binario.
 *  @param Array de peliculas eMovie.
 */
void modificarPelicula(eMovie pelicula[]);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param Array de peliculas eMovie para ser agregadas en el archivo.
 *  @param El nombre para el archivo.
 */
void generarPagina(eMovie lista[], char nombre[]);

/**
 *  Inicializa los estados de las peliculas en 0.
 *  @param Array de peliculas eMovie.
 */
void inicializarEstados(eMovie pelicula[]);

/**
 *  Recorre el array de peliculas para encontrar el primer lugar libre.
 *  @param Array de peliculas eMovie.
 *  @return Retorna un entero con la posicion del primer lugar libre del array.
 */
int buscarLibre(eMovie pelicula[]);

/**
 *  Carga el archivo binario.
 *  @param Array de peliculas eMovie
 *  @return Retorna 0 o 1 de acuerdo a si pudo abrir el archivo binario o no.
 */
int cargarArchivo(eMovie pelicula[]);

/**
 *  Guarda el archivo binario.
 *  @param Array de peliculas eMovie
 *  @return Retorna 0 o 1 de acuerdo a si pudo guardar el archivo binario o no.
 */
int guardarArchivo(eMovie pelicula[]);

#endif // FUNCIONES_H_INCLUDED
