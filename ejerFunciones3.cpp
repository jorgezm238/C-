#include<stdio.h>

// Prototipo de la función factorial
int factorial(int);

// Función principal
int main() {
    int num1 = 5;
    
    // Llamada a la función factorial
    printf("El factorial de %d es %d\n", num1, factorial(num1));

    return 0; // Indica que todo ha funcionado correctamente
}

// Definición de la función factorial
int factorial(int n) {
    if (n == 0) {
        return 1; // El factorial de 0 es 1
    } else {
        return n * factorial(n - 1); // Cálculo recursivo
    }
}

