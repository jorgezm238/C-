#include <stdio.h>
#define TAM 50


void leerHotel(int *capacidad, float *precioBase );
int validarHotel(int capacidad, float precioBase);
int checkIn(int *capacidad, int noches[TAM], char huesped[TAM][]);
float checkOut(int capacidad, float precioBase int *noches[TAM], char *huesped[TAM][]);

int main(){
int capacidad;
float precioBase;
int noches[TAM];
char huesped[TAM][50];


return 0;


}

void leerHotel(int *capacidad, float *precioBase ){
do{
    printf("Introduce el numero de habitaciones :");
    scanf("%d", capacidad);
    printf("Introduce el precio base :");
    scanf("%f", precioBase);


} while (!validarHotel(*capacidad,*precioBase));

    }

int validarHotel(int capacidad, float precioBase){
if (capacidad>0 && precioBase>0){
    return 1;
}

return 0;

}

int checkIn(int *capacidad, float *precioBase int *noches[TAM], char *huesped[TAM][]){


int i;
int cantidadNoches;
char nombre[];


for ( i = 0; i < capacidad; i++){
    if (noches[i]==0) {
        printf("Introduce tu nombre: ");
        scanf("%s",&nombre);

        int k=0;
        while (nombre[k] !='\0' ){
            
            huesped[i][k]=nombre[k];
            k++;
        }
        huesped[i][k]='\0';// asi se acaba el string
        
        do {
            printf("Introduce el numero de noches: ");
            scanf("%d", &cantidadNoches);
        } while (cantidadNoches <= 0);

            noches[i] = cantidadNoches;   // ya queda “ocupada”

            return i+1; //num de habit. asignadas
        }
        
    }   
    printf("No hay habitacion niger");
    return -1; //no hay habitacion libres
}

void iniciarHabitaciones(int noches[TAM], char huesped[TAM][],int capacidad){

    for (int i = 0; i < capacidad; i++){
        
        huesped[i][0]='\0';
        noches[i]= 0;
    }
    

}

int checkOut(int capacidad, float precioBase, int *noches[TAM], char *huesped[TAM][]){
    float importe;
    int i;
    int numHabitacion;

       printf("Introduce el numero de habitacion : ");
       scanf("%d",&numHabitacion);
        if (numHabitacion<1 || numHabitacion > capacidad){
            printf("ERROR");
            return -1.0f;
        }
        if (noches[numHabitacion-1]>0){
            importe=noches[numHabitacion-1] * precioBase;
            printf("El importe es de: %f ", importe);
            printf("El huesped: %s de la habitacion: %d que se ha quedado %d noches: ", huesped[numHabitacion-1], numHabitacion, noches[numHabitacion-1]);
            huesped[numHabitacion-1][0] = '\0';
            noches[numHabitacion-1] = 0;
            
        } 

return importe;
        
}


