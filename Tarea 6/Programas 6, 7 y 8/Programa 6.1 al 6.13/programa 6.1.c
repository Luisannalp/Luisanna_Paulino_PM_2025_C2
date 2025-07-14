#include <stdio.h>

const int TAM = 10;

void Lectura(int[][TAM], int);
void Imprime(int[][TAM], int);

int main(void) {
int MAT[TAM][TAM];
Lectura(MAT, TAM);
Imprime(MAT, TAM);
return 0;
}

void Lectura(int A[][TAM], int F) {
int I, J;
for (I = 0; I < F; I++)
for (J = 0; J < F; J++) {
printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
scanf("%d", &A[I][J]);
}
}

void Imprime(int A[][TAM], int F) {
int I;
printf("\nDiagonal principal:\n");
for (I = 0; I < F; I++)
printf("Elemento %d %d: %d\n", I + 1, I + 1, A[I][I]);
}
    