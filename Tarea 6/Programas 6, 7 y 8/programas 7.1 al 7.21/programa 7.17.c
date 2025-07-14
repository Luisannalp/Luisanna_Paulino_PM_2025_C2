#include <stdio.h>
#include <string.h>

char *inverso(char *);

int main(void) {
char fra[50], aux[50];
printf("\nIngrese la linea de texto: ");
gets(fra);
strcpy(aux, inverso(fra));
printf("\nEscribe la linea de texto en forma inversa: ");
puts(aux);
return 0;
}

char *inverso(char *cadena) {
int i = 0, j, lon;
char cad_char_temp;
lon = strlen(cadena);
j = lon - 1;
while (i < (lon - 1) / 2) {
cad_char_temp = cadena[i];
cadena[i] = cadena[j];
cadena[j] = cad_char_temp;
i++;
j--;
}
return cadena;
}
        