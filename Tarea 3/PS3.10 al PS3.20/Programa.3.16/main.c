#include <stdio.h>

int main() {
    int N;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    // Parte creciente (1 hasta N)
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Parte decreciente (N-1 hasta 1)
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
