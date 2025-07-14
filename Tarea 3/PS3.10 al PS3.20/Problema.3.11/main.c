#include <stdio.h>

int main()
{
    int N;
    printf("Ingrese el n�mero de a�os: ");
    scanf("%d", &N);

    float VIN[N][4];  // Matriz de N a�os por 4 tipos de vino
    float totalTipo[4] = {0};  // Total por tipo de vino
    float totalAnual[N];       // Total por a�o

    // Leer los datos
    for (int i = 0; i < N; i++)
    {
        printf("A�o %d:\n", i + 1);
        totalAnual[i] = 0;
        for (int j = 0; j < 4; j++)
        {
            printf("  Litros tipo %d: ", j + 1);
            scanf("%f", &VIN[i][j]);
            totalTipo[j] += VIN[i][j];      // Sumar al tipo
            totalAnual[i] += VIN[i][j];     // Sumar al a�o
        }
    }

    // Mostrar totales por tipo de vino
    printf("\nTotal producido por tipo de vino:\n");
    for (int j = 0; j < 4; j++)
    {
        printf("Tipo %d: %.2f litros\n", j + 1, totalTipo[j]);
    }

    // Mostrar totales por a�o
    printf("\nTotal producido por a�o:\n");
    for (int i = 0; i < N; i++)
    {
        printf("A�o %d: %.2f litros\n", i + 1, totalAnual[i]);
    }

    return 0;
}
