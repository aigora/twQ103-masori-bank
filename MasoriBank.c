#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cuenta{
	
	char usuario[50];
	char clave[30];
    float dinero;
};


int main(){
	struct cuenta cliente[100];
	int n=0; // numero de clientes
	int k, x, j=0; // j=0 para comparar desde el primer usuario
	int comparar, comparar2, comparacion;
	int numusuario;
	int IBAN, entidad, oficina, control, numCuenta;
	int longitud=0, may=0, i=0;
	float ingreso, transferencia;
	char opcion, opcion2, opcion3,opcion5,opcion4;
	char comunidad;
	char user[50], password[50];
	char titular[50], pais[3];

	
	printf("\n");
	system("color 0B");
	
	printf("                                             BIENVENID@ A MASORI BANK");
	
	printf("\n");
	
		
	FILE*fichero;
		
	fichero = fopen("usuarios.txt", "a+"); 
	
	if(fichero == NULL) {
		printf("Error en la apertura de fichero");
		return -1;
	}
	while(fscanf(fichero, "%d\t%s\t%s",&n,cliente[n].usuario, cliente[n].clave)!=EOF){
		n++;
		if(n!=0){
			n=n-1; // Queremos que sume clientes según se van registrando no aquí
		}
	}
	fclose(fichero);
	
	printf ("  > I-Iniciar sesion\n");
	printf ("  > R-Registrarse\n"); 
	printf("\n");
	scanf("%c", &opcion3);
	fflush(stdin);
	system("cls");
	switch (opcion3){
		case 'I':
			if(n==0){
				printf("Todavia no hay ningun usuario registrado en el cajero. Cree un usuario antes.");
				break;
			}
			else{
				fichero=fopen("usuarios.txt","r");
				if(fichero==NULL){
					printf("Error en la apertura de fichero\n");
					return -1;
				}
				else{
					do{
						do{
							printf("\nUsuario: ");
							scanf("%s", user);
							// Comprobamos si el usuario introducido coincide con alguno de los registrados
							for(j=0;j<n;j++){
								comparar=strcmp(user, cliente[j].usuario);
								if(comparar==0){
									numusuario=j;
									break;
								}
								else if(j==n-1){
									printf("Usuario no registrado\n");
								}
							}
						}while(comparar==1||comparar==-1);
						
						do{
							printf("Clave: ");
							scanf("%s", password);
							// Se compara la contraseña introducida con la contraseña del usuario introducido
							comparar2=strcmp(password, cliente[numusuario].clave);
							if(comparar2==0){
								system("cls");
								printf("\n");						
								printf("Bienvenido/a %s\n", cliente[numusuario].usuario);
							}
						}while (comparar2==1||comparar2==-1);
					
						fclose(fichero);
						
					}while(fscanf(fichero,"%s\t%s", cliente[j].usuario, cliente[j].clave)!=EOF);
				}
				break;
			}
			
		case 'R': 
			printf("\nUsuario: ");
			gets(cliente[n].usuario); 
			
			fichero= fopen("usuarios.txt","r");
			if(fichero == NULL){
				printf("EL fichero no se ha podido abrir correctamente.\n");
				return -1;
			}
				
			for(x=0; x<=n; x++){
				while(fscanf(fichero,"%i  %s\t%s",&i+1,cliente[x].usuario, cliente[x].clave)!=EOF){
					comparacion=strcmp(cliente[x].usuario,cliente[n].usuario);
					if(comparacion==0){
						printf("Este usuario ya existe\n");
						return 0;
					}
					x++;
				}
			}

			do{
				printf("Introduzca una clave que contenga 8 caracteres y una mayuscula como minimo:\n");
				gets(cliente[n].clave);
				
				// Calcular longitud de la contraseña:
				while(cliente[n].clave[i] !='\0'){
					longitud++;
					i++;
			    }	
			    // Contador de mayúsculas
				for(i=0;i<=longitud;i++){
					if(cliente[n].clave[i]>='A' && cliente[n].clave[i]<='Z'){
						may++;
					}
				}
				if(longitud<8 || may==0){ 
					printf("La clave introducida no cumple los requisitos\n");
					printf("\n");	
				}	
			}while(longitud<8 || may==0);
		
			n++; // Se registra alguien y aumenta el contador de clientes
			
			fichero = fopen("usuarios.txt","w");
			if(fichero==NULL){
				printf("Error al abrir el fichero\n");
					return -1;
			}
			else{
				k=0;
				while(k<n){
					fprintf(fichero,"%d\t%s\t%s\n",k+1,cliente[k].usuario,cliente[k].clave); // Se imprimen los datos del nuevo usuario registrado (usuario y contraseña)
					k++;	
				}	
			}	
			fclose(fichero);
			break;
		default: printf("Opcion incorrecta");
			return 0;	
		}
	
	do{
		//system("cls");
		printf("\n");
		printf ("  > A-Cuenta\n");
		printf ("  > B-Buscar oficinas y cajeros cercanos\n");
		printf ("  > C-Realizar transferencia\n"); 
		printf ("  > D-Cerrar aplicacion\n");
		printf("\n");
		fflush(stdin);
		printf ("Introduzca la opcion que desea:\n");
		scanf("%c", &opcion);	
		system("cls");
			
		switch (opcion){
			// En esta opción el cliente podrá consultar el saldo de su cuenta o aumentarlo
			case 'A':
				printf("\n");
				printf("  (1) Consultar cuenta\n");
				printf("  (2) Ingresar dinero\n");
				fflush(stdin);
				printf ("Introduzca la opcion que desea:\n");
				scanf("%c", &opcion4);
				system("cls");
				
				switch (opcion4){
					case '1':
						printf("\nSu saldo actual es de: %.2f euros", cliente[numusuario].dinero);
						break;
					case '2':
						printf("\nIntroduzca la cantidad de dinero que desee ingresar: ");
						scanf("%f", &ingreso);
						cliente[numusuario].dinero=cliente[numusuario].dinero+ingreso;
						printf("\nEspere por favor...\n");
						Sleep(1000); //Temporizador
						printf("Ingreso realizado con exito\n");
						break;
					default:
						printf("\nOpcion incorrecta\n");
						break;
				}
				getch();
				system("cls");
				break;
			// Según la comunidad en la que se encuentre el cliente se muestran distintas ubicaciones de nuestras oficinas
			case 'B':
				printf("Introduzca la comunidad autonoma en la que se encuentra:\n");
				printf("\n");
				printf("  (a) Galicia\n  (b) Asturias\n  (c) Pais Vasco\n  (d) Cantabria\n  (e) Navarra\n  (f) Aragon\n  (g) La Rioja\n  (h) Catalunya\n");
				printf("  (i) Comunidad Valenciana\n  (j) Murcia\n  (k) Castilla y Leon\n  (l) Castilla La Mancha\n  (m) Madrid\n  (n) Andalucia\n  (o) Extremadura\n");
				printf(" \n");
				scanf("%s", &comunidad);
				system("cls");
				
				switch (comunidad){
					case 'a':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nRua do Franco (Santiago de Compostela)\n");
						break;
					case 'b':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nCalle Gascona (Oviedo)\n");
						printf("\nCalle Corrida (Gijon)\n");
						break;
					case 'c':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nPortu Kalea (Guipuzcua)\n");
						break;
					case 'd':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nCalle Lealtad (Santander)\n");
						break;
					case 'e':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nCuesta de Santo Domingo (Pamplona)\n");
						break;
					case 'f':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nPuerto Venecia (Zaragoza)\n");
						break;
					case 'g':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nMuro de Cervantes (Logrono)\n");
						break;
					case 'h':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nPaseo de Gracia (Barcelona)\n");
						printf("\nCall Jueu (Girona)\n");
						printf("\nPaseo 30 de Octubre (Tarragona)\n");
						break;
					case 'i':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nCalle de la Paz (Valencia)\n");
						printf("\nRambla de Alicante (Alicante)\n");
						break;
					case 'j':
						printf("\nBuscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("Barrio del Carmen\n");
						break;
					case 'k':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nCalle Calvario (Segovia)\n");
						printf("\nPlaza Mayor (Salamanca)\n");
						printf("\nCalle Ancha (Leon)\n");
						break;
					case 'l':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nPaseo de San Cristobal (Toledo)\n");
						printf("\nCalle Tejares (Albacete)\n");
						break;
					case 'm':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nLopez de Hoyos (Prosperidad)\n");
						printf("\nRonda de Valencia (Embajadores)\n");
						printf("\nAvenida de los claveles (Majadahonda)\n");
						break;
					case 'n':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nCalle Marques de Larios (Malaga)\n");
						printf("\nPlaza de la Virgen de los Reyes (Sevilla)\n");
						printf("Barriada de la Paz (Cadiz)\n");
						break;
					case 'o':
						printf("Buscando cajeros y oficinas, espere por favor...\n");
						Sleep(1000);
						printf("\nPlaza Mayor de Caceres\n");
						break;
					default:
						printf("Opcion incorrecta\n");																
				}  
				getch();
				system("cls");		
				break;
			// Con la tercera opción podrá realizar una transferencia a la persona que desee simplemente con introducir sus datos
			case 'C':
				printf("\n");
				fflush(stdin);
				printf("Introduzca los datos del receptor de la transferencia \n");
				
				printf(" \nTitular de la cuenta: ");
				gets(titular);
				
				fflush(stdin);
				printf(" \nCodigo del pais (mayusculas): ");
				gets(pais);
				
				printf(" \nIBAN (dos digitos): ");
				scanf("%d",&IBAN);
				
				printf(" \nEntidad (cuatro digitos): ");
				scanf("%d",&entidad);
				
				printf(" \nOficina (cuatro digitos): ");
				scanf("%d",&oficina);
				
				printf(" \nDigito de Control (dos digitos): ");
				scanf("%d",&control);
				
				printf(" \nNumero de Cuenta (diez digitos): ");
				scanf("%d",&numCuenta);
		
				printf("\nEstas seguro de que quiere realizar la transferencia a %s con codigo Iban %s %d  %d  %d  %d  %d \n",titular, pais, IBAN, entidad, oficina, control, numCuenta);
				printf("\n");
				fflush(stdin);
				
				printf("SI (S)   NO (N):\n");
				scanf("%c",&opcion5);
				system("cls");
				
				switch(opcion5){
					case 'S': 
						printf("Introduzca la cantidad que desea transferir:\n");
						scanf("%f",&transferencia);
						
						if(transferencia>ingreso){
							printf("No tiene sufuciente saldo para realizar la operacion\n");
						}
						else{
							cliente[numusuario].dinero=cliente[numusuario].dinero-transferencia;
							printf("Espere por favor...\n");
							Sleep(1000);
							printf("Transferencia realizada con exito\n");
						}
						break;
					case 'N':
						printf("Transferencia cancelada\n");
						break;
					default: 
						printf("\nOpcion incorrecta\n");
				}
			getch();
			system("cls");
			break;
			case 'D':
				printf("\nHasta la proxima!\n");
				return 0;
				break;
			default:
				printf("\nOpcion incorrecta\n");
				break;
		}
		//system("cls");
	}while(opcion!='D');
}





