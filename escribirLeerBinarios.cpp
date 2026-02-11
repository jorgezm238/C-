#include <stdio.h>

/* Programa que escribe en forma binaria los datos de un array y luego los lee */
int main() {
    int datos[10]      = {1,2,3,4,5,6,7,8,9,10};
    int datosLeidos[10];
    int i;
    FILE *fichero;

    /* 1. Escribir en binario */
    fichero = fopen("datos.bin", "wb");
    if (fichero == NULL) {
        printf("Error al abrir el fichero para escritura.\n");
    } else {
        fwrite(datos, sizeof(int), 10, fichero);
        fclose(fichero);
    }

    /* 2. Leer en binario */
    fichero = fopen("datos.bin", "rb");
    if (fichero == NULL) {
        printf("Error al abrir el fichero para lectura.\n");
    } else {
        fread(datosLeidos, sizeof(int), 10, fichero);
        fclose(fichero);
    }

    /* 3. Mostrar lo leído */
    for (i = 0; i < 10; i++) {
        printf("%d ", datosLeidos[i]);
    }
    printf("\n");

    return 0;
}
