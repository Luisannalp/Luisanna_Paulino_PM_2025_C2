#include <stdio.h>

int productoria(int);

void main(void)
{
    int NUM;
    do
    {
        printf("Ingresa el numero del cual quieres calcular la productoria: ");
        scanf("%d", &NUM);
    }
    while (NUM> 100 || NUM < 1);
    printf("\nLa productoria de %d es: %d", NUM, productoria(NUM));
}
int Productoria(int N)
{
    int I, PRO = 1;
    for (I = 1; I <= N; I++)
        PRO *= I;
    return (PRO);
}
