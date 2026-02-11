#include <stdio.h>

void leerEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrca, int *duracionMaxima);
int validarEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrca, int *duracionMaxima);
int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer):
int calcularIncrementoOrcas(int *orcas, int presasConsumidas, int presasNecesarias);
int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccion,int consumoOrca, int duracionMaxima);
void mostrarResultado(int focasFinal, int orcasFinal, int diasSimulados, int duracionMaxima);

int main(){








}

void leerEcosistema(int *focas, int *orcas,int *tasaReproduccion, int *consumoOrca, int *duracionMaxima){
    
    do{
        printf("Introduce el numero inicial de focas : ");
        scanf("%d", focas);
        printf("Introduce el numero inicial de orcas : ");
        scanf("%d", orcas);
        printf("Introduce la tasa de reproduccion: ");
        scanf("%d", tasaReproduccion);
        printf("Introduce el consumo de las orcas : ");
        scanf("%d", consumoOrca);
        printf("Introduce la duracion maxima : ");
        scanf("%d", duracionMaxima);


    } while (!validarEcosistema(*focas,*orcas,*tasaReproduccion,*consumoOrca,*duracionMaxima));
}

int validarEcosistema(int *focas,int *orcas,int *tasaReproduccion,int *consumoOrca,int *duracionMaxima){
    if (*focas >0 && *orcas>0 && *tasaReproduccion>0 && *consumoOrca>0 && *duracionMaxima>0){
        return 1;
    }
    return 0;
}

int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer){

if (focasHoy>focasAyer){
    tasaActual = (tasaActual*90)/100;
}
if (focasAyer<focasAyer){
    tasaActual= (tasaActual*110)/100;
}

return tasaActual;

}

int calcularIncrementoOrcas(int *orcas, int presasConsumidas, int presasNecesarias){
    if (presasConsumidas<presasNecesarias){
        *orcas = (orcas *95)/100
    }
    return *orcas;
}

int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccion,int consumoOrca, int duracionMaxima){
    int focasAyer;
    int diasSimulados=0;


    focasAyer= *focas;
    *focas = *focas + ((*focas) + (*tasaReproduccion))/100;
    *tasaReproduccion=ajustarTasaReproduccion(tasaReproduccion,focas,focasAyer);

    int presasNecesarias = *orcas * consumoOrca;


    while (*focas >0 && *orcas>0){
        if (*duracionMaxima>0 && diasSimulados>=*duracionMaxima )
        {
            break;
        }
        
    }


    return diasSimulados;
    
}

void mostrarResultado(int focasFinal, int orcasFinal,
                      int diasSimulados, int duracionMaxima) {

    printf("Tras %d dias: Focas=%d, Orcas=%d. ",
           diasSimulados, focasFinal, orcasFinal);

    if (diasSimulados == duracionMaxima) {
        printf("La simulacion finalizo por fin de duracion.\n");
    } else {
        printf("La simulacion finalizo por extincion.\n");
    }
}
