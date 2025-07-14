#include <stdio.h>

/* B�squeda binaria en un arreglo ordenado en forma creciente. */

#define MAX 100  // Definici�n de tama�o m�ximo del arreglo

// Prototipos de funciones
void Lectura(int A[], int T);
int Binaria(int A[], int T, int E);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    // Verificar que el tama�o del arreglo sea v�lido
    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);

    if (RES)
        printf("\nEl elemento se encuentra en la posici�n: %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

    return 0;
}

void Lectura(int A[], int T)
// La funci�n Lectura se usa para llenar el arreglo con T elementos
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
// Realiza b�squeda binaria del elemento E en arreglo A ordenado
{
    int IZQ = 0, DER = T - 1, CEN;
    int POS = 0;  // Guardar� la posici�n encontrada (1-based) o 0 si no

    while (IZQ <= DER && POS == 0) {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            POS = CEN + 1;  // Se suma 1 porque el usuario espera posici�n desde 1
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return POS;
}
