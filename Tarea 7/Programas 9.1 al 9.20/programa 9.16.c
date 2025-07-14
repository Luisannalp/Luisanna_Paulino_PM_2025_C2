#include <stdio.h>
#include <stdlib.h>

void sumypro(FILE *ap1) {
char cad[50];
int i = 0;
float sum = 0.0, r;
while (!feof(ap1)) {
if (fgets(cad, 50, ap1) != NULL) {
r = atof(cad);
if (r) {
i++;
sum += r;
}
}
}
printf("\nSuma: %.2f", sum);
if (i)
printf("\nPromedio: %.2f", sum / i);
}

int main(void) {
FILE *ap = fopen("arc2.txt", "r");
if (ap != NULL) {
sumypro(ap);
fclose(ap);
} else
printf("No se puede abrir el archivo\n");
return 0;
}
        