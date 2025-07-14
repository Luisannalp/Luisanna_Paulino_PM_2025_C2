#include <stdio.h>

int main(void) {
char cad[50];
int res;
FILE *ar = fopen("arc.txt", "w");
if (ar != NULL) {
printf("\n?Desea ingresar una cadena de caracteres? Si-1 No-0: ");
scanf("%d", &res);
while (res) {
fflush(stdin);
printf("Ingrese la cadena: ");
fgets(cad, 50, stdin);
cad[strcspn(cad, "\n")] = '\0';
fputs(cad, ar);
printf("\n?Desea ingresar otra cadena de caracteres? Si-1 No-0: ");
scanf("%d", &res);
if (res)
fputs("\n", ar);
}
fclose(ar);
} else
printf("No se puede abrir el archivo\n");
return 0;
}
            