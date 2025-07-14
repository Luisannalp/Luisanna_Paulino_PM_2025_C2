#include <stdio.h>
#include <string.h>

int main(void) {
char cad1[50], cad2[50];
char *cad0_ptr;
int i = 0;
printf("\nIngrese la primera cadena de caracteres: ");
gets(cad1);
printf("\nIngrese la cadena a buscar: ");
gets(cad2);
cad0_ptr = cad1;
cad0_ptr = strstr(cad0_ptr, cad2);
while (cad0_ptr != NULL) {
i++;
cad0_ptr = strstr(cad0_ptr + 1, cad2);
}
printf("\nEl numero de veces que aparece la segunda cadena es: %d", i);
return 0;
}
        