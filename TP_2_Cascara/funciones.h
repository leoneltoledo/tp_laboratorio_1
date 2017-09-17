#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 20

typedef struct {
    char nombre[50];
    int edad;
    int dni;
    int estado;
}ePersona;

/** \brief Alta de persona, ingreso de nombre, edad y dni.
 *
 * \param Array de personas.
 * \param Entero, tamaño del array.
 * \return Void.
 *
 */
void agregarPersona(ePersona[], int);

/** \brief Baja de persona preguntando por el dni, cambiando el estado de 1 a 0.
 *
 * \param Array de personas.
 * \param Entero, tamaño del array.
 * \return Void.
 *
 */
void borrarPersona(ePersona[], int);

/** \brief Ordena la lista de personas por nombre de la A la Z.
 *
 * \param Array de personas.
 * \param Entero, tamaño del array.
 * \return Void.
 *
 */
void ordenarPersonas(ePersona[], int);

/** \brief Muestra la lista de personas en pantalla.
 *
 * \param Array de personas.
 * \param Entero, tamaño del array.
 * \return Void.
 *
 */
void mostrarPersonas(ePersona[], int);

/** \brief Inicializa los estados del array en 0.
 *
 * \param Array de personas.
 * \param Entero, tamaño del array.
 * \return Void.
 *
 */
void inicializarEstados(ePersona[], int);

/** \brief Comprueba cuantas personas hay en cada rango de edad y grafica con un "*" a cada persona.
 *
 * \param Array de personas.
 * \param Entero, tamaño del array.
 * \return Void.
 *
 */
void graficoPersonas(ePersona[], int);

#endif // FUNCIONES_H_INCLUDED
