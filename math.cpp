#include <stdio.h>
#define PI 3.141596
#include <windows.h>  // al inicio del archivo

#include <math.h>  //biblioteca para el pow

int main() {
//solicita un valor entero, calcula su cuadrado y su raiz cuadrada	
 	int numero;
    float resultado;

    // Pedir el primer n�mero al usuario
    printf("Introduce un numero\n");
    scanf("%d", &numero);  
    
    resultado = pow(numero,2);
    printf("El cuadrado es: %g\n", resultado);

    resultado = sqrt(numero);
    printf("La raiz cuadrada es : %g\n", resultado);
   
printf("\nCerrando en 10 segundos...\n");
Sleep(10000); // 10000 milisegundos = 10 segundos
return 0;
}
