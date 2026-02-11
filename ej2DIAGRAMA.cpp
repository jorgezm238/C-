#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // system

int main() {

    int n, i;        // n: cantidad de números a leer
                     // i: contador para el ciclo

    double x;        // x: guarda cada número ingresado por el usuario
    double mayor1;   // mayor1: el número más grande encontrado
    double segundoMayor;   // segundo número más grande

    // Pedimos cuántos números se van a ingresar
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    // Verificamos que se ingresen al menos dos números
    if (n < 2) {
        printf("Se necesitan al menos dos numeros.\n");
        system("pause");
        return 1;
    }

    // Leemos el primer número
    printf("Ingrese el primer numero: ");
    scanf("%lf", &x);

    // Inicializamos los dos mayores con el primer valor leído
    mayor1 = x;
    segundoMayor = x;

    // Ciclo para leer el resto de los números
    for (i = 2; i <= n; i++) {

        printf("Ingrese el numero %d: ", i);
        scanf("%lf", &x);

        if (x > mayor1) {
            segundoMayor = mayor1;
            mayor1 = x;
        }
        else if (x > segundoMayor && x < mayor1) {
            segundoMayor = x;
        }
    }

    // Mostramos los resultados
    printf("\nEl mayor es: %.2f", mayor1);
    printf("\nEl segundo mayor es: %.2f\n", segundoMayor);

    // Verificamos si los dos mayores son iguales
    if (mayor1 == segundoMayor) {
        printf("Los dos valores mas grandes son iguales.\n");
    }

    system("pause");   // <-- evita que se cierre el CMD
    return 0;
}
