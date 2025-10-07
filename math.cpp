#include <stdio.h>
#define PI 3.141596
#include <math.h>  //biblioteca para el pow

int main() {
//solicita un valor entero, calcula su cuadrado y su raiz cuadrada	
 	int numero;
    float resultado;

    // Pedir el primer número al usuario
    printf("Introduce un numero\n");
    scanf("%d", &numero);  
    
    resultado = pow(numero,2);
    printf("El cuadrado es: %g\n", resultado);

    resultado = sqrt(numero);
    printf("La raiz cuadrada es : %g\n", resultado);
   

return 0;
}
