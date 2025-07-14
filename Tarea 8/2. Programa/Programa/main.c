#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    float promedio;
} Alumno;

void guardarAlumnos(const char *nombreArchivo, Alumno *alumnos, int cantidad)
{
    FILE *f = fopen(nombreArchivo, "wb");
    if (!f)
    {
        perror("Error al abrir el archivo para escritura");
        exit(1);
    }
    fwrite(alumnos, sizeof(Alumno), cantidad, f);
    fclose(f);
}

Alumno* leerAlumnos(const char *nombreArchivo, int *cantidad)
{
    FILE *f = fopen(nombreArchivo, "rb");
    if (!f)
    {
        perror("Error al abrir el archivo para lectura");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long tamanio = ftell(f);
    rewind(f);
    *cantidad = tamanio / sizeof(Alumno);
    Alumno *alumnos = (Alumno *)malloc(*cantidad * sizeof(Alumno));
    if (!alumnos)
    {
        perror("No se pudo asignar memoria");
        exit(1);
    }

    fread(alumnos, sizeof(Alumno), *cantidad, f);
    fclose(f);
    return alumnos;
}

void mostrarAlumnos(Alumno *alumnos, int cantidad)
{
    Alumno *ptr = alumnos;
    for (int i = 0; i < cantidad; i++)
    {
        printf("Alumno #%d: %s - Promedio: %.2f\n", i + 1, ptr->nombre, ptr->promedio);
        ptr++;
    }
}

int main()
{
    int cantidad;
    printf("¿Cuántos alumnos deseas ingresar? ");
    scanf("%d", &cantidad);
    Alumno *alumnos = (Alumno *)malloc(cantidad * sizeof(Alumno));
    if (!alumnos)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre del alumno #%d: ", i + 1);
        scanf(" %[^\n]", alumnos[i].nombre);
        printf("Promedio del alumno #%d: ", i + 1);
        scanf("%f", &alumnos[i].promedio);
    }
    guardarAlumnos("alumnos.dat", alumnos, cantidad);
    free(alumnos);
    Alumno *alumnosLeidos = leerAlumnos("alumnos.dat", &cantidad);
    printf("\n--- Lista de alumnos leídos desde disco ---\n");
    mostrarAlumnos(alumnosLeidos, cantidad);
    free(alumnosLeidos);

    return 0;
}
