/*Programa que escribe en forma de texto, un saludo, tras pedir datos al usuario*/

#include<stdio.h>

int main(){
char nombre[50];
FILE *fichero;

printf("Como te llamas?\n");
scanf("%s", nombre);

fichero=fopen("fichero.txt", "w");

if (fichero != NULL) {
fprintf(fichero, "Saludos %s", nombre);
fclose(fichero);


}
else{
	printf("Error al abrir el fichero.\n");
}

return 0;
}
