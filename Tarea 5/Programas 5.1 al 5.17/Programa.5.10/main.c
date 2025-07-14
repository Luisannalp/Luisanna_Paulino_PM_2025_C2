#include <stdio.h>

/* Búsqueda secuencial en arreglos ordenados en forma creciente. */

#define MAX 100  // Se define el tamaño máximo del arreglo

// Prototipos de funciones
void Lectura(int A[], int T);
int Busca(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    // Se verifica que el tamaño del arreglo sea correcto
    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    // Se llama a la función que busca en el arreglo
    RES = Busca(VEC, TAM, ELE);

    if (RES)
        // Si RES es diferente de 0, se escribe la posición del elemento
        printf("\nEl elemento se encuentra en la posición: %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

    return 0;
}

void Lectura(int A[], int T)
// La función Lectura se utiliza para leer un arreglo unidimensional
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int E)
// Esta función busca el elemento E en el arreglo ordenado A.
// Si se encuentra, regresa la posición (empezando desde 1); si no, regresa 0.
{
    int RES, I = 0, BAN = 0;

    // Nueva condición: E >= A[I], si ya A[I] es mayor que E, no seguirá buscando
    while ((I < T) && (E >= A[I]) && !BAN) {
        if (A[I] == E)
            BAN++;
        else
            I++;
    }

    if (BAN)
        RES = I + 1;  // Se suma 1 porque el arreglo empieza en índice 0
    else
        RES = 0;

    return RES;
}
