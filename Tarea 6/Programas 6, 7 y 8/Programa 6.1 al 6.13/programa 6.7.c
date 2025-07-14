#include <stdio.h>

const int F = 15, C = 12;

void Lectura1(int[][C], int, int);
void Lectura2(float[], int);
void Funcion1(int[][C], int, int, float[], float[]);
void Funcion2(float[], int);
void Funcion3(float[], int);

int main(void) {
int FAB[F][C] = {0};
float COS[F], VEN[F];
Lectura1(FAB, F, C);
Lectura2(COS, F);
Funcion1(FAB, F, C, COS, VEN);
Funcion2(VEN, F);
Funcion3(VEN, F);
return 0;
}

void Lectura1(int A[][C], int F, int C) {
int MES, PRO, CAN;
printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
scanf("%d %d %d", &MES, &PRO, &CAN);
while (MES != -1 && PRO != -1 && CAN != -1) {
if (MES >= 1 && MES <= 12 && PRO >= 1 && PRO <= F)
A[MES - 1][PRO - 1] += CAN;
printf("Ingrese mes, tipo de producto y cantidad vendida: ");
scanf("%d %d %d", &MES, &PRO, &CAN);
}
}

void Lectura2(float A[], int N) {
int I;
for (I = 0; I < N; I++) {
printf("Ingrese costo del producto %d: ", I + 1);
scanf("%f", &A[I]);
}
}

void Funcion1(int A[][C], int F, int C, float V1[], float V2[]) {
int I, J, SUM;
printf("\n");
for (I = 0; I < F; I++) {
SUM = 0;
for (J = 0; J < C; J++)
SUM += A[I][J];
V2[I] = V1[I] * SUM;
printf("\nTotal de ventas del producto %d: %.2f", I + 1, V2[I]);
}
}

void Funcion2(float A[], int C) {
int I;
float SUM = 0.0;
for (I = 0; I < C; I++)
SUM += A[I];
printf("\n\nTotal de ventas de la fabrica: %.2f", SUM);
}

void Funcion3(float A[], int C) {
int I, TPR = 0;
float VEN = A[0];
for (I = 1; I < C; I++)
if (VEN < A[I]) {
TPR = I;
VEN = A[I];
}
printf("\n\nTipo de Producto mas vendido: %d \t Ventas: %.2f", TPR + 1, VEN);
}
        