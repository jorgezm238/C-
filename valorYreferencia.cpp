#include<stdio.h>

//ver cambios en valor y referencia
void valor(int);
void referencia(int *);
// Función principal
int main() {
    int a= 5;
    
    printf("El valor original de la variable a es: %d\n", a);
    valor(a);
    printf("El valor de la variable a despues de la funcion valor es : %d\n", a);
    referencia(&a);
    printf("El valor de la variable a despues de la funcion de referencia es : %d\n", a);
    
    
    
    
    
    return 0; // Indica que todo ha funcionado correctamente
}
void valor(int a){
a = a+1;
printf("El valor dentro de valor es %d\n", a);
}


void referencia(int *a)
{
*a = *a+1;
printf("El valor dentro de referencia es %d\n", *a);
}
