#include <stdio.h>

int main() {
    char nombre[20];
    int numero1;
    int numero2;
    int numero3;
    int result;
    
    // Pedir el nombre al usuario
    printf("Introduce tu nombre: \n");
    scanf("%s", nombre);  // Aquí funciona correctamente

    //Pedir los tres números al usuario
    printf("Introduce el primer numero\n");
    scanf("%d", &numero1);  

    printf("Introduce el segundo numero\n");
    scanf("%d", &numero2); 

    printf("Introduce el tercer numero\n");
    scanf("%d", &numero3);  

    //Sumar los tres números
    result = numero1 + numero2 + numero3;

    printf("Hola %s. Por si no lo sabias, el resultado de %d + %d + %d es %d\n", nombre, numero1, numero2, numero3, result);

    return 0; // Indica que todo ha funcionado correctamente
}

