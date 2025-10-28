#include <stdio.h>
#define TAM 10

int main() {
    int num[TAM];
    int i;
   
    // Leer los números
    for(i = 0; i < TAM; i++) {
        printf("\nDime el valor del numero %d: ", i + 1);
        scanf("%d", &num[i]); // Usamos 'i' en lugar de 'TAM'
    }
  	int mayor=num[0];
   
    for(i =1; i <=TAM; i++) {
        if(num[i]>mayor){
        	mayor = num[i];
		}
    }
	printf("El numero mayor es : %d: ", mayor);
    return 0; // Indica que todo ha funcionado correctamente
}

