#include <stdio.h>

int f1(void);
int f2(void);
int f3(void);
int f4(void);

int X = 2;
int K_glob = 3;

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
        printf("\n\nResultado de la función f1(): %d", f1());
        printf("\nResultado de la función f2(): %d", f2());
        printf("\nResultado de la función f3(): %d", f3());
        printf("\nResultado de la función f4(): %d", f4());
    }

    return 0;
}

int f1(void)
{
    X = X + 5;
    return (X);
}

int f2(void)
{
    int X = 1;
    X += 7;
    return (X);
}

int f3(void)
{
    static int X = 0;
    X += 2;
    return (X);
}

int f4(void)
{
    int K = 5;
    int resultado = K + K_glob;
    return resultado;
}
