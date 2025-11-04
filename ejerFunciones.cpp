#include<stdio.h>



//prototipos (declaraciones de funciones)
//vamos a declarar la funcion suma , recibe 2 enteros y devuelve 1 entero
int suma(int,int);
//funcion principal
int main() {
	
	
int num1=15,num2=25, resultado;

//aqui llamamos a la función
resultado = suma(num1,num2);

printf("El resultado de la suma es: %d", resultado);







    return 0; // Indica que todo ha funcionado correctamente
    //fin de la funcion principal
}
int suma(int a, int b){
	int resultado;
	resultado=a+b;
	return resultado;
		}

