#include <stdio.h>

const int F = 5, C = 12;

void LecturaM(float[][C], int, int);
void LecturaV(float[], int);
void F1(float[][C], int, int, float[], float[]);
void F2(float[][C], int, int);
void F3(float[], int);

int main(void) {
float FON[F][C], PRE[F], REN[F];
LecturaM(FON, F, C);
LecturaV(PRE, F);
F1(FON, F, C, PRE, REN);
F2(FON, F, C);
F3(REN, F);
return 0;
}

void LecturaM(float A[][C], int F, int C) {
int I, J;
for (I = 0; I < F; I++)
for (J = 0; J < C; J++) {
printf("Precio fondo %d\t mes %d: ", I + 1, J + 1);
scanf("%f", &A[I][J]);
}
}

void LecturaV(float A[], int T) {
int I;
printf("\n");
for (I = 0; I < T; I++) {
printf("Precio Fondo %d al 31/12/2003: ", I + 1);
scanf("%f", &A[I]);
}
}

void F1(float A[][C], int F, int C, float B[], float V[]) {
int I;
printf("\nRENDIMIENTOS ANUALES DE LOS FONDOS");
for (I = 0; I < F; I++) {
V[I] = (A[I][C - 1] - B[I]) / B[I] * 100;
printf("\nFondo %d: %.2f", I + 1, V[I]);
}
}

void F2(float A[][C], int R, int C) {
int I, J;
float SUM, PRO;
printf("\n\nPROMEDIO ANUALIZADO DE LAS ACCIONES DE LOS FONDOS");
for (I = 0; I < R; I++) {
SUM = 0;
for (J = 0; J < C; J++)
SUM += A[I][J];
PRO = SUM / C;
printf("\nFondo %d: %.2f", I + 1, PRO);
}
}

void F3(float A[], int F) {
float ME = A[0], PE = A[0];
int M = 0, P = 0, I;
for (I = 1; I < F; I++) {
if (A[I] > ME) {
ME = A[I];
M = I;
}
if (A[I] < PE) {
PE = A[I];
P = I;
}
}
printf("\n\nMEJOR Y PEOR FONDO DE INVERSION");
printf("\nMejor fondo: %d\tRendimiento: %.2f", M + 1, ME);
printf("\nPeor fondo: %d\tRendimiento: %.2f", P + 1, PE);
}
                