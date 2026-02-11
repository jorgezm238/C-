#include <stdio.h>

/* PROTOTIPOS */
void leerFecha(int *dia, int *mes, int *anio);
int validarFecha(int dia, int mes, int anio);
int calcularDias(int dia, int mes, int anio);
int anioBisiesto(int anio);
void mostrarResultado(int dia, int mes, int anio, int diaSemana);

/* MAIN */
int main() {

    int dia, mes, anio;
    int diaSemana;

    leerFecha(&dia, &mes, &anio);

    

    mostrarResultado(dia, mes, anio, diaSemana);

    printf("\nPulsa ENTER para salir...");
    getchar();
    getchar();

    return 0;
}

/* FUNCIONES */

void leerFecha(int *dia, int *mes, int *anio) {
    do {
        printf("Introduce el dia (1-31): ");
        scanf("%d", dia);

        printf("Introduce el mes (1-12): ");
        scanf("%d", mes);

        printf("Introduce el año (> 2023): ");
        scanf("%d", anio);

        if (!validarFecha(*dia, *mes, *anio))
            printf("Fecha incorrecta, vuelve a intentarlo.\n");

    } while (!validarFecha(*dia, *mes, *anio));
}

int validarFecha(int dia, int mes, int anio) {

    if (anio <= 2023) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1 || dia > 31) return 0;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return 0;

    if (mes == 2) {
        if (anioBisiesto(anio)) {
            if (dia > 29) return 0;
        } else {
            if (dia > 28) return 0;
        }
    }

    return 1;
}

int anioBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int calcularDias(int dia, int mes, int anio) {

    int totalDias = 0;
    int i;

    /* Años completos */
    for (i = 2023; i < anio; i++) {
        if (anioBisiesto(i))
            totalDias += 366;
        else
            totalDias += 365;
    }

    /* Meses completos del año actual */
    int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for (i = 1; i < mes; i++) {
        totalDias += diasMes[i - 1];
        if (i == 2 && anioBisiesto(anio))
            totalDias += 1;
    }

    /* Días del mes actual */
    totalDias += dia;

    /* Ajuste para que 01/01/2023 sea día 0 */
    totalDias -= 1;

    return totalDias;
}

int calcularDiaSemana(int dia, int mes, int anio, int diaSemana){
    diaSemana = calcularDias(dia, mes, anio) % 7;
    if (diaSemana == 0)
        diaSemana = 7;

return diaSemana;
}


void mostrarResultado(int dia, int mes, int anio, int diaSemana) {

    diaSemana = calcularDiaSemana(dia,mes,anio,diaSemana);
    char *letraSemana[] = {
        //"ERROR",
        "Lunes",
        "Martes",
        "Miercoles",
        "Jueves",
        "Viernes",
        "Sabado",
        "Domingo"
    };

    printf("\nEl dia %02d/%02d/%d sera %s",
           dia, mes, anio, letraSemana[diaSemana-1]);
}
