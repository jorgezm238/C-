#include <stdio.h>
#define TAM 10

int main() {
    int num[TAM];
    int i;
   
    // Leer los números
    for(i = 0; i < TAM; i++) {
        printf("\nDime el valor del número %d: ", i + 1);
        scanf("%d", &num[i]); // Usamos 'i' en lugar de 'TAM'
    }
  
    // Mostrar los números en orden inverso
    printf("\nLos números en orden inverso son: \n");
    for(i = TAM - 1; i >= 0; i--) {
        printf("%d ", num[i]); // Usamos 'num[i]' en lugar de '&num[TAM]'
    }

    return 0; // Indica que todo ha funcionado correctamente
}

