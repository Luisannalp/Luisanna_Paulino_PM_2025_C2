#include <stdio.h>
#include <string.h>

int cuentap(char *);

int main(void) {
int i;
char fra[50];
printf("\nIngrese la linea de texto: ");
gets(fra);
strcat(fra, " ");
i = cuentap(fra);
printf("\nLa linea de texto tiene %d palabras", i);
return 0;
}

int cuentap(char *cad) {
char *cad0_ptr;
int i = 0;
cad0_ptr = strstr(cad, " ");
while (cad0_ptr != NULL) {
strcpy(cad, cad0_ptr + 1);
i++;
cad0_ptr = strstr(cad, " ");
}
return i;
}
        