#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdio.h>
#include <stdlib.h>

void convertir_a_grises(const char *input_filename) {
    int ancho, alto, canales;
    unsigned char *imagen = stbi_load(input_filename, &ancho, &alto, &canales, 3); // Forzamos 3 canales

    if (!imagen) {
        printf("Error al cargar la imagen: %s\n", input_filename);
        return;
    }

    unsigned char *imagen_gris = (unsigned char *)malloc(ancho * alto * 3);

    for (int i = 0; i < ancho * alto; i++) {
        int r = imagen[i * 3];
        int g = imagen[i * 3 + 1];
        int b = imagen[i * 3 + 2];

        unsigned char gris = (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);

        imagen_gris[i * 3 + 0] = gris;
        imagen_gris[i * 3 + 1] = gris;
        imagen_gris[i * 3 + 2] = gris;
    }

    if (!stbi_write_jpg("salida.jpg", ancho, alto, 3, imagen_gris, 90)) {
        printf("Error al guardar salida.jpg\n");
    } else {
        printf("Imagen convertida a gris correctamente. Revisa salida.jpg\n");
    }

    stbi_image_free(imagen);
    free(imagen_gris);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.jpg\n", argv[0]);
        return 1;
    }

    convertir_a_grises(argv[1]);
    return 0;
}
