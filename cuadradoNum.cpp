#include <stdio.h>
#include <math.h>  //biblioteca para el pow
int main(){
 	int numero;
 	int result;
 	
 	printf("Introduce el primer numero\n");
 	scanf("%d", &numero);  // Usar & para obtener la dirección de la variable
 	
	result = pow(numero,2);
 	printf("El resultado de %d al cuadrado es %d \n", numero, result);
 	
 	return 0; // Indica que todo ha funcionado correctamente
}

