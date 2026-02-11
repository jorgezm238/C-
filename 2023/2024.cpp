#include <stdio.h>
#define TAM 500



void leerHotel(int *capacidad, float *precioBase);
float validarHotel(int capacidad, float precioBase);
float checkIn(int capacidad, float precioBase,int noches[TAM],char huesped[TAM][50]);
float checkOut(int *capacidad,int noches[TAM],char huesped[TAM][50], int precioBase);
void mostrarHotel(int capacidad,int noches[TAM],char huesped[TAM][50], int precioBase);

int main(){
int capacidad;
float precioBase;
int noches[TAM];
char huesped[TAM][50];
int opcion;


do
{
    printf("Menu");
		printf("1.- Checking");
		printf("2.- Chekout");
		printf("3. Mostrar estado del hotel");
		printf("0.- Salir");
		printf("Selecciona una opcion");
		scanf("%d", &opcion);

switch (opcion)
{
case 1:
    leerHotel(&capacidad, &precioBase);
    break;

case 2:
    checkIn(capacidad, precioBase, noches, huesped);
    break;

case 3:
    checkOut(&capacidad, noches, huesped, precioBase);
    break;

case 4:
    mostrarHotel(capacidad, noches, huesped, precioBase);
    break;

case 0:
    break;

default:
    printf("Opcion no valida\n");
    break;
}
} while (opcion!=0);










    return 0;
}

void leerHotel(int *capacidad, float *precioBase){

    do
    {
    printf("Introduce el numero total de habitaciones: ");
    scanf("%d",capacidad);
    printf("Introduce el precio base por noche: ");
    scanf("%f", precioBase);
    } while (!validarHotel(*capacidad,*precioBase, ));
    
}

float validarHotel(int capacidad, int precioBase ){
    if (capacidad<=0 && precioBase<=0){
        return 0;
    }
        return 1;

}

float checkIn(int capacidad, float precioBase,int noches[TAM],char huesped[TAM][50]){

int i;
int habitacionOcupada = 0;
int habitacionLibre = 0;
int nochesHuesped;
char nombreHuesped[50];

for ( i = 0; i < capacidad; i++){
    if (noches[i]>0){
        habitacionOcupada++;
    }
}
habitacionLibre= capacidad - habitacionOcupada;
    if (habitacionLibre<=0){
        return -1;
}
do
{
    printf("Introduzca el numero de noches: ");
    scanf("%d",&nochesHuesped);

} while (nochesHuesped<1);
  
    printf("Introduzca su nombre: ");
    scanf("%s",&huesped);

for ( i = 0; i < capacidad; i++){
if (noches[i]<1){
    noches[i]=nochesHuesped;
    huesped[i]= nombreHuesped;
    return i + 1;
    }
}

}

float checkOut(int *capacidad,int noches[TAM],char huesped[TAM][50], int precioBase){

int numeroHabitacion;
float importe;

printf("Introduce el numero de tu habitacion: ");
scanf("%d",&numeroHabitacion);
if (noches[numeroHabitacion-1] < 1){
    
    printf("ERROR. Tu habitacion no es valida");
    return -1;
}
else 
importe = precioBase * noches[numeroHabitacion-1];
printf("El importe de tu estancia es de: %f ",importe);

noches[numeroHabitacion-1]=0;
huesped[numeroHabitacion-1][0]='\0'; //para borrar los caracteres

return importe;


}

void mostrarHotel(int capacidad,int noches[TAM],char huesped[TAM][50], int precioBase){
int i;
int habitacionesOcupadas=0;

printf("La capacidad del hotel es: %d", capacidad);
printf("El precio base del hotel es: %g", precioBase);

for ( i = 0; i < capacidad; i++){
   if (noches[i]>0){
    habitacionesOcupadas++;
    printf("Habitacion reservada por: %s",huesped[i][50]);
   }
}
printf("El numero de habitaciones libres es de : ", capacidad-habitacionesOcupadas);
printf("El numero de habitaciones ocupadas es de : ",habitacionesOcupadas);




}