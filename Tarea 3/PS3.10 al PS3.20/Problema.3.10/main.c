#include <stdio.h>
#include <stdlib.h>


int main()
{
    float L[6]; // Declaramos a L que contrendra las 6 posiciones donde se guardarn los precios.
    int B[6]= {0}; // Para contar los boletos vendidos
    int CLA, CAN; // CLA tipo de localidad, CAN cantidad de boletos vendidos.
    float total = 0; // Suma total del didero recaudado.

    printf("Ingrese los precios de las 6 localidades:\n");
    // Leer precios
    for (int i = 0; i < 6; i++)
    {
        printf("Precio de l%d:", i + 1);
        scanf("%f", &L[i]);
    }

    //Leer ventas
    printf("\nIngresa la localidad y cantidad de venta. Escriba (0 0) para terminar\n");
    while(1)
    {
        printf("Tipo de localidad: ");
        scanf("%d", &CLA);
        printf("Cantidad de boletos: ");
        scanf("%d", &CAN);

        if (CLA == 0 && CAN == 0) break;
        if (CLA <1 && CLA >6)
        {
            printf("Tipo invalido. Debe ser entre 1-6.\n");
            continue;
        }

        total += L[CLA - 1]* CAN;
        B[CLA - 1] += CAN;
    }

//Resultado
    printf("Total recaudado: $%.2f\n", total);
    for (int i = 0; i < 6; i++)
    {
        printf("l%d: %d boletos\n", i + 1, B[i]);
    }
    return 0;

}
