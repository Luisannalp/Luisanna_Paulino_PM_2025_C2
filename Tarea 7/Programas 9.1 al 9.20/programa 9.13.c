#include <stdio.h>

int cuenta(char car) {
int con = 0;
char p;
FILE *ar = fopen("arc.txt", "r");
if (ar != NULL) {
while (!feof(ar)) {
p = getc(ar);
if (p == car)
con++;
}
fclose(ar);
return con;
}
return -1;
}

int main(void) {
char car;
printf("\nIngrese el caracter que se va a buscar en el archivo: ");
car = getchar();
int res = cuenta(car);
if (res != -1)
printf("\nEl caracter %c se encuentra en el archivo %d veces\n", car, res);
printf("No se pudo abrir el archivo\n");
return 0;
}