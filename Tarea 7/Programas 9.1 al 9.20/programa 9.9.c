#include <stdio.h>

typedef struct {
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;

void lee(FILE *ap) {
alumno alu;
while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
printf("\nMatricula: %d", alu.matricula);
printf("\tCarrera: %d", alu.carrera);
printf("\tPromedio: %.2f\t", alu.promedio);
puts(alu.nombre);
}
}

int main(void) {
FILE *ar = fopen("ad1.dat", "r");
if (ar != NULL) {
lee(ar);
fclose(ar);
} else
printf("\nEl archivo no se puede abrir\n");
return 0;
}
        