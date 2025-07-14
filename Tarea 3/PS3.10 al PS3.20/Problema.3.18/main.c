#include <stdio.h>

int main() {
    int N;

    printf("Ingrese un n�mero entero positivo: ");
    scanf("%d", &N);

    for (int fila = 0; fila < N; fila++) {
        // N�meros izquierdos (ascendentes)
        for (int num = 1; num <= N - fila; num++) {
            printf("%d ", num);
        }

        // Espacios centrales
        int espacios = 2 * fila + 1;
        for (int e = 0; e < espacios; e++) {
            printf("  "); // Dos espacios por posici�n
        }

        // N�meros derechos (descendentes)
        for (int num = N - fila; num >= 1; num--) {
            printf("%d ", num);
        }

        printf("\n"); // Cambio de l�nea
    }

    return 0;
}
