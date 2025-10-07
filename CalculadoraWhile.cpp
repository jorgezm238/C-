#include <stdio.h>

int main() {
    // Declarar las variables
    int numero1;
    int numero2;
    int suma, resta, mult, division, resto;

    // Pedir el primer número al usuario
    printf("Introduce el primer numero\n");
    scanf("%d", &numero1);  

    // Pedir el segundo número y asegurarse de que no sea cero
    do {
        printf("Introduce el segundo numero\n");
        scanf("%d", &numero2);
    } while (numero2 == 0);  // Si el número es cero que se  pida de nuevo

    // Realizar las operaciones
    suma = numero1 + numero2;
    resta = numero1 - numero2;
    mult = numero1 * numero2;
    division = numero1 / numero2;
    resto = numero1 % numero2;

    // Mostrar los resultados
    printf("El resultado de la suma es: %d + %d = %d\n", numero1, numero2, suma);
    printf("El resultado de la resta es: %d - %d = %d\n", numero1, numero2, resta);
    printf("El resultado de la multiplicacion es: %d * %d = %d\n", numero1, numero2, mult);
    printf("El resultado de la division es: %d / %d = %d\n", numero1, numero2, division);
    printf("El resultado del resto es: %d %% %d = %d\n", numero1, numero2, resto);

    return 0; // Indica que todo ha funcionado correctamente
}

