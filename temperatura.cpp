#include <stdio.h>
#define PI 3.141596
#include <math.h>  //biblioteca para el pow

int main() {
	//dada una temperatura en la escala centigrada, escribir su valor en las escalar reaumur, farenheit y kelvin.
	
    float temperatura, resultado;

    // Pedir el primer número al usuario
    printf("Introduce la temperatura en centigrados\n");
    scanf("%f", &temperatura);  
    
    resultado = temperatura * 0.8;
    printf("El resultado en Reaumur es: %g\n", resultado);

    resultado = temperatura * 1.8 + 32;
    printf("El resultado en Farenheit es: %g\n", resultado);
    
    resultado = temperatura + 273.15;
    printf("El resultado en Kelvin es: %g\n", resultado);
    // el %g elige automáticamente entre notación decimal o científica, dependiendo del número.

return 0;
}
