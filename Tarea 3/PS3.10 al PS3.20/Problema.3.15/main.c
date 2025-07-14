#include <stdio.h>

int main() {
    int N1, N2, temp;

    // Pedir que ingrese dos números
    printf("Ingrese el primer número (N1): ");
    scanf("%d", &N1);

    printf("Ingrese el segundo número (N2): ");
    scanf("%d", &N2);

    // Validar que los números sean naturales (mayores o iguales a cero)
    if (N1 < 0 || N2 < 0) {
        printf("Por favor ingrese números naturales (0 o mayores).\n");
        return 1;  // Salir del programa con error
    }

    while (N2 != 0) {
        temp = N2;
        N2 = N1 % N2;
        N1 = temp;
    }

    printf("El máximo común divisor (MCD) es: %d\n", N1);

    return 0;
}
