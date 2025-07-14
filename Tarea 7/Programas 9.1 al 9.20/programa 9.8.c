#include <stdio.h>

typedef struct {
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;

void escribe(FILE *ap) {
alumno alu;
int i = 0, r;
printf("\n?Desea ingresar informacion sobre alumnos? (Si-1 No-0): ");
scanf("%d", &r);
while (r) {
i++;
printf("Matricula del alumno %d: ", i);
scanf("%d", &alu.matricula);
printf("Nombre del alumno %d: ", i);
fflush(stdin);
fgets(alu.nombre, 50, stdin);
alu.nombre[strcspn(alu.nombre, "\n")] = '\0';
printf("Carrera del alumno %d: ", i);
scanf("%d", &alu.carrera);
printf("Promedio del alumno %d: ", i);
scanf("%f", &alu.promedio);
fwrite(&alu, sizeof(alumno), 1, ap);
printf("\n?Desea ingresar informacion sobre mas alumnos? (Si-1 No-0): ");
scanf("%d", &r);
}
}

int main(void) {
FILE *ar = fopen("ad1.dat", "w");
if (ar != NULL) {
escribe(ar);
fclose(ar);
} else
printf("\nEl archivo no se puede abrir\n");
return 0;
}
        