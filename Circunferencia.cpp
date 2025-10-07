#include <stdio.h>
#define PI 3.141596
#include <math.h>  //biblioteca para el pow

int main() {
	//dada la longitud del radio, clcular la longitud de la circunferenia, el área del círculo, y el volumen de la esfera
    // Declarar las variables
    float radio = 15.6;
    float resultado;


resultado= 2* PI * radio;
    
    // Mostrar los resultados
    printf("El resultado de la longitud es: %.2f\n", resultado);

   resultado=  PI * pow(radio,2);
   printf("El resultado del area es %.2f\n", resultado);
   
   
    resultado= 1.33 * PI * pow(radio,3);
   printf("El resultado del volumen es %.2f\n", resultado);

    return 0; // Indica que todo ha funcionado correctamente
}
