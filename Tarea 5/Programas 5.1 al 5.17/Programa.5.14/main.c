#include <stdio.h>
#include <math.h>

/* Estadístico.
   El programa recibe un arreglo unidimensional de enteros que contiene calificaciones,
   y calcula la media, la varianza, la desviación estándar y la moda. */

const int MAX = 100;

void Lectura(int *, int);
float Media(int *, int);
float Varianza(int *, int, float);
float Desviacion(float);
void Frecuencia(int *, int, int *);
int Moda(int *, int);

int main(void)
{
    int TAM, MOD, ALU[MAX], FRE[11] = {0}; // FRE para frecuencias de 0 a 10 (suponiendo calif entre 0 y 10)
    float MED, VAR, DES;

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);  // Verifica tamaño correcto

    Lectura(ALU, TAM);
    MED = Media(ALU, TAM);
    VAR = Varianza(ALU, TAM, MED);
    DES = Desviacion(VAR);
    Frecuencia(ALU, TAM, FRE);
    MOD = Moda(FRE, 11);

    printf("\nMedia:      %.2f", MED);
    printf("\nVarianza:   %.2f", VAR);
    printf("\nDesviación: %.2f", DES);
    printf("\nModa:       %d\n", MOD);

    return 0;
}

void Lectura(int A[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
        if (A[I] < 0 || A[I] > 10) {
            printf("Calificacion fuera de rango (0-10). Intente de nuevo.\n");
            I--;
        }
    }
}

float Media(int A[], int T)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += A[I];
    return (SUM / T);
}

float Varianza(int A[], int T, float M)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += pow((A[I] - M), 2);
    return (SUM / T);
}

float Desviacion(float V)
{
    return sqrt(V);
}

void Frecuencia(int A[], int P, int B[])
{
    int I;
    for (I = 0; I < P; I++)
        B[A[I]]++;
}

int Moda(int A[], int T)
{
    int I, MOD = 0, VAL = 0;
    for (I = 1; I < T; I++)
    {
        if (A[I] > MOD)
        {
            MOD = A[I];
            VAL = I;
        }
    }
    return VAL;
}
