#include <stdio.h>
#define TAM 5

int main() {
    int numeros[TAM];
    int opcion;
    int suma;

    // Leer los números
    for (int i = 0; i < TAM; i++) {                 // <-- corregido
        printf("Introduce el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    do {
        printf("\n1- Mostrar todos\n2- Calcular suma\n3- Calcular promedio\n4- Mostrar numero mayor\n5- Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                for (int i = 0; i < TAM; i++)
                    printf("%d\n", numeros[i]);
                break;

            case 2:
                suma = 0;
                for (int i = 0; i < TAM; i++)
                    suma += numeros[i];
                printf("La suma es: %d\n", suma);
                break;

            case 3:
                suma = 0;
                for (int i = 0; i < TAM; i++)
                    suma += numeros[i];
                printf("El promedio es: %.2f\n", (float)suma / TAM);
                break;

            case 4: {
                int mayor = numeros[0];             // <-- corregido
                for (int i = 1; i < TAM; i++)
                    if (numeros[i] > mayor)
                        mayor = numeros[i];
                printf("El numero mayor es: %d\n", mayor);
                break;
            }

            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
