#include <stdio.h>

const int MAX = 100;

void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

int main(void)
{
    int TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);  // Verifica tamaño correcto

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);

    return 0;
}

void Lectura(int A[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
{
    int I;
    printf("\nArreglo ordenado:\n");
    for (I = 0; I < T; I++)
        printf("A[%d]: %d\n", I, A[I]);
}

void Ordena(int A[], int T)
{
    int I, J, MEN, L, temp;
    for (I = 0; I < T - 1; I++)
    {
        MEN = A[I];
        L = I;
        for (J = I + 1; J < T; J++)
        {
            if (A[J] < MEN)
            {
                MEN = A[J];
                L = J;
            }
        }
        // Intercambio de A[L] y A[I]
        temp = A[L];
        A[L] = A[I];
        A[I] = temp;
    }
}
