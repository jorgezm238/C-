#include <stdio.h>

/* =====================================================
   PROTOTIPOS DE FUNCIONES
   -----------------------------------------------------
   Sirven para que el compilador conozca las funciones
   antes de que se usen en main.
   ===================================================== */

void leerEcosistema(int *orcas, int *focas, int *tasaReproduccionFocas,
                    int *consumoOrca, int *duracionMaxima);

int validarEcosistema(int *orcas, int *focas, int *tasaReproduccionFocas,
                      int *consumoOrca, int *duracionMaxima);

int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer);

void calcularIncrementoOrcas(int *orcas, int presasConsumidas, int presasNecesarias);

int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccionFocas,
                       int consumoOrca, int duracionMaxima);

void mostrarResultado(int focasFinal, int orcasFinal,
                      int diasSimulados, int duracionMaxima);

/* =====================================================
   FUNCIÓN PRINCIPAL
   -----------------------------------------------------
   main NO contiene lógica.
   Solo:
   - declara variables
   - llama a funciones
   ===================================================== */

int main(void) {

    /* Variables del ecosistema */
    int orcas;
    int focas;
    int tasaReproduccionFocas;
    int consumoOrca;
    int duracionMaxima;
    int diasSimulados;

    /* 1) Leer los datos iniciales del ecosistema */
    leerEcosistema(&orcas, &focas, &tasaReproduccionFocas,
                   &consumoOrca, &duracionMaxima);

    /* 2) Ejecutar la simulación */
    calcularSimulacion(&focas, &orcas,
                        &tasaReproduccionFocas,
                        consumoOrca, duracionMaxima);

    /* 3) Mostrar el resultado final */
    mostrarResultado(focas, orcas, diasSimulados, duracionMaxima);
    printf("\nPulsa ENTER para salir...");
getchar(); // limpia el '\n' pendiente del último scanf
getchar(); // espera a que pulses ENTER

    return 0;
}

/* =====================================================
   leerEcosistema
   -----------------------------------------------------
   - Pide los valores iniciales al usuario
   - Repite mientras los datos no sean válidos
   - Usa punteros porque modifica variables de main
   ===================================================== */

void leerEcosistema(int *orcas, int *focas, int *tasaReproduccionFocas,
                    int *consumoOrca, int *duracionMaxima) {

    do {
        printf("Introduce el numero inicial de orcas: ");
        scanf("%d", orcas);

        printf("Introduce el numero inicial de focas: ");
        scanf("%d", focas);

        printf("Introduce la tasa de reproduccion base de las focas (%%): ");
        scanf("%d", tasaReproduccionFocas);

        printf("Introduce el consumo diario de focas por orca: ");
        scanf("%d", consumoOrca);

        printf("Introduce la duracion maxima de la simulacion (0 = hasta extincion): ");
        scanf("%d", duracionMaxima);

    } while (!validarEcosistema(orcas, focas, tasaReproduccionFocas,
                               consumoOrca, duracionMaxima));
}

/* =====================================================
   validarEcosistema 11.36   0.74976 0.47  0.40  1.86
   -----------------------------------------------------
   - Comprueba que los valores sean correctos
   - Devuelve 1 si son válidos, 0 si no
   ===================================================== */

int validarEcosistema(int *orcas, int *focas, int *tasaReproduccionFocas,
                      int *consumoOrca, int *duracionMaxima) {

    if (*orcas > 0 && *focas > 0 &&
        *tasaReproduccionFocas > 0 &&
        *consumoOrca > 0 &&
        *duracionMaxima >= 0) {

        return 1;
    }
    return 0;
    
}

/* =====================================================
   ajustarTasaReproduccion
   -----------------------------------------------------
   - Recibe valores por copia
   - Ajusta la tasa según la evolución de las focas
   - Devuelve la nueva tasa
   ===================================================== */

int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer) {

    if (focasHoy > focasAyer) {
        /* Si las focas aumentan, la tasa baja un 10% */
        tasaActual = tasaActual * 90 / 100;
    }
    else if (focasHoy < focasAyer) {
        /* Si las focas disminuyen, la tasa sube un 10% */
        tasaActual = tasaActual * 110 / 100;
    }

    return tasaActual;
}

/* =====================================================
   calcularIncrementoOrcas
   -----------------------------------------------------
   - Modifica la población de orcas
   - Usa puntero porque cambia el valor original
   ===================================================== */

void calcularIncrementoOrcas(int *orcas, int presasConsumidas, int presasNecesarias) {

    if (presasConsumidas < presasNecesarias) {
        /* Si no hay suficiente comida, las orcas disminuyen un 5% */
        *orcas = (*orcas * 95) / 100;
    }
}

/* =====================================================
   calcularSimulacion
   -----------------------------------------------------
   - Simula el ecosistema día a día
   - Termina por extinción o por fin de duración
   - Devuelve el número de días simulados
   ===================================================== */

int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccionFocas,
                       int consumoOrca, int duracionMaxima) {

    int diasSimulados = 0;

    /* Mientras haya focas y orcas vivas */
    while (*focas > 0 && *orcas > 0) {

        /* Fin por duración */
        if (duracionMaxima > 0 && diasSimulados >= duracionMaxima) {
            break;
        }

        /* Guardamos las focas del día anterior */
        int focasAyer = *focas;

        /* Reproducción de focas */
        *focas = *focas + (*focas * (*tasaReproduccionFocas)) / 100;

        /* Ajuste de la tasa */
        *tasaReproduccionFocas =
            ajustarTasaReproduccion(*tasaReproduccionFocas, *focas, focasAyer);

        /* Consumo de focas por las orcas */
        int presasNecesarias = (*orcas) * consumoOrca;

        int presasConsumidas = presasNecesarias;
        if (presasConsumidas > *focas) {
            presasConsumidas = *focas;
        }

        *focas = *focas - presasConsumidas;

        /* Ajuste de orcas */
        calcularIncrementoOrcas(orcas, presasConsumidas, presasNecesarias);

        /* Se ha simulado un día más */
        diasSimulados++;
    }

    return diasSimulados;
}

/* =====================================================
   mostrarResultado
   -----------------------------------------------------
   - Muestra el resultado final
   - Decide si terminó por extinción o por duración
   ===================================================== */

void mostrarResultado(int focasFinal, int orcasFinal,
                      int diasSimulados, int duracionMaxima) {

    if (focasFinal <= 0 || orcasFinal <= 0) {
        printf("Tras %d dias: Focas=%d, Orcas=%d. "
               "La simulacion finalizo por extincion.\n",
               diasSimulados, focasFinal, orcasFinal);
    }
    else {
        printf("Tras %d dias: Focas=%d, Orcas=%d. "
               "La simulacion finalizo por fin de duracion.\n",
               diasSimulados, focasFinal, orcasFinal);
    }
}
