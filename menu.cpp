#include <stdio.h>
#define TAM 10

int main() {
    float num[TAM];
    int i;
   
    // Leer las notas
    for(i = 0; i < TAM; i++) {
        printf("\nDime la nota del alumno %d: ", i + 1);
        scanf("%f", &num[i]);  // Usamos '%f' para leer un número de tipo float
    }

    int opcion;
    printf("\nElige una opción:\n");
    printf("1. Listar las notas\n");
    printf("2. Calcular la media de todos los valores\n");
    printf("3. Calcular la menor nota\n");
    printf("4. Calcular la mayor nota\n");
    scanf("%d", &opcion);
    
    switch(opcion) {
        case 1:
            // Listar las notas
            printf("\nNotas de los alumnos:\n");
            for(i = 0; i < TAM; i++) {
                printf("Nota del alumno %d: %.2f\n", i + 1, num[i]);  // Usamos %.2f para mostrar 2 decimales
            }
            break;

        case 2:
            // Calcular la media
            {
                float suma = 0;
                for(i = 0; i < TAM; i++) {
                    suma += num[i];  // Sumar las notas
                }
                float media = suma / TAM;
                printf("La nota media es: %.2f\n", media);  // Mostrar la media con 2 decimales
            }
            break;

        case 3:
            // Calcular la menor nota
            {
                float menor = num[0];
                for(i = 1; i < TAM; i++) {
                    if(num[i] < menor) {
                        menor = num[i];  // Actualizar si encontramos una nota menor
                    }
                }
                printf("La nota menor es: %.2f\n", menor);  // Mostrar la menor nota con 2 decimales
            }
            break;

        case 4:
            // Calcular la mayor nota
            {
                float mayor = num[0];
                for(i = 1; i < TAM; i++) {
                    if(num[i] > mayor) {
                        mayor = num[i];  // Actualizar si encontramos una nota mayor
                    }
                }
                printf("La nota mayor es: %.2f\n", mayor);  // Mostrar la mayor nota con 2 decimales
            }
            break;

        default:
            printf("Opción no válida.\n");
            break;
    }
    
    return 0; // Indica que todo ha funcionado correctamente
}

