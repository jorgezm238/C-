#include <stdio.h>

int main() {
    char buffer[50];
    FILE *fichero;

    fichero = fopen("fichero.txt", "r");

    if (fichero != NULL) {

        // Leemos una línea del fichero
        while(fgets(buffer, sizeof(buffer), fichero) != NULL){
        	
        printf("Estamos leyendo el fichero: %s\n", buffer);
        
        	
		}
fclose(fichero);
       


    } else {
        printf("Error al abrir el fichero.\n");
    }

    return 0;
}
