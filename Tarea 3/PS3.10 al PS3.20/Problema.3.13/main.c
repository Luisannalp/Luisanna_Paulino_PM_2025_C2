#include <stdio.h>
#include <math.h>

// Funci�n para saber si un n�mero es primo
int esPrimo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N1, N2, temp;

    // Leer los dos n�meros
    printf("Introduce el primer n�mero: ");
    scanf("%d", &N1);
    printf("Introduce el segundo n�mero: ");
    scanf("%d", &N2);

    // Asegurarse de que N1 < N2
    if (N1 > N2) {
        temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Pares de primos gemelos entre %d y %d:\n", N1, N2);

    for (int i = N1; i <= N2 - 2; i++) {
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
        }
    }

    return 0;
}

