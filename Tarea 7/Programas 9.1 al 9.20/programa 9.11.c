#include <stdio.h>

typedef struct {
int clave;
int departamento;
float salario;
float ventas[12];
} empleado;

void incrementa(FILE *ap) {
int i, j, t;
float sum;
empleado emple;
t = sizeof(empleado);
while (fread(&emple, sizeof(empleado), 1, ap) == 1) {
i = ftell(ap) / t;
sum = 0;
for (j = 0; j < 12; j++)
sum += emple.ventas[j];
if (sum > 1000000) {
emple.salario *= 1.10;
fseek(ap, (i - 1) * sizeof(empleado), SEEK_SET);
fwrite(&emple, sizeof(empleado), 1, ap);
fseek(ap, i * sizeof(empleado), SEEK_SET);
}
}
}

int main(void) {
FILE *ar = fopen("ad5.dat", "r+");
if (ar != NULL) {
incrementa(ar);
fclose(ar);
} else
printf("\nEl archivo no se puede abrir\n");
return 0;
}
        