#include <stdio.h>

/* Lee valores iniciales válidos */
void leerEcosistema(int *focas, int *orcas, int *tasaReproduccion, int *consumoOrca, int *duracionMax) {
    int ok = 0;
    const char *msg;

    ok = 0; msg = "Introduce el numero de focas iniciales: ";
    while (!ok) {
        printf("%s", msg);
        scanf("%d", focas);
        if (*focas > 0) ok = 1;
        else msg = "Valor incorrecto. Introduce un numero de focas > 0: ";
    }

    ok = 0; msg = "Introduce el numero de orcas iniciales: ";
    while (!ok) {
        printf("%s", msg);
        scanf("%d", orcas);
        if (*orcas > 0) ok = 1;
        else msg = "Valor incorrecto. Introduce un numero de orcas > 0: ";
    }

    ok = 0; msg = "Introduce la tasa de reproduccion de las focas (%%, ej. 20): ";
    while (!ok) {
        printf("%s", msg);
        scanf("%d", tasaReproduccion);
        if (*tasaReproduccion >= 0) ok = 1;
        else msg = "Valor incorrecto. Introduce una tasa >= 0: ";
    }

    ok = 0; msg = "Introduce el consumo de orca (presas por orca y dia): ";
    while (!ok) {
        printf("%s", msg);
        scanf("%d", consumoOrca);
        if (*consumoOrca > 0) ok = 1;
        else msg = "Valor incorrecto. Introduce consumo > 0: ";
    }

    ok = 0; msg = "Introduce el numero de dias a simular (0 = hasta extincion): ";
    while (!ok) {
        printf("%s", msg);
        scanf("%d", duracionMax);
        if (*duracionMax >= 0) ok = 1;
        else msg = "Valor incorrecto. Introduce dias >= 0: ";
    }
}

/* Chequeo rápido de que todo siga en rangos válidos */
int validarEcosistema(int focas, int orcas, int tasaReproduccion, int consumoOrca, int duracionMax) {
    return (focas > 0 && orcas > 0 && tasaReproduccion >= 0 && consumoOrca > 0 && duracionMax >= 0);
}

/* Ajusta la tasa en base a si las focas suben o bajan */
int ajustarTasaReproduccion(int tasaActual, int focasHoy, int focasAyer) {
    if (focasHoy > focasAyer) tasaActual -= 10;
    else if (focasHoy < focasAyer) tasaActual += 10;

    /* Limites razonables para que no sea negativa ni dispareta */
    if (tasaActual < 0) tasaActual = 0;
    if (tasaActual > 100) tasaActual = 100;
    return tasaActual;
}

/* Modifica la población de orcas en función de presas */
void calcularIncrementoOrcas(int *orcas, int presasConsumidas, int presasNecesarias) {
    if (presasConsumidas < presasNecesarias) {
        *orcas = (int)(*orcas * 0.95); /* bajan un 5% */
    } else if (presasConsumidas > 2 * presasNecesarias) {
        *orcas = (int)(*orcas * 1.05); /* suben un 5% */
    }
}

/* Simulación principal: devuelve dias simulados (o hasta extinción) */
int calcularSimulacion(int *focas, int *orcas, int *tasaReproduccion, int consumoOrca, int duracionMax) {
    int diasSimulados = 0;
    int focasAyer = *focas;

    while (validarEcosistema(*focas, *orcas, *tasaReproduccion, consumoOrca, duracionMax) &&
           (duracionMax == 0 || diasSimulados < duracionMax)) {

        /* Reproducción de focas: crecimiento proporcional */
        *focas = *focas + (*focas * (*tasaReproduccion)) / 100;

        /* Orcas comen focas */
        int presasNecesarias = (*orcas) * consumoOrca;
        int presasConsumidas = presasNecesarias;            /* come lo que necesita si hay */
        if (presasConsumidas > *focas) presasConsumidas = *focas;  /* no puede comer mas que lo que hay */

        *focas -= presasConsumidas;
        if (*focas < 0) *focas = 0;

        /* Ajuste de tasa según subida/bajada */
        *tasaReproduccion = ajustarTasaReproduccion(*tasaReproduccion, *focas, focasAyer);
        focasAyer = *focas;

        /* Ajuste de orcas según disponibilidad de presas */
        calcularIncrementoOrcas(orcas, presasConsumidas, presasNecesarias);

        diasSimulados++;

        /* Parada temprana si hay extinción */
        if (*focas <= 0 || *orcas <= 0) break;
    }

    return diasSimulados;
}

void mostrarResultado(int focasFinal, int orcasFinal, int diasSimulados, int duracionMax) {
    if (orcasFinal <= 0 || focasFinal <= 0) {
        printf("Tras %d dias: Focas=%d, Orcas=%d. La simulacion finalizo por extincion.\n",
               diasSimulados, focasFinal, orcasFinal);
    } else if (duracionMax != 0 && diasSimulados >= duracionMax) {
        printf("Tras %d dias: Focas=%d, Orcas=%d. La simulacion finalizo por fin de duracion.\n",
               diasSimulados, focasFinal, orcasFinal);
    } else {
        printf("Tras %d dias: Focas=%d, Orcas=%d. (fin anticipado)\n",
               diasSimulados, focasFinal, orcasFinal);
    }
}

int main(void) {
    int focas, orcas, tasaReproduccion, consumoOrca, duracionMax;

    leerEcosistema(&focas, &orcas, &tasaReproduccion, &consumoOrca, &duracionMax);

    int diasSimulados = calcularSimulacion(&focas, &orcas, &tasaReproduccion, consumoOrca, duracionMax);

    mostrarResultado(focas, orcas, diasSimulados, duracionMax);

    /* Resumen final */
    printf("\nResumen:\n");
    printf("Focas: %d\n", focas);
    printf("Orcas: %d\n", orcas);
    printf("Tasa reproduccion focas: %d%%\n", tasaReproduccion);
    printf("Consumo orca (presas/dia): %d\n", consumoOrca);
    printf("Dias simulados: %d\n", diasSimulados);

    return 0;
}
