#include<stdio.h>

/* Programa que pide un año al usuario y dice si ese año es bisiesto o no usando la función bisiesto */

// Prototipo de la función bisiesto
int bisiesto(int);

// Función principal
int main() {
    int anho;

    printf("Dime un anhooooo: ");
    scanf("%d", &anho);

    int esBisiesto = bisiesto(anho);
    if (esBisiesto == 1) {
        printf("El anho %d es bisiesto.\n", anho);
    } else {
        printf("El anho %d no es bisiesto.\n", anho);
    }

    return 0; // Indica que todo ha funcionado correctamente
}

// Definición de la función bisiesto
int bisiesto(int anho) {
    if ((anho % 4 == 0 && anho % 100 != 0) || anho % 400 == 0) {
        return 1; // Es bisiesto
    } else {
        return 0; // No es bisiesto
    }
}
