#include <stdio.h>
#include <stdlib.h>

int main(void) {
char c, cad[20];
int i = 0;
float sum = 0.0;
printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
c = getchar();
fflush(stdin);
while (c == 'S' || c == 's') {
printf("\nIngrese la cadena de caracteres: ");
gets(cad);
i++;
sum += atof(cad);
printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
fflush(stdin);
c = getchar();
fflush(stdin);
}
printf("\nSuma: %.2f", sum);
if (i > 0)
printf("\nPromedio: %.2f", sum / i);
else
printf("\nNo se ingresaron numeros para calcular el promedio.");
return 0;
}
        