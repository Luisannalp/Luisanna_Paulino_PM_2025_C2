#include <stdio.h>

int main(void) {
char cad0[20] = "Argentina";
puts(cad0);
strcpy(cad0, "Brasil");
puts(cad0);
char cad1[20] = "";
gets(cad1);
puts(cad1);
char cad2[20] = "Mexico";
puts(cad2);
gets(cad2);
puts(cad2);
return 0;
}
    