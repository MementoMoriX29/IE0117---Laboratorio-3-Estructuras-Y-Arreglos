#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int contar_unos_fila(int m[][SIZE], int fila);
int contar_unos_columna(int m[][SIZE], int col);
int es_identidad(int m[][SIZE]);
int tiene_fila_completa(int m[][SIZE]);
int tiene_columna_completa(int m[][SIZE]);


int contar_unos_fila(int m[][SIZE], int fila) {
    int count = 0;
    for (int j = 0; j < SIZE; j++) {
        if (m[fila][j] == 1)
            count++;
    }
    return count;
}


int contar_unos_columna(int m[][SIZE], int col) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (m[i][col] == 1)
            count++;
    }
    return count;
}


int es_identidad(int m[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                if (m[i][j] != 1) return 0;
            } else {
                if (m[i][j] != 0) return 0;
            }
        }
    }
    return 1;
}


int tiene_fila_completa(int m[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (contar_unos_fila(m, i) == SIZE)
            return 1;
    }
    return 0;

}

int tiene_columna_completa(int m[][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        if (contar_unos_columna(m, j) == SIZE)
            return 1;
    }
    return 0;
}


void imprimir_matriz(int m[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %d", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    int m[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    printf("Matriz ingresada:\n");
    imprimir_matriz(m);
    printf("Es matriz identidad: %s\n", es_identidad(m) ? "si" : "no");
    printf("Tiene fila completa de unos: %s\n", tiene_fila_completa(m) ? "si" : "no");
    printf("Tiene columna completa de unos: %s\n", tiene_columna_completa(m) ? "si" : "no");

    /* Matriz aleatoria */
    int r[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            r[i][j] = rand() % 2;

    printf("\nMatriz aleatoria:\n");
    imprimir_matriz(r);
    printf("Es matriz identidad: %s\n", es_identidad(r) ? "si" : "no");
    printf("Tiene fila completa de unos: %s\n", tiene_fila_completa(r) ? "si" : "no");
    printf("Tiene columna completa de unos: %s\n", tiene_columna_completa(r) ? "si" : "no");
    return 0;
}
