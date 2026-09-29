/*!
 * \file   ejercicio3_estadisticas.c
 * \brief  Ejercicio 3: Análisis estadístico de un buffer.
 * \author Luis Felipe Solarte Tintinago
 * \date   2026-09-27
 */

#include <stdio.h>

/* Se define la función requerida */
int calcular_estadisticas(const float *datos, int n, float *promedio, float *minimo, float *maximo);

int calcular_estadisticas(const float *datos, int n, float *promedio, float *minimo, float *maximo) {
    /* Comprobar que todos los datos sean validos */
    if (datos == NULL || promedio == NULL || minimo == NULL || maximo == NULL || n <= 0) {
        return -1; /* Devuelve -1 si algún puntero es NULL o si 'n' no es valido */
    }

    /* Se inicializa en la primera dirección */
    float suma = *datos;
    *minimo = *datos;
    *maximo = *datos;

    /* Puntero que empieza en el segundo elemento */
    const float *ptr_actual = datos + 1;
    const float *ptr_fin = datos + n;

    /* Recorrido usando operaciones de punteros */
    while (ptr_actual < ptr_fin) {
        /* suma que se usará para el promedio */
        suma += *ptr_actual;

        /* Se identifica el minimo*/
        if (*ptr_actual < *minimo) {
            *minimo = *ptr_actual;
        }
        
        /* Se identifica el máximo */
        if (*ptr_actual > *maximo) {
            *maximo = *ptr_actual;
        }
        
        /* Se avanza a la siguiente dirección */
        ptr_actual++;
    }

    /* Se calcula promedio y se asigna */
    *promedio = suma / n;

    return 0; /* El 0 representa operación exitosa */
}


int main(void) {
    float lecturas[5];
    int cantidad = 5;
    
    /* Variables donde se guardan los resultados */
    float prom_resultado = 0.0f;
    float min_resultado = 0.0f;
    float max_resultado = 0.0f;

    printf("Ingrese 5 lecturas numericas:\n");
    
    /* Se leen los datos: */
    float *ptr_ingreso = lecturas;
    while (ptr_ingreso < lecturas + cantidad) {
        printf("Valor: ");
        scanf("%f", ptr_ingreso); /* así scanf espera una direccion de memoria directamente */
        ptr_ingreso++;
    }

    /* se llama la función, pasando las direcciones de los punteros con & */
    int estado = calcular_estadisticas(lecturas, cantidad, &prom_resultado, &min_resultado, &max_resultado);

    /* Si el estado está en 0 (operación exitosa) */
    if (estado == 0) {
        printf("\n--- Reporte Estadistico ---\n");
        printf("Promedio: %.2f\n", prom_resultado);
        printf("Minimo:   %.2f\n", min_resultado);
        printf("Maximo:   %.2f\n", max_resultado);
    } else {
        printf("Error: Datos invalidos o punteros nulos detectados.\n");
    }

    /* Limpieza preventiva */
    ptr_ingreso = NULL;

    return 0;
}