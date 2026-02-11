#include <stdio.h>
/*Programa que escribe en forma binaria los datos de un array*/
int main() {
    int datos[10]={1,2,3,4,5,6,7,8,9,10};
    FILE *fichero;

    fichero = fopen("datos.bin", "wb");

    if (fichero != NULL) {


fwrite(datos, sizeof(int), 10, fichero);
fclose(fichero);
} else {
printf("Error al abrir el fichero.\n");
}

    return 0;
}
