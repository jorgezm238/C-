#include <stdio.h>

int main() {
	//leer dos numeros de teclado calcular la suma, resta, producto y cociente, asi como el resto de la div entera. Supongamos que el segundo numero es distinto de cero
    char nombre[20];
    int numero1;
    int numero2;
    int result,suma,resta,mult,division,resto;
    

    //Pedir los tres números al usuario
    printf("Introduce el primer numero\n");
    scanf("%d", &numero1);  
    
	printf("Introduce el segundo numero\n");

	if(numero2 != 0){
	    scanf("%d", &numero2); }
    else{
	printf("Se acabo el programa");
		}
    suma = numero1 + numero2;
    resta = numero1 - numero2;
    mult = numero1 * numero2;
    division = numero1 / numero2;
    resto = numero1 % numero2;
    
	printf(" El resultado de la suma es: %d + %d es %d\n", numero1, numero2, suma);
	printf(" El resultado de  la resta es : %d - %d es %d\n", numero1, numero2, resta);
	printf(" El resultado de la multiplicación es : %d * %d es %d\n", numero1, numero2, mult);
	printf(" El resultado de la division es : %d / %d es %d\n", numero1, numero2, division);
	printf(" El resultado de la resto es : %d / %d es %d\n", numero1, numero2, resto);




 


    return 0; // Indica que todo ha funcionado correctamente
}

