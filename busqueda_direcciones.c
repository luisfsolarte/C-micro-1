/*!
 * \file   ejercicio2_busqueda.c
 * \brief  Ejercicio 2: Búsqueda lineal y aritmética de direcciones.
 * \author Luis Felipe Solarte Tintinago
 * \date   2026-09-27
 */

#include <stdio.h>
#include <stddef.h> /* Para resta de punteros */

/* La función:
const int *inicio recible la dirección de memoria de inicio
int longitud es el tamaño del arreglo
int objetivo es el número que se busca */

const int* buscar_elemento(const int *inicio, int longitud, int objetivo);

/* Definición de la función  */
const int* buscar_elemento(const int *inicio, int longitud, int objetivo) {
    /* If que corrobora que la dirección no sea vacía o negativa.
       Si pasa, la función se aborta y retorna NULL */
    if (inicio == NULL || longitud <= 0) {
        return NULL;
    }

/* Punteros para el recorrido */
    const int *ptr_actual = inicio; /* Donde inicia el recorrido */
    const int *ptr_fin = inicio + longitud; /* Donde finaliza el recorrido */

    /* Avanzar unicamente con avance de punteros */
    while (ptr_actual < ptr_fin) {
        /* Si todavía no se llega al final, miramos el valor dentro del casillero */
        if (*ptr_actual == objetivo) {
            return ptr_actual; /* Cuando se encuentra, se devuelve su dirección */
        }
        ptr_actual++; /* Si no se encuentra se avanza a la siguiente dirección */
    }

    /* Si se termina el ciclo y no lo encuentra */
    return NULL;
}


int main(void) {
    /* Pimero se crea un arreglo de datos */
    int datos[5] = {10, 25, 40, 55, 70};
    int tamano = 5;
    int numero_a_buscar = 55;

    /* Se llama a la función creada antes*/
    const int *ptr_hallado = buscar_elemento(datos, tamano, numero_a_buscar);

    /* Se revisa si la función encontró algo */
    if (ptr_hallado != NULL) {
        /* Se restan los punteros para hallar el indice del puntero objetivo */
        ptrdiff_t indice = ptr_hallado - datos;
        
        printf("El numero %d fue encontrado.\n", numero_a_buscar);
        printf("El indice logico del objetivo en el arreglo es: %td\n", indice);
    } else {
        printf("El numero %d no existe en el arreglo.\n", numero_a_buscar);
    }

    /*Se limpiar puntero al finalizar */
    ptr_hallado = NULL;

    return 0;
}