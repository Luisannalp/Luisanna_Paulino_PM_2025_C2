#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nombre [50];
    float promedio;
} Alumno;

void agregarAlumno(const char *archivo)
{
    FILE *f = fopen(archivo, "ab");
    Alumno a;
    printf("Nombre: ");
    scanf("%[^\n]", a.nombre);
    printf("Promedio: ");
    scanf("%f", &a.promedio);
    fwrite(&a, sizeof(Alumno), 1, f);
    fclose(f);
}

int cargarAlumnos(const char *archivo, Alumno alumnos[]) {
    FILE *f = fopen(archivo, "rb");
    if (!f) return 0;
    int i = 0;
    while (fread(&alumnos[i], sizeof(Alumno), 1, f)) {
        i++;
    }
    fclose(f);
    return i;
}

void bubbleSort(Alumno a[], int n, int porNombre) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            int cmp = porNombre
                ? strcmp(a[j].nombre, a[j + 1].nombre)
                : (a[j].promedio < a[j + 1].promedio);
            if (cmp > 0) {
                Alumno temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}

void imprimir (Alumno a[], int n)
{
    printf("\n%-20s | %s\n", "Nombre", "Promedio");
    for (int i = 0; i < n; i++)
    {
        printf("%-20s | %.2f\n", a[i].nombre, a[i].promedio);
    }
}
int main()
{
    char archivo []= "alumnos.dar";
    Alumno lista[100];
    int opcion;

    printf("1. Agregar alumno\n2. Ver ordenado por nombre\n3. Ver ordenado por promedio\nOpcion:");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        agregarAlumno(archivo);
    }
    else
    {
        int n = cargarAlumnos(archivo, lista);
        if (n == 0) {
            printf("No hay datos.\n");
            return 0;
        }
        if (opcion == 2) bubbleSort(lista, n, 1);
        if (opcion == 3) bubbleSort(lista, n, 0);
        imprimir(lista, n);
    }

    return 0;
}
