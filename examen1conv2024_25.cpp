// ejemplo solucion examen

#include<stdio.h>

#define TAM 500

void leerHotel(int *capacidad,float *precioBase);
int validarHotel(int capacidad,float precioBase);
void mostrarHotel(int capacidad,float precioBase, int noches[], char huesped[TAM][]);

int checkIn(int noches[], char huesped[TAM][],int capacidad);
float checkOut(int noches[], char huesped[TAM][],int capacidad, float precioBase);

int main(){
	int capacidad;
	int opcion;
	float precioBase;
	int noches[TAM];
	char huesped[TAM][50];
	// llamamos a la funcion para configurar el hotel
	leerHotel(&capacidad, &precioBase);
	//creamos un menu, que se repetira hasta que el usuario quiera salir
	do{
		printf("Menu");
		printf("1.- Checking");
		printf("2.- Chekout");
		printf("3. Mostrar estado del hotel");
		printf("0.- Salir");
		printf("Selecciona una opcion");
		scanf("%d", &opcion);
		//evaluamos la opcion seleccionada
		switch(opcion){
			case 1:
				checkIn(noches,huesped,capacidad);
				break;
			case 2:
				checkOut(noches,huesped,capacidad,precioBase);
				break;
			case 3:
				mostrarHotel(capacidad,precioBase, noches, huesped);
				break;
			default:
				break;
		}
	
	}while(opcion!=0);
	
	return 0;

}

void leerHotel(int *capacidad,float *precioBase){
//	preguntamos mediante un bucle los valores
	do{
		printf("Dime numero de habitaciones");
		scanf("%d", capacidad);
		printf("Dime el precio de cada habitacion");
		scanf("%f", precioBase);
		//llamamos a otra funcion para validar datos
	}while( !validarHotel(*capacidad, *precioBase) );
}

int validarHotel(int capacidad,float precioBase){
	//si son correctos devolvemos 1 y salimos
	if(capacidad > 0  && precioBase > 0 ){
		return 1;
	}
	return 0;
}

void mostrarHotel(int capacidad,float precioBase, int noches[], char huesped[TAM][]){
	int i; 
	int ocupadas=0;
	printf("La capacidad del hotel es: %d", capacidad);
	printf("El precio base del hotel es: %g", precioBase);
	
	for(i=0; i<capacidad; i++){
		printf("En la habitacion %d esta reservada para %d noches", i+1,noches[i]);
		// si el elemento del vector tiene un valor mayor a cero, es que esta ocupada, incremeneto en contador.
		if(noches[i]>0){
			ocupadas++;
			printf("Reservada por %s", huesped[i]);
		}
	}
	printf("El numero de habitaciones libres es %d", capacidad-ocupadas);
	printf("El numero de habitaciones ocupadas es %d", ocupadas);
	
}


int checkIn(int noches[], char huesped[TAM][],int capacidad){

	int i, ocupadas=0, libres, nochesHuesped;
	char nombre[50];

	
	for(i=0; i<capacidad; i++){
		if(noches[i]>0){ 
			ocupadas++;
		}
	} 
	libres=capacidad-ocupadas;
	if(libres <= 0){
		return -1;
	}
	do{
	printf("Cuantas noches te vas a quedar?");
	scanf("%d", &nochesHuesped);
	}while(nochesHuesped<1);
	
	printf("Cual es tu nombre?");
	scanf("%s", nombre);
	
	for(i=0; i<capacidad; i++){
		if(noches[i]<1){ 
			noches[i]=nochesHuesped;
			huesped[i]=nombre;
			return i+1; 
		}
	} 
	

}


float checkOut(int noches[], char huesped[TAM][],int capacidad, float precioBase){
	int numerohabitacion;
	float importe;
	
	printf("Cual es tu numero de habitacion?");
	scanf("%d", &numerohabitacion);
	
	if(noches[numerohabitacion-1] < 1){
		printf("La habitacion no esta ocupàda, revisa el numero");
		return -1;
	}
	importe=precioBase*noches[numerohabitacion-1];
	printf("El importe que el huesped tiene que abonar es de %.2f", importe);
	
	noches[numerohabitacion-1]=0;
	huesped[numerohabitacion-1]="\0";
	
	return importe;

}
