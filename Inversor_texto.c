/*!
 * \file   ejercicio1_inversion.c
 * \date   28-09-2026
 * \author Luis Felipe Solarte Tintinago (100624021037)
 * \brief  Ejercicio 1: Inversión de una cadena de caracteres in-place.
 * \par Descripción
 */

#include <stdio.h>

/* Prototipo de la función */
/*!
 * \brief Invierte el contenido de una cadena directamente en su espacio de memoria.
 * \param cadena Puntero al primer carácter del arreglo a procesar.
 */
void invertir_cadena(char *cadena);

void invertir_cadena(char *cadena) {
    /* 1. Se verifica que la dirección de memoria no esté vacía  */
    if (cadena == NULL) {
        return;
    }

    /* Puntero para buscar el final de la cadena */
    char *fin = cadena;

    /* 2. Se busca el final de la cadena*/
    while (*fin != '\0') { /* Se va buscando manualmente buscando el caracter nulo '\0' */
        fin++; 
    }

    /* Si la cadena está vacía (cuando se apunta al nulo), se termina */
    if (cadena == fin) {
        fin = NULL; 
        return;
    }

    /* Se retrocede una dirección de memoria para apuntar al último caracter */
    fin--;

    /* Se revisa y previene si el ultimo caracter es un salto de linea */
    if (*fin == '\n') {
        if (cadena == fin) {
            fin = NULL;
            return;
        }
        fin--;  /* Se retrocede una dirección para obtener el ultimo caracter y no '\0' o '\n' */

    }

    while (cadena < fin) {
        /* Se copia el caracter que está al final y se pega en el principio */
        char caracter_temporal = *cadena;
        *cadena = *fin;
        *fin = caracter_temporal;

        /* Se apunta hacia los demás caracteres y se retrocede una dirección para obtener el ultimo caracter*/
        cadena++;
        fin--;
    }
      /* Con este bucle el proceso va desde el exterior al interior*/
    /* 4. Seguridad: Asignar NULL a los punteros que quedan fuera de uso */
    fin = NULL; 
}

/*!
 * \brief Función principal del programa.
 */
int main(void) {
    /* Reservar almacenamiento de 200 caracteres */
    char buffer_entrada[200]; 

    printf("Ingrese una cadena de texto para que sea invertida: ");

    /* Leer desde el teclado */
    if (fgets(buffer_entrada, sizeof(buffer_entrada), stdin) != NULL) {
    /* sizeof es el numero maximo de caracteres que se pueden ingresar para no ocasionar el colapso*/
    /* stdin le dice a c que lea desde el teclado*/
    /* Invocación de la función procesando el arreglo mediante punteros */
    /* Se aplica la función invertir_cadena */
        invertir_cadena(buffer_entrada);
        
        printf("Cadena resultante: %s\n", buffer_entrada);
    } else {
        printf("Error en la lectura de datos.\n");
    }

    return 0;
  
}          