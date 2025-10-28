#include <stdio.h>

#define TAM 31  

int main() {
    int num[TAM];
    int i;
   
    // Inicializamos el array para representar los d�as de diciembre
    for(i = 0; i < TAM; i++) {
        num[i] = i + 1; // D�as del 1 al 31
    }

    // Imprimir el t�tulo del mes
    printf("*** MES DE DICIEMBRE 2025 ***\n\n");

    // Imprimir los d�as de la semana
    printf("Lun Mar Mie Jue Vie Sab Dom\n");

    int primer_dia = 1;  


    
    for(i = 0; i < TAM; i++) {
        printf("%2d  ", num[i]);  
        
        
        if ((i + primer_dia) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");  // L�nea final para terminar el calendario

    return 0;
}

