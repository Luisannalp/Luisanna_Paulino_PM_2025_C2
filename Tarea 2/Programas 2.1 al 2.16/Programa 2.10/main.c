#include <stdio.h>
#include <math.h>

void main(void)
{
    int NUM;
    printf("Hello world!\n");
    scanf("%d", &NUM);
    if (NUM ==0)
        printf("\nNULO");
    else
        if (pow (-1, NUM)> 0)
        printf("\nPar");
    else
        printf("\nImpar");
}
