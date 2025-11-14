#include <stdio.h>
#define TAM 10

int main() {
    int num[TAM];
    int i;
   
    // Leer los n�meros
    for(i = 0; i < TAM; i++) {
        printf("\nDime el valor del numero %d: ", i + 1);
        scanf("%d", &num[i]); // Usamos 'i' en lugar de 'TAM'
    }
  
    // Mostrar los n�meros en orden inverso
    printf("\nLos numeros en orden inverso son: \n");
    for(i = TAM - 1; i >= 0; i--) {
        printf("%d ", num[i]); // Usamos 'num[i]' en lugar de '&num[TAM]'
    }

    return 0; // Indica que todo ha funcionado correctamente
}

