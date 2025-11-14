#include<stdio.h>
 #include <windows.h>  // al inicio del archivo
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
    
    
    
    


printf("\nCerrando en 10 segundos...\n");
Sleep(100000); // 10000 milisegundos = 10 segundos
return 0;

   
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
