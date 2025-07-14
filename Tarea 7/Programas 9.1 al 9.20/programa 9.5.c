#include <stdio.h>

int main(void) {
int i, j, n, mat;
float cal;
FILE *ar = fopen("arc8.txt", "w");
printf("\nIngrese el numero de alumnos: ");
scanf("%d", &n);
if (n < 1 || n > 35) {
printf("El numero de alumnos debe estar entre 1 y 35\n");
return 1;
}
if (ar != NULL) {
fprintf(ar, "%d ", n);
for (i = 0; i < n; i++) {
printf("\nIngrese la matricula del alumno %d: ", i + 1);
scanf("%d", &mat);
fprintf(ar, "\n%d ", mat);
for (j = 0; j < 5; j++) {
printf("Calificacion %d: ", j + 1);
scanf("%f", &cal);
fprintf(ar, "%.2f ", cal);
}
}
fclose(ar);
} else
printf("No se puede abrir el archivo\n");
return 0;
}
                    