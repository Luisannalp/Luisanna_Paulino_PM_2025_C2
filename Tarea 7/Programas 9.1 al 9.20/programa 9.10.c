#include <stdio.h>

typedef struct {
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;

void modifica(FILE *ap) {
int d;
alumno alu;
printf("\nIngrese el numero de registro que desea modificar: ");
scanf("%d", &d);
fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
if (fread(&alu, sizeof(alumno), 1, ap) == 1) {
printf("Ingrese el promedio correcto del alumno: ");
scanf("%f", &alu.promedio);
fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
fwrite(&alu, sizeof(alumno), 1, ap);
} else
printf("Registro no encontrado\n");
}

int main(void) {
FILE *ar = fopen("ad1.dat", "r+");
if (ar != NULL) {
modifica(ar);
fclose(ar);
} else
printf("\nEl archivo no se puede abrir\n");
return 0;
}
        