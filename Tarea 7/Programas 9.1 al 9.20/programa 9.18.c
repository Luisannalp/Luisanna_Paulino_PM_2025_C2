#include <stdio.h>

void mezcla(FILE *ar, FILE *ar1, FILE *ar2) {
int i, mat, mat1, b = 1, b1 = 1;
float ca[3], ca1[3];
while ((!feof(ar) || !b) && (!feof(ar1) || !b1)) {
if (b) {
if (fscanf(ar, "%d", &mat) == 1) {
for (i = 0; i < 3; i++)
fscanf(ar, "%f", &ca[i]);
b = 0;
} else
b = 1;
}
if (b1) {
if (fscanf(ar1, "%d", &mat1) == 1) {
for (i = 0; i < 3; i++)
fscanf(ar1, "%f", &ca1[i]);
b1 = 0;
} else
b1 = 1;
}
if (!b && !b1) {
if (mat < mat1) {
fprintf(ar2, "%d\t", mat);
for (i = 0; i < 3; i++)
fprintf(ar2, "%.2f\t", ca[i]);
b = 1;
} else {
fprintf(ar2, "%d\t", mat1);
for (i = 0; i < 3; i++)
fprintf(ar2, "%.2f\t", ca1[i]);
b1 = 1;
}
fputs("\n", ar2);
}
}
while (!b && !feof(ar)) {
fprintf(ar2, "%d\t", mat);
for (i = 0; i < 3; i++)
fprintf(ar2, "%.2f\t", ca[i]);
fputs("\n", ar2);
b = 1;
if (fscanf(ar, "%d", &mat) == 1) {
for (i = 0; i < 3; i++)
fscanf(ar, "%f", &ca[i]);
b = 0;
}
}
while (!b1 && !feof(ar1)) {
fprintf(ar2, "%d\t", mat1);
for (i = 0; i < 3; i++)
fprintf(ar2, "%.2f\t", ca1[i]);
fputs("\n", ar2);
b1 = 1;
if (fscanf(ar1, "%d", &mat1) == 1) {
for (i = 0; i < 3; i++)
fscanf(ar1, "%f", &ca1[i]);
b1 = 0;
}
}
}

int main(void) {
FILE *ar = fopen("arc9.dat", "r");
FILE *ar1 = fopen("arc10.dat", "r");
FILE *ar2 = fopen("arc11.dat", "w");
if (ar != NULL && ar1 != NULL && ar2 != NULL) {
mezcla(ar, ar1, ar2);
fclose(ar);
fclose(ar1);
fclose(ar2);
} else
printf("No se pueden abrir los archivos\n");
return 0;
}
        