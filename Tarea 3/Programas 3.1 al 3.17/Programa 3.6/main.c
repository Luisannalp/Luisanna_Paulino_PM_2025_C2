#include <stdio.h>

void main(void)
{
    int I = 0;
    float SAL, PRO, NOM = 0;
    printf("Ingrese el salario del profesor:\t");
    scanf("%f", &SAL);
    do
    {
        NOM = NOM + SAL;
        printf("Ingrese el salario del profesor -0 para terminar- :\t");
        scanf("%f", &SAL);
    }
    while (SAL);
    PRO = NOM / I;
    printf("\nN�mina: %.2f \t Promedio de salarios: %.2f", NOM, PRO);
}
