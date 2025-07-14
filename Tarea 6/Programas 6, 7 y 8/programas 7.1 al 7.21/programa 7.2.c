#include <stdio.h>
#include <ctype.h>

int main(void) {
char p1;
printf("\nIngrese un caracter para analizar si es un digito: ");
p1 = getchar();
if (isdigit(p1))
printf("%c es un digito\n", p1);
printf("%c no es un digito\n", p1);
fflush(stdin);
printf("\nIngrese un caracter para examinar si es una letra: ");
p1 = getchar();
if (isalpha(p1))
printf("%c es una letra\n", p1);
else
printf("%c no es una letra\n", p1);
fflush(stdin);
printf("\nIngrese un caracter para examinar si es una letra minuscula: ");
p1 = getchar();
if (isalpha(p1)) {
if (islower(p1))
    printf("%c es una letra minuscula\n", p1);
else
    printf("%c no es una letra minuscula\n", p1);
    } else
        printf("%c no es una letra\n", p1);
return 0;
}
