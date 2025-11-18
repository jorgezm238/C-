/* EXAMEN 2022-2023*/
#include <stdio.h>
#include <math.h>

#define Ca 5730
#define U 703800000
#define Ce 30
#define R 1602
#define TAM 10     // <-- tamaño del array como pediste

// PROTOTIPOS EXACTAMENTE COMO LOS QUIERES
void menu(int *);
void rellenatiempos(int *);
float porcentajeNucleosDesintegrados(int, int);
void muestra(int *, int *);

// PROGRAMA PRINCIPAL
int main() {
    int opcion;
    int tiempos[TAM];

    menu(&opcion);

    if (opcion == 5) {   // salir
        return 0;
    }

    rellenatiempos(tiempos);
    muestra(tiempos, &opcion);

    return 0;
}

// DEFINICIÓN DE FUNCIONES

void menu(int *opcion) {
    do {
        printf("\n*** MENU ***\n");
        printf("1- Carbono-14 (14C)\n");
        printf("2- Uranio-235 (235U)\n");
        printf("3- Cesio-137 (137Cs)\n");
        printf("4- Radio-226 (226Ra)\n");
        printf("5- Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", opcion);

        if (*opcion < 1 || *opcion > 5) {
            printf("Opcion incorrecta\n");
        }

    } while (*opcion < 1 || *opcion > 5);
}

void rellenatiempos(int *anhos) {
    for (int i = 0; i < TAM; i++) {
        do {
            printf("Dame el anho %d: ", i + 1);
            scanf("%d", &anhos[i]);

            if (anhos[i] <= 0) {
                printf("Valor no valido (debe ser mayor que 0).\n");
            }
        } while (anhos[i] <= 0);
    }
}

float porcentajeNucleosDesintegrados(int anhos, int elemento) {
    float periodo;

    switch (elemento) {
        case 1: periodo = Ca; break;
        case 2: periodo = U;  break;
        case 3: periodo = Ce; break;
        case 4: periodo = R;  break;
        default: return 0;
    }

    float periodos_transcurridos = (float)anhos / periodo;

    // porcentaje desintegrado = 100 - 100/(2^periodos)
    return 100 - (100 / pow(2, periodos_transcurridos));
}

void muestra(int *tiempos, int *elemento) {
    for (int i = 0; i < TAM; i++) {
        float p = porcentajeNucleosDesintegrados(tiempos[i], *elemento);
        printf("En %d anhos se ha desintegrado el %.2f%% de nucleos.\n",
               tiempos[i], p);
    }
}
