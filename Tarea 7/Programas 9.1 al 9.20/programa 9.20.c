#include <stdio.h>

typedef struct {
char materia[50];
int calificacion;
} matcal;

typedef struct {
int matricula;
char nombre[50];
matcal cal[5];
} alumno;

void F1(FILE *ap) {
alumno alu;
int j;
float sum, pro;
printf("\nMATRICULA y PROMEDIOS\n");
while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
printf("Matricula: %d", alu.matricula);
sum = 0.0;
for (j = 0; j < 5; j++)
sum += alu.cal[j].calificacion;
pro = sum / 5;
printf("\tPromedio: %.2f\n", pro);
}
}

void F2(FILE *ap) {
alumno alu;
printf("\nALUMNOS CON CALIFICACION > 9 EN MATERIA 3\n");
rewind(ap);
while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
if (alu.cal[2].calificacion > 9)
printf("Matricula del alumno: %d\n", alu.matricula);
}
}

float F3(FILE *ap) {
alumno alu;
int i = 0;
float sum = 0;
rewind(ap);
while (fread(&alu, sizeof(alumno), 1, ap) == 1) {
i++;
sum += alu.cal[3].calificacion;
}
return i ? sum / i : 0;
}

int main(void) {
float pro;
FILE *ap = fopen("esc.dat", "r");
if (ap != NULL) {
F1(ap);
F2(ap);
pro = F3(ap);
printf("\nPROMEDIO GENERAL MATERIA 4: %.2f\n", pro);
fclose(ap);
} else
printf("\nEl archivo no se puede abrir\n");
return 0;
}
        