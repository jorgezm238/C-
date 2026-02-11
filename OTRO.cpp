#include <stdio.h>
#include <stdlib.h>   // NECESARIO para system("pause")

int main(){

    int n ,i;
    double x, mayor1, segundoMayor;

    printf("Introduce la cantidad de numeros que vas a introducir: ");
    scanf("%d", &n);

    if (n <= 2){
        printf("Tienes que escribir al menos 2 numeros\n");
        system("pause");
        return 1;
    }

    printf("Introduce el primer numero: ");
    scanf("%lf", &x);

    mayor1 = x;
    segundoMayor = x;

    for (i = 2; i <= n; i++){
        printf("Introduce el %d numero: ", i);
        scanf("%lf", &x);

        if (x > mayor1){
            segundoMayor = mayor1;
            mayor1 = x;
        }
        else if ((x > segundoMayor) && (x < mayor1)){
            segundoMayor = x;
        }
    }

    printf("El numero mayor es: %lf\n", mayor1);
    printf("El segundo mayor es : %lf\n", segundoMayor);

    if (mayor1 == segundoMayor){
        printf("Los 2 numeros identificados son iguales de grandes: %lf y %lf\n",
               mayor1, segundoMayor);
    }

    system("pause");   // ← ESTA LÍNEA evita que se cierre el CMD
    return 0;
}
