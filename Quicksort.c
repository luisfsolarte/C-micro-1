/*!
 * \file   ejercicio5_quicksort.c
 * \brief  Ejercicio 5: Quicksort in-place con asignación dinámica
 * \author Luis Felipe Solarte Tintinago (100624021037)
 * \date   28-09-2026
 */

#include <stdio.h>
#include <stdlib.h> /* Para malloc, calloc y free */

/* Funciones que se usarán */
void intercambiar(int *a, int *b);
void quicksort(int *arreglo, int izquierda, int derecha);
void imprimir_arreglo(const int *arreglo, int n);

void intercambiar(int *a, int *b) {
    /* Se verifica que los datos seaen validos */
    if (a == NULL || b == NULL) {
        return; 
    }
    
    /* Intercambio usando indirección */
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void quicksort(int *arreglo, int izquierda, int derecha) {
    /* Validación de datos */
    if (arreglo == NULL || izquierda >= derecha) {
        return;
    }

    /* Con lomuto se selecciona el último elemento como pivote */
    int pivote = *(arreglo + derecha);
    int i = izquierda - 1;

    /* Se recorre usando unicamente punteros, como se pide */
    for (int j = izquierda; j < derecha; j++) {
        if (*(arreglo + j) <= pivote) {
            i++;
            /* Pasamos las direcciones de memoria a la función intercambiar */
            intercambiar((arreglo + i), (arreglo + j));
        }
    }
    
    /* Se pone el pivote en su posición final */
    intercambiar((arreglo + i + 1), (arreglo + derecha));
    int indice_pivote = i + 1;

    /* Se llaman las sub-listas izquierda y derecha */
    quicksort(arreglo, izquierda, indice_pivote - 1);
    quicksort(arreglo, indice_pivote + 1, derecha);
}

void imprimir_arreglo(const int *arreglo, int n) {
    if (arreglo == NULL || n <= 0) return;
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arreglo + i));
    }
    printf("\n");
}

int main(void) {
    int cantidad = 0;

    printf("¿Cuantos elementos desea ordenar?: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("Cantidad invalida.\n");
        return -1;
    }

    /* Reserva exacta de memoria dinámica en el Heap */
    int *arreglo_dinamico = (int *)malloc(cantidad * sizeof(int));

    /* Comprobar que la reserva no falle */
    if (arreglo_dinamico == NULL) {
        printf("Error: No se pudo reservar la memoria.\n");
        return -1;
    }

    /* Se leen los datos usando punteros */
    int *ptr_ingreso = arreglo_dinamico;
    printf("Ingrese los %d numeros:\n", cantidad);
    while (ptr_ingreso < arreglo_dinamico + cantidad) {
        scanf("%d", ptr_ingreso);
        ptr_ingreso++;
    }

    printf("\nArreglo original: ");
    imprimir_arreglo(arreglo_dinamico, cantidad);

    /* Se ejecuta el ordenamiento*/
    quicksort(arreglo_dinamico, 0, cantidad - 1);

    printf("Arreglo ordenado: ");
    imprimir_arreglo(arreglo_dinamico, cantidad);

    /* Se libera memoria */
    free(arreglo_dinamico);
    arreglo_dinamico = NULL; /* Practica correcta hecha en los demás ejercicios */
    ptr_ingreso = NULL;

    return 0;
}

