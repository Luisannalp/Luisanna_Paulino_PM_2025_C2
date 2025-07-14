#include <stdio.h>

int main(void) {
char p1;
FILE *ar = fopen("arc.txt", "r");
if (ar != NULL) {
while (!feof(ar)) {
p1 = fgetc(ar);
if (!feof(ar))
putchar(p1);
}
fclose(ar);
} else
printf("No se puede abrir el archivo\n");
return 0;
}
            