#include <stdio.h>

/* Búsqueda binaria en un arreglo ordenado en forma creciente. */

#define MAX 100  // Definición de tamaño máximo del arreglo

// Prototipos de funciones
void Lectura(int A[], int T);
int Binaria(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    // Verificar que el tamaño del arreglo sea válido
    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

    return 0;
}

void Lectura(int A[], int T)
// La función Lectura se usa para llenar el arreglo con T elementos
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
// Realiza búsqueda binaria del elemento E en arreglo A ordenado
{
    int IZQ = 0, DER = T - 1, CEN;
    int POS = 0;  // Guardará la posición encontrada (1-based) o 0 si no

    while (IZQ <= DER && POS == 0) {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            POS = CEN + 1;  // Se suma 1 porque el usuario espera posición desde 1
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return POS;
}
