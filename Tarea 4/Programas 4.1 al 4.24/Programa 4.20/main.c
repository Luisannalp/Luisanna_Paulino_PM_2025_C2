#include <stdio.h>

int f1 (int, int *);

int A = 3;
int B = 7;
int C = 4;
int D = 2;


void main(void)
{
    A= f1 (C, &D);
    printf("\n%d %d %d %d", A, B, C, D);
    C = 3;
    C = f1 (A, &C);
    printf("\n%d %d %d %d", A, B, C, D);
}
int f1 (int X, int *Y)
{
    int A;
    A = X * *Y;
    C++;
    B += *Y;
    printf("\n%d %d %d %d", A, B, C, D);
    *Y--;
    return (C);
}
