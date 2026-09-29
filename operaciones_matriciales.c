/*!
 * \file   ejercicio4_matrices.c
 * \brief  Ejercicio 4: Operaciones matriciales en memoria contigua .
 * \author Luis Felipe Solarte Tintinago
 * \date   2026-09-27
 */

#include <stdio.h>

/* Funciones requeridas */
void sumar_matrices(const int *matA, const int *matB, int *res, int filas, int columnas);
void multiplicar_matrices(const int *matA, const int *matB, int *res, int n);
void imprimir_matriz(const int *mat, int filas, int columnas);

/* Función para imprimir la matriz */
void imprimir_matriz(const int *mat, int filas, int columnas) {
/* Se comprueba que los datos sean validos */
    if (mat == NULL || filas <= 0 || columnas <= 0) return; 
    /* para cada elemento de la matriz se usan los ciclos for 
    i para cada 'fila', j  para cada 'columna'*/
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            /* Se usa el algebra de matrices dada en el requerimiento 
            el * para decir que ingrese a esa posición */
            printf("%d\t", *(mat + (i * columnas) + j));
        }
        printf("\n");
    }
}

/* Función para sumar dos matrices */
void sumar_matrices(const int *matA, const int *matB, int *res, int filas, int columnas) {
/* Se verifica que los datos sean validos */
    if (matA == NULL || matB == NULL || res == NULL) return;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            /*Se suman los dos valores que se tienen en la matriz A y la matriz B.
            Guarda el resultado en la posición correspondiente de los resultados. */
            *(res + (i * columnas) + j) = *(matA + (i * columnas) + j) + *(matB + (i * columnas) + j);
        }
    }
}


 
 void multiplicar_matrices(const int *matA, const int *matB, int *res, int n) {
    if (matA == NULL || matB == NULL || res == NULL || n <= 0) return;

    for (int i = 0; i < n; i++) {          /* Recorre las filas de la matriz A */
        for (int j = 0; j < n; j++) {      /* Recorre las columnas de la matriz B */
            
            /* Inicializar la celda resultado en 0 */
            *(res + (i * n) + j) = 0;
            
            /* En tres bucles se obtiene el producto punto completo */
            for (int k = 0; k < n; k++) {
                *(res + (i * n) + j) += *(matA + (i * n) + k) * *(matB + (k * n) + j);
            }
        }
    }
}



int main(void) {
    /* Para representar las matrices en bloques de 3x3 
       Se reserva en la memoria 4 bloques de 9 posiciones (para cada matriz)*/
    int matriz_a[9];
    int matriz_b[9];
    int matriz_res_suma[9];
    int matriz_res_mult[9];

    printf(" INGRESA MATRIZ A (3x3) \n"); 
    /* Primero se apunta a la primera dirección de memoria
       Posteriormente se le pide al usuario que ingrese un valor
       se lee el valor y se guarda en esa direccion de memoria
       Por ultimo, se salta una posición hasta llenar los 9 espacios de la matriz*/
    int *ptr_a = matriz_a;
    while (ptr_a < matriz_a + 9) {
        printf("Ingrese valor: ");
        scanf("%d", ptr_a);
        ptr_a++;
    }

    printf("\n INGRESA MATRIZ B (3x3)\n");
    /* Primero se apunta a la primera dirección de memoria
       Posteriormente se le pide al usuario que ingrese un valor
       se lee el valor y se guarda en esa direccion de memoria
       Por ultimo, se salta una posición hasta llenar los 9 espacios de la matriz*/
    int *ptr_b = matriz_b;
    while (ptr_b < matriz_b + 9) {
        printf("Ingrese valor: ");
        scanf("%d", ptr_b);
        ptr_b++;
    }

    /* Se hacen las operaciones llamando a las funciones */
    sumar_matrices(matriz_a, matriz_b, matriz_res_suma, 3, 3);
    multiplicar_matrices(matriz_a, matriz_b, matriz_res_mult, 3);

    /* Se muestran los resultados en la pantalla */
    printf("\n--- MATRIZ A ---\n");
    imprimir_matriz(matriz_a, 3, 3);

    printf("\n--- MATRIZ B ---\n");
    imprimir_matriz(matriz_b, 3, 3);

    printf("\n--- RESULTADO SUMA ---\n");
    imprimir_matriz(matriz_res_suma, 3, 3);

    printf("\n--- RESULTADO MULTIPLICACION ---\n");
    imprimir_matriz(matriz_res_mult, 3, 3);
    
    /* Se vacían los punteros */
    ptr_a = NULL;
    ptr_b = NULL;

    return 0; /* Con 0 se avisa que el programa terminó correctamente */
}