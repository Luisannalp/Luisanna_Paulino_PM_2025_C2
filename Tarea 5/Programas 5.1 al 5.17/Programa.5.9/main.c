#include <stdio.h>

/* B�squeda secuencial en arreglos desordenados. */

#define MAX 100  // Se define el tama�o m�ximo del arreglo

// Prototipos de funciones
void Lectura(int A[], int T);
int Busca(int A[], int T, int K);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    // Verificar que el tama�o del arreglo sea correcto
    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    // Se llama a la funci�n que busca en el arreglo
    RES = Busca(VEC, TAM, ELE);

    if (RES)
        // Si RES tiene un valor diferente de 0, se escribe la posici�n
        printf("\nEl elemento se encuentra en la posici�n %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
// La funci�n Lectura se utiliza para leer un arreglo unidimensional
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int K)
// Esta funci�n localiza en el arreglo un elemento determinado.
// Si se encuentra, devuelve su posici�n (empezando desde 1). Si no, devuelve 0.
{
    int I = 0, BAN = 0, RES;

    while (I < T && !BAN) {
        if (A[I] == K)
            BAN++;
        else
            I++;
    }

    if (BAN)
        RES = I + 1;  // Se suma 1 porque el arreglo inicia en �ndice 0
    else
        RES = 0;

    return RES;
}
