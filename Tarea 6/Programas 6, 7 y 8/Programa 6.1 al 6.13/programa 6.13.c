#include <stdio.h>

const int MES = 12;
const int DEP = 3;
const int ANO = 8;

void Lectura(float[][DEP][ANO], int, int, int);
void Funcion1(float[][DEP][ANO], int, int, int);
void Funcion2(float[][DEP][ANO], int, int, int);
void Funcion3(float[][DEP][ANO], int, int, int);

int main(void) {
float PRO[MES][DEP][ANO];
Lectura(PRO, MES, DEP, ANO);
Funcion1(PRO, MES, DEP, 2);
Funcion2(PRO, MES, DEP, ANO);
Funcion3(PRO, MES, DEP, ANO);
return 0;
}

void Lectura(float A[][DEP][ANO], int F, int C, int P) {
int K, I, J;
for (K = 0; K < P; K++)
for (I = 0; I < F; I++)
for (J = 0; J < C; J++) {
printf("Ano: %d\tMes: %d\tDepartamento: %d: ", K + 1, I + 1, J + 1);
scanf("%f", &A[I][J][K]);
}
}

void Funcion1(float A[][DEP][ANO], int F, int C, int P) {
int I, J;
float SUM = 0.0;
for (I = 0; I < F; I++)
for (J = 0; J < C; J++)
SUM += A[I][J][P - 1];
printf("\n\nVentas totales de la empresa en el segundo ano: %.2f", SUM);
}

void Funcion2(float A[][DEP][ANO], int F, int C, int P) {
int I, J;
float SUM1 = 0, SUM2 = 0, SUM3 = 0;
for (I = 0; I < F; I++) {
SUM1 += A[I][0][P - 1];
SUM2 += A[I][1][P - 1];
SUM3 += A[I][2][P - 1];
}
if (SUM1 > SUM2 && SUM1 > SUM3)
printf("\n\nDepartamento con mayores ventas en el ultimo ano: Hilos. Importe: %.2f", SUM1);
else if (SUM2 > SUM3)
printf("\n\nDepartamento con mayores ventas en el ultimo ano: Lanas. Importe: %.2f", SUM2);
printf("\n\nDepartamento con mayores ventas en el ultimo ano: Licra. Importe: %.2f", SUM3);
}

void Funcion3(float A[][DEP][ANO], int F, int C, int P) {
int I, J, K, D = 0, M = 0, ANO_MAY = 0;
float VMAY = 0.0;
for (K = 0; K < P; K++)
for (I = 0; I < F; I++)
for (J = 0; J < C; J++)
if (A[I][J][K] > VMAY) {
VMAY = A[I][J][K];
D = J;
M = I;
ANO_MAY = K;
}
printf("\n\nDepartamento, mes y ano con mayores ventas: Departamento %d\tMes %d\tAno %d\tVentas %.2f", D + 1, M + 1, ANO_MAY + 1, VMAY);
}
                                                  