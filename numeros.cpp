#include <stdio.h>

int main(){
 	int numero1;
 	int numero2;
 	int numero3;
 	int result;
 	
 	printf("Introduce el primer numero\n");
 	scanf("%d", &numero1);  // Usar & para obtener la dirección de la variable
 	
 	printf("Introduce el segundo numero\n");
 	scanf("%d", &numero2);  // Lo mismo aquí
 	
 	printf("Introduce el tercer numero\n");
 	scanf("%d", &numero3);  // Y aquí también
 	
 	result = numero1 + numero2 + numero3;
 	printf("El resultado de %d + %d + %d es %d\n", numero1, numero2, numero3, result);
 	
 	return 0; // Indica que todo ha funcionado correctamente
}

