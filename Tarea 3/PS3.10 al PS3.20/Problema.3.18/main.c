#include <stdio.h>

int main() {
    int N;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    for (int fila = 0; fila < N; fila++) {
        // Números izquierdos (ascendentes)
        for (int num = 1; num <= N - fila; num++) {
            printf("%d ", num);
        }

        // Espacios centrales
        int espacios = 2 * fila + 1;
        for (int e = 0; e < espacios; e++) {
            printf("  "); // Dos espacios por posición
        }

        // Números derechos (descendentes)
        for (int num = N - fila; num >= 1; num--) {
            printf("%d ", num);
        }

        printf("\n"); // Cambio de línea
    }

    return 0;
}
