#include <stdio.h>

int main() {
    char nombre[20];
    float numero1;
    float numero2;
    float numero3;
    float result;
    float division;
    float nuevaDivision;
    
    // Pedir el nombre al usuario
    printf("Introduce tu nombre: \n");
    scanf("%s", nombre);  

    printf("Introduce el primer numero\n");
    scanf("%f", &numero1);  

    printf("Introduce el segundo numero\n");
    scanf("%f", &numero2); 

    printf("Introduce el tercer numero\n");
    scanf("%f", &numero3);  

    result = numero1 + numero2 + numero3;

    printf("Hola %s. Por si no lo sabias, el resultado de %f + %f + %f es %f\n", nombre, numero1, numero2, numero3, result);

    // Realizar la división
    division = result / 2;

    printf("La division de la suma es igual a: %f\n", division);
	
	  nuevaDivision = numero1 / numero2;
	  printf("La division entre el primer numero (%f) y el segundo numero (%f) es igual a : %f\n", numero1,numero2,nuevaDivision);

    return 0; // Indica que todo ha funcionado correctamente
}

