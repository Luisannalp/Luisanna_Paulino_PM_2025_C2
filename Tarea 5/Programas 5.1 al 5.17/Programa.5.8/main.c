#include <stdio.h>


/* Primos.
   El programa almacena en un arreglo unidimensional los primeros 100 n�meros primos. */

const int TAM = 100;

void Imprime(int[], int);  // Prototipos de funciones.
void Primo(int, int *);

void main(void)
{
    int P[TAM] = {1, 2};  // Aunque 1 no es primo, este ejemplo lo incluye.
    int FLA, J = 2, PRI = 3;

    while (J < TAM)  // Debe ser < TAM, no <=, porque los �ndices van de 0 a 99.
    {
        FLA = 1;
        Primo(PRI, &FLA);  // Se llama a la funci�n que determina si PRI es primo.

        if (FLA)  // Si FLA es 1, entonces PRI es primo.
        {
            P[J] = PRI;
            J++;
        }

        PRI += 2;  // Se incrementa en 2 para evitar pares (excepto el 2, que ya est�).
    }

    Imprime(P, TAM);
}

void Primo(int A, int *B)
// Esta funci�n determina si A es primo, en cuyo caso el valor de *B se mantiene en 1.
// Si no es primo, *B se pone en 0.
{
    int DI = 3;
    while (*B && (DI <= A / 2))  // Se puede optimizar a sqrt(A), pero se mantiene as�.
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
    }
}

void Imprime(int Primos[], int T)
// Esta funci�n imprime el arreglo unidimensional de n�meros primos.
{
    int I;
    for (I = 0; I < T; I++)
        printf("Primos[%d]: %d\n", I, Primos[I]);
}
