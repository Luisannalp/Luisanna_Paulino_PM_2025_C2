#include<stdio.h>
int main() {
    int N;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &N);

    // Generar la figura
    for (int i = 1; i <= N; i++) {
        // Parte creciente (1 hasta i)
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Parte decreciente (i-1 hasta 1)
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
