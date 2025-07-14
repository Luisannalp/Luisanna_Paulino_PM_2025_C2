#include <stdio.h>
#include <math.h>

int main() {
    float grados, radianes, termino, resultado = 0;
    int exponente = 1, signo = 1, contador = 0;
    double factorial;

    printf("Introduce el ángulo en grados: ");
    scanf("%f", &grados);

    // Convertir a radianes
    radianes = grados * M_PI / 180;

    do {
        // Calcular el factorial de exponente
        factorial = 1;
        for (int i = 1; i <= exponente; i++) {
            factorial *= i;
        }

        // Calcular el término y sumarlo
        termino = signo * pow(radianes, exponente) / factorial;
        resultado += termino;

        // Preparar siguiente término
        exponente += 2;
        signo *= -1;
        contador++;
    } while (fabs(termino) >= 0.001);

    printf("sen(%.0f) ≈ %.5f usando %d términos\n", grados, resultado, contador);

    return 0;
}
