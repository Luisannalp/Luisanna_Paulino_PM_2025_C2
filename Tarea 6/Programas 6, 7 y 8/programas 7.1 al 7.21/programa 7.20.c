#include <stdio.h>
#include <string.h>

int longitud(char *cadena);

int main(void) {
int i, n, l = -1, p = -1, t;
char cad[50];
char FRA[20][50];
printf("\nIngrese el numero de filas del arreglo: ");
scanf("%d", &n);
if (n <= 0 || n > 20) {
printf("Numero de filas invalido. Debe ser entre 1 y 20.\n");
return 1;
}
for (i = 0; i < n; i++) {
printf("Ingrese la linea %d de texto. Maximo 50 caracteres: ", i + 1);
fflush(stdin);
gets(FRA[i]);
}
printf("\n");
for (i = 0; i < n; i++) {
strcpy(cad, FRA[i]);
t = longitud(cad);
if (t > l) {
l = t;
p = i;
}
}
if (p != -1) {
printf("\nLa cadena con mayor longitud es: ");
puts(FRA[p]);
printf("\nLongitud: %d", l);
} else {
printf("\nNo se ingresaron cadenas para comparar.");
}
return 0;
}

int longitud(char *cadena) {
int cue = 0;
while (cadena[cue] != '\0')
cue++;
return cue;
}
    