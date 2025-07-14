#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cambia(FILE *ap1, FILE *ap2) {
char cad[50], *cad1, aux[50];
while (!feof(ap1)) {
if (fgets(cad, 50, ap1) != NULL) {
cad[strcspn(cad, "\n")] = '\0';
cad1 = cad;
char *cad2 = strstr(cad1, "mexico");
while (cad2 != NULL) {
cad2[0] = 'M';
int k = cad2 - cad1;
strncpy(aux, cad1, k);
aux[k] = '\0';
strcat(aux, cad2);
strcpy(cad1, aux);
cad2 = strstr(cad1, "mexico");
}
fputs(cad1, ap2);
fputs("\n", ap2);
}
}
}

int main(void) {
FILE *ar = fopen("arc.txt", "r");
FILE *ap = fopen("arc1.txt", "w");
if (ar != NULL && ap != NULL) {
cambia(ar, ap);
fclose(ar);
fclose(ap);
printf("No se pueden abrir los archivos\n");
return 0;
}
}   