#include <stdio.h>

int main(){
	char nombre[20];
	char apellido1[20];
	char apellido2[20];
	//mnsje
	printf("Introduce tu nombre\n");
	scanf("%s", nombre);
		printf("Introduce tu primer apellido\n");
		scanf("%s", apellido1);
				printf("Introduce tu segundo apellido\n");
		scanf("%s", apellido2);
			printf("Hola %s %s %s, un placer saludarte\n", nombre,apellido1,apellido2);

	return 0; //sirve para decir al SO que todo a funcionado
}
