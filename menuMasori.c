#include <stdio.h>


int main(){
	char opcion, opcion2;
	char ubicacion[100];
	
	printf("\n");
	printf("                                             BIENVENID@ A MASORI BANK");
	
	printf("\n");
	
	do{
		printf("\n");
		printf ("  > A-Consultar movimientos\n");
		printf ("  > B-Buscar oficinas y cajeros cercanos\n");
		printf ("  > C-Realizar transferencia\n");
		printf ("  > D-Configuracion del perfil\n");
		printf ("  > E-Cerrar aplicacion\n");
		printf("\n");
		fflush(stdin);
		printf ("Introduzca la opcion que desea:\n");
		scanf("%c", &opcion);
		
		switch (opcion){
			case 'A':
					printf("Estos son sus ultimos movimientos realizados:\n");
				break;
			case 'B':
					printf("Introduzca su ubicacion:\n");
					scanf("%s", ubicacion);
					printf("Buscando cajeros y oficinas, espere por favor...\n");
				break;
			case 'C':
					printf("Introduzca los datos del receptor de la transferencia \n");
				break;
			case'D':
					printf ("  > A-Cambiar datos:\n");
					printf ("  > B-Cerrar sesion:\n");
					fflush(stdin);
					printf("\n");
					printf ("Introduce la opcion:\n");
					scanf("%c", &opcion2);
				break;
			case 'E':
					printf ("Hasta la proxima!\n");
				break;
			default:
				printf("Opcion incorrecta\n");
		}
	} while (opcion != 'E');





}

