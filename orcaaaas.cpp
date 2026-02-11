#include <stdio.h>

void leerEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrcas, int *duracionMaxima);
int validarEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrcas, int *duracionMaxima);
int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer);
int calcularIncrementoOrcas(int *orcas,int presasConsumidas,int presasNecesarias);
int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccion, int consumoOrca, int duracionMaxima);

int main(){
int focas,orcas,tasaReproduccion,consumoOrcas,duracionMaxima,diasSimulados;

leerEcosistema(focas,orcas,tasaReproduccion,consumoOrcas,duracionMaxima);
calcularSimulacion(focas,orcas,tasaReproduccion);
mostrarResultado();






    return 0;
}
void leerEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrcas, int *duracionMaxima){
    do
    {
printf("Introduce el numero inicial de focas");
scanf("%d",focas);
printf("Introduce el numero de orcas");
scanf("%d",orcas);
printf("Introduce la tasa de reproduccion base de las focas");
scanf("%d", tasaReproduccion);
printf("Introduce el consumo diario de focas por orcas");
scanf("%d",consumoOrcas);
printf("Introduce la duracion maxima");
scanf("%d",duracionMaxima);

    } while (!validarEcosistema(*focas, *orcas, *tasaReproduccion, *consumoOrcas,*duracionMaxima));
}

int validarEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrcas, int *duracionMaxima){

if (*orcas<=0 ){
   return 0;
}

if (*focas<=0){
   return 0;
}
if (*tasaReproduccion<=0){
   return 0;
}
if (*consumoOrcas<=0){
   return 0;
}
if (*duracionMaxima<0){
   return 0;
}

return 1;
}

int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer){

    if (focasHoy>focasAyer) {
        tasaActual=(tasaActual*90)/100;
    }
    if (focasHoy<focasAyer){
        tasaActual=(tasaActual*110)/100;
    }
    
return tasaActual;
}


int calcularIncrementoOrcas(int *orcas,int presasConsumidas,int presasNecesarias){

if (presasConsumidas<presasNecesarias){
    *orcas= (*orcas*95)/100;
}


return *orcas;
}

int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccion, int consumoOrca, int duracionMaxima){

int diasSimulados=0;
while (focas>0 && orcas>0){
    if (duracionMaxima >0 && diasSimulados>=duracionMaxima){
        break;
    }

    int focasAyer = *focas;
    *focas = *focas + ((*focas) * (*tasaReproduccion))/100;

    *tasaReproduccion=ajustarTasaReproduccion(tasaReproduccion,focas,focasAyer);
    

}








}