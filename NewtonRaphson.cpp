/*
	===================================================================================================================================================
	FACULTAD DE ESTUDIOS SUPERIORES ACATLÁN
	UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO
	
	MÉTODOS NUMÉRICOS II
	GRUPO: 2451
	PROFESORA CARRILLO RAMIREZ TERESA
	AÑO 2022
	
	MÉTODO DE NEWTON RAPHSON PARA SISTEMAS DE ECUACIONES NO LINEALES 3x3 Y 2x2
	
	PROGRAMA REALIZADO POR:
	-ACEVEDO SANCHEZ DULCE NAOMI
	-GUZMAN MORENO ERICK MIGUEL
	-MENESES ARREOLA JOSE LUIS
	-MORALES CAMPOS ISAAC ULISES
	==================================================================================================================================================
*/

#include <stdio.h> //Funciones principales (printf,scanf,etc)
#include <stdlib.h> //Funciones system y malloc
#include <math.h> //Funcion fabs(valor absoluto)

typedef struct nodo{ //En estos nodos almacenamos todas las posiciones y su error relativo en cada iteracion
	float x;
	float y;
	float z;
	float error;
	struct nodo *sig;
}VECTOR;

char elec; 
float er_rel; 
int num_ite; //Numero de iteraciones esperado por el usuario
float tol; //Error relativo esperado por el usuario
int cont; //Contador para saber cuantas iteraciones se llevan hasta el momento
float er_act; //Aqui se almacena el valor del ultimo error relativo registrado

//PROTOTIPOS
VECTOR* crear_Nodo(); //Se genera un nodo nuevo cada que se requiera
float calculoNR(VECTOR *xyz); //Hace el calculo del Método de Newton Raphson para sistemas 3x3
void calculoNR2(VECTOR *xyz); //Hace el calculo del Método de Newton Raphson para sistemas 2x2
float* matrizInversa3(float *aux); //Calcula la matriz inversa para sistemas 3x3
float* matrizInversa2(float *aux); //Calcula la matriz inversa para sistemas 2x2
void imprimirTabla(VECTOR *xyz); //Imprime los resultados en pantalla


int main()
{
	char opc, opc1;
	opc1 = '1';
	while(opc != '0')
	{
		system("cls");
		printf("\tBIENVENIDO A RESOLUCION DE SISTEMAS POR METODO DE NEWTON RHAPSON!!!\n");
		printf("\tPROGRAMA ELABORADO POR:\n\n");
		printf("\t-ACEVEDO SANCHEZ DULCE NAOMI\n");
		printf("\t-GUZMAN MORENO ERICK MIGUEL\n");
		printf("\t-MENESES ARREOLA JOSE LUIS\n");
		printf("\t-MORALES CAMPOS ISAAC ULISES\n\n");
		printf("\t=====================================================================\n");
		printf("\tSELECCIONE UNA OPCION:\n");
		printf("\t1.-RESOLVER SISTEMA\n");
		printf("\t0.-SALIR DEL PROGRAMA\n\n");
		printf("\tSELECCION: ");
		fflush(stdin);
		scanf("%c", &opc);
		if(opc == '2')
		{
			break;
		}
		while(opc == '1')
		{
			system("cls");
			printf("\tESCOJA UN SISTEMA DE ECUACIONES PARA RESOLVER:\n");
			printf("\t================================================================\n");
			printf("\t1.- SISTEMA #1\n\n");
			printf("\tf1(x,y) = (x^2) + xy - 10 = 0\n");
			printf("\tf2(x,y) = y + 3x(y^2) - 50 = 0\n");
			printf("\t================================================================\n");
			printf("\t2.- SISTEMA #2\n\n");
			printf("\tf1(x,y) = (x^2) + (y^2) - 9 = 0\n");
			printf("\tf2(x,y) = (-e^x) - 2y - 3 = 0\n");
			printf("\t================================================================\n");
			printf("\t3.- SISTEMA #3\n\n");
			printf("\tf1(x,y,z) = 2(x^2) - 4x + (y^2) + 3(z^2) + 6z + 2 = 0\n");
			printf("\tf2(x,y,z) = (x^2) + (y^2) - 2y + 2(z^2) - 5 = 0\n");
			printf("\tf3(x,y,z) = 3(x^2) - 12x + (y^2) - 3(z^2) + 8 = 0\n");
			printf("\t================================================================\n");
			printf("\t4.- SISTEMA #4\n\n");
			printf("\tf1(x,y,z) = (x^2) - 4x + (y^2) = 0\n");
			printf("\tf2(x,y,z) = (x^2) - x - 12y + 1 = 0\n");
			printf("\tf3(x,y,z) = 3(x^2) - 12x + (y^2) - 3(z^2) + 8 = 0\n");
			printf("\t================================================================\n");
			printf("\tSELECCION: ");
			fflush(stdin);
			scanf("%c", &elec);
			
			VECTOR *xyz; //Se genera el vector inicial
			
			switch(elec)
			{
				case '1':
					while(opc1 == '1')
					{
						system("cls");
						er_act = 100;
						xyz = crear_Nodo();//Se genera el primer nodo para almacenar los datos iniciales
						cont = 1;
						printf("\tIndique los valores iniciales: \n");
						printf("\tX = ");
						scanf("%f", &xyz->x);
						printf("\n\tY = ");
						scanf("%f", &xyz->y);
						printf("\t================================================================\n");
						printf("\tIndique el numero maximo de iteraciones: ");
						scanf("%d", &num_ite);
						printf("\n\n\tIndique la tolerancia(Ej. 0.00005): ");
						scanf("%f", &tol);
						system("cls");
						while(er_act > tol && cont != num_ite) //Hasta que el error relativo sea menor o hasta que se llegue al máximo número de iteraciones
						{
							calculoNR2(xyz); //Calculamos el vector solución para un sistema 2x2
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("TOLERANCIA = %f", tol);
						printf("\n==========================================\n");
						printf("|%-10s| |%-10s| |%-14s|", "X", "Y","Error Relativo");
						imprimirTabla(xyz); //Imprimimos los resultados en pantalla
						printf("\n==========================================\n");
						system("pause");
						system("cls");
						printf("\tDesea cambiar los datos de entrada para una nueva raiz?\n");
						printf("\t1.-SI\n");
						printf("\t2-NO\n");
						printf("\tSELECCION: ");
						fflush(stdin);
						scanf("%c", &opc1);
					}
					break;	
				case '2':
					while(opc1 == '1')
					{
						system("cls");
						er_act = 100;
						xyz = crear_Nodo(); //Se genera el primer nodo para almacenar los datos iniciales
						cont = 1;
						printf("\tIndique los valores iniciales: \n");
						printf("\tX = ");
						scanf("%f", &xyz->x);
						printf("\n\tY = ");
						scanf("%f", &xyz->y);
						printf("\t================================================================\n");
						printf("\tIndique el numero maximo de iteraciones: ");
						scanf("%d", &num_ite);
						printf("\n\n\tIndique la tolerancia(Ej. 0.00005): ");
						scanf("%f", &tol);
						system("cls");
						while(er_act > tol && cont != num_ite) //Hasta que el error relativo sea menor o hasta que se llegue al máximo número de iteraciones
						{
							calculoNR2(xyz);//Calculamos el vector solución para un sistema 2x2
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("TOLERANCIA = %f", tol);
						printf("\n==========================================\n");
						printf("|%-10s| |%-10s| |%-14s|", "X", "Y","Error Relativo");
						imprimirTabla(xyz); //Imprimimos los resultados en pantalla
						printf("\n==========================================\n");
						system("pause");
						system("cls");
						printf("\tDesea cambiar los datos de entrada para una nueva raiz?\n");
						printf("\t1.-SI\n");
						printf("\t2-NO\n");
						printf("\tSELECCION: ");
						fflush(stdin);
						scanf("%c", &opc1);
					}
					break;
				case '3':
					while(opc1 == '1')
					{
						system("cls");
						er_act = 100;
						xyz = crear_Nodo();//Se genera el primer nodo para almacenar los datos iniciales
						cont = 1;
						printf("\tIndique los valores iniciales: \n");
						printf("\tX = ");
						scanf("%f", &xyz->x);
						printf("\n\tY = ");
						scanf("%f", &xyz->y);
						printf("\n\tZ = ");
						scanf("%f", &xyz->z);
						printf("\t================================================================\n");
						printf("\tIndique el numero maximo de iteraciones: ");
						scanf("%d", &num_ite);
						printf("\n\n\tIndique la tolerancia(Ej. 0.00005): ");
						scanf("%f", &tol);
						system("cls");
						while(er_act > tol && cont != num_ite) //Hasta que el error relativo sea menor o hasta que se llegue al máximo número de iteraciones
						{
							calculoNR(xyz);//Calculamos el vector solución para un sistema 3x3
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("Z = %f\n", xyz->z);
						printf("TOLERANCIA = %f", tol);
						printf("\n=======================================================\n");
						printf("|%-10s| |%-10s| |%-10s| |%-10s|", "X", "Y", "Z", "Error Relativo");
						imprimirTabla(xyz); //Imprimimos los resultados en pantalla
						printf("\n=======================================================\n");
						system("pause");
						system("cls");
						printf("\tDesea cambiar los datos de entrada para una nueva raiz?\n");
						printf("\t1.-SI\n");
						printf("\t2-NO\n");
						printf("\tSELECCION: ");
						fflush(stdin);
						scanf("%c", &opc1);	
					}
					break;
				case '4':
					while(opc1 == '1')
					{
						system("cls");
						er_act = 100;
						VECTOR *xyz;
						xyz = crear_Nodo();//Se genera el primer nodo para almacenar los datos iniciales
						cont = 1;
						printf("\tIndique los valores iniciales: \n");
						printf("\tX = ");
						scanf("%f", &xyz->x);
						printf("\n\tY = ");
						scanf("%f", &xyz->y);
						printf("\n\tZ = ");
						scanf("%f", &xyz->z);
						printf("\t========================================================\n");
						printf("\tIndique el numero maximo de iteraciones: ");
						scanf("%d", &num_ite);
						printf("\n\n\tIndique la tolerancia(Ej. 0.00005): ");
						scanf("%f", &tol);
						system("cls");
						while(er_act > tol && cont != num_ite) //Hasta que el error relativo sea menor o hasta que se llegue al máximo número de iteraciones
						{
							calculoNR(xyz); //Calculamos el vector solución para un sistema 3x3
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("Z = %f\n", xyz->z);
						printf("TOLERANCIA = %f", tol);
						printf("\n=======================================================\n");
						printf("|%-10s| |%-10s| |%-10s| |%-14s|", "X", "Y", "Z", "Error Relativo");
						imprimirTabla(xyz); //Imprimimos los resultados en pantalla
						printf("\n===============================================================\n");
						system("pause");
						system("cls");
						printf("\tDesea cambiar los datos de entrada para una nueva raiz?\n");
						printf("\t1.-SI\n");
						printf("\t2-NO\n");
						printf("\tSELECCION: ");
						fflush(stdin);
						scanf("%c", &opc1);
					}
					break;
			}
			system("cls");
			printf("\tDesea resolver otro sistema de ecuaciones?\n");
			printf("\t1.-Si\n");
			printf("\t2.-No\n");
			fflush(stdin);
			scanf("%c", &opc);
			opc1 = '1';	
		}
		
	}
}

float calculoNR(VECTOR* xyz) //Hace el calculo del vector solucion para los sistemas 3x3
{
	while(xyz->sig != NULL) //Visitamos todos los nodos, hasta llegar al ultimo en el que tenemos información
	{
		xyz = xyz->sig;
	}
	xyz->sig = crear_Nodo(); //Generamos un nuevo nodo en la posicion siguiente, para almacenar la nueva estimación
	float *jacob = (float*)malloc(9*sizeof(float)); //Generamos un arreglo para guardar la matriz jacobiana
	
	float f1;
	float f2;
	float f3;
	
	if(elec == '3') //Obtenemos los valores de la matriz jacobiana y obtenemos las evaluaciones de las funciones en los nuevos puntos
	{
		jacob[0] = (4 * xyz->x) - 4;
		jacob[1] = 2 * xyz->y;
		jacob[2] = (6 * xyz->z) + 6;
		jacob[3] = 2 * xyz->x;
		jacob[4] = (2 * xyz->y) - 2;
		jacob[5] = 4 * xyz->z;
		jacob[6] = (6 * xyz->x) - 12;
		jacob[7] = 2 * xyz->y;
		jacob[8] =	-6 * xyz->z;
		f1 = (2 * (xyz->x * xyz->x))-(4*xyz->x)+(xyz->y*xyz->y)+(3*(xyz->z*xyz->z))+(6*xyz->z) + 2;
		f2 = (xyz->x * xyz->x) + (xyz->y * xyz->y) - (2 * xyz->y) + (2 * (xyz->z * xyz->z)) - 5;
		f3 = (3 * (xyz->x * xyz->x)) - (12 * xyz->x) + (xyz->y * xyz->y) - (3 * (xyz->z * xyz->z)) + 8;
	}
	if(elec == '4') //Obtenemos los valores de la matriz jacobiana y obtenemos las evaluaciones de las funciones en los nuevos puntos
	{
		jacob[0] = (2 * xyz->x) - 4;
		jacob[1] = 2 * xyz->y;
		jacob[2] = 0;
		jacob[3] = (2 * xyz->x) - 1;
		jacob[4] = -12;
		jacob[5] = 0;
		jacob[6] = (6 * xyz->x);
		jacob[7] = 2 * xyz->y;
		jacob[8] = -6 * xyz->z;
		f1 = (xyz->x * xyz->x) - (4 * xyz->x) + (xyz->y * xyz->y);
		f2 = (xyz->x * xyz->x) - xyz->x - (12 * xyz->y) + 1;
		f3 = (3 * (xyz->x * xyz->x)) - (12 * xyz->x) + (xyz->y * xyz->y) - (3 * (xyz->z * xyz->z)) + 8;
	}
	float *inversa = matrizInversa3(jacob); //Obtenemos la matriz inversa 3x3 a traves de la matriz jacobiana
	
	xyz->sig->x = xyz->x-((inversa[0] * f1)+(inversa[1] * f2)+(inversa[2] * f3)); //Asignamos el valor de la nueva estimacion del punto x al nodo que se genero con anterioridad
	xyz->sig->y = xyz->y - ((inversa[3] * f1) + (inversa[4] * f2) + (inversa[5] * f3)); //Asignamos el valor de la nueva estimacion del punto y al nodo que se genero con anterioridad
	xyz->sig->z = xyz->z - ((inversa[6] * f1) + (inversa[7] * f2) + (inversa[8] * f3)); //Asignamos el valor de la nueva estimacion del punto z al nodo que se genero con anterioridad
	
	float aux1;
	
	//AQUI SE EVALUA EL ERROR RELATIVO POR MEDIO DE LA NORMA ESPECTRAL
	if(fabs(xyz->sig->x) > fabs(xyz->sig->y) && fabs(xyz->sig->x) > fabs(xyz->sig->z)) //Se obtiene el valor del denominador
	{
		aux1 = fabs(xyz->sig->x);
	}else
	{
		if(fabs(xyz->sig->y) > fabs(xyz->sig->x) && fabs(xyz->sig->y) > fabs(xyz->sig->z))
		{
			aux1 = fabs(xyz->sig->y);
		}else
		{
			aux1 = fabs(xyz->sig->x);
		}
	}
	
	if(fabs(xyz->sig->x - xyz->x) > fabs(xyz->sig->y - xyz->y) && fabs(xyz->sig->x - xyz->x) > fabs(xyz->sig->z - xyz->z)) //Se obtiene el valor del numerador
	{
		xyz->sig->error = (fabs(xyz->sig->x - xyz->x))/aux1; //Se obtiene el error relativo
	}else
	{
		if(fabs(xyz->sig->y - xyz->y) > fabs(xyz->sig->x - xyz->x) && fabs(xyz->sig->y - xyz->y) > fabs(xyz->sig->z - xyz->z))
		{
			xyz->sig->error = (fabs(xyz->sig->y - xyz->y))/aux1; //Se obtiene el error relativo
		}else
		{
			xyz->sig->error = (fabs(xyz->sig->z - xyz->z))/aux1; //Se obtiene el error relativo
		}
	}
	
	cont++; //El contador de cuantas iteraciones se han realizado aumenta
	er_act = xyz->sig->error; //Se actualiza el valor del ultimo error evaluado
}

void calculoNR2(VECTOR *xyz) //Hace el calculo del vector solucion para los sistemas 3x3
{
	while(xyz->sig != NULL) //Visitamos todos los nodos, hasta llegar al ultimo en el que tenemos información
	{
		xyz = xyz->sig; 
	}
	
	xyz->sig = crear_Nodo(); //Generamos un nuevo nodo en la posicion siguiente, para almacenar la nueva estimación
	
	float *jacob = (float*)malloc(4*sizeof(float)); //Generamos un arreglo para la matriz jacobiana
	float f1,f2;
	
	if(elec == '1') //Obtenemos los valores de la matriz jacobiana y obtenemos las evaluaciones de las funciones en los nuevos puntos
	{
		jacob[0] =2*(xyz->x) + xyz->y;
		jacob[1] = xyz->x;
		jacob[2] = 3 * (xyz->y * xyz->y);
		jacob[3] = 1 + (6 * xyz->x * xyz->y);
		f1 = (xyz->x * xyz->x) + (xyz->x * xyz->y) - 10;
		f2 = xyz->y + (3 * xyz->x * (xyz->y * xyz->y)) - 50;
	}
	if(elec == '2') //Obtenemos los valores de la matriz jacobiana y obtenemos las evaluaciones de las funciones en los nuevos puntos
	{
		jacob[0] = 2 * xyz->x;
		jacob[1] = 2 * xyz->y;
		jacob[2] = -exp(xyz->x);
		jacob[3] = -2;
		f1 = (xyz->x*xyz->x) + (xyz->y * xyz->y) - 9;
		f2 = (-exp(xyz->x)) - (2 * xyz->y) - 3;
	}
	
	float *inversa = matrizInversa2(jacob); //Obtenemos la matriz inversa 3x3 a traves de la matriz jacobiana
	
	xyz->sig->x = xyz->x - ((inversa[0] * f1) + (inversa[1] * f2)); //Asignamos el valor de la nueva estimacion del punto x al nodo que se genero con anterioridad
	xyz->sig->y = xyz->y - ((inversa[2] * f1) + (inversa[3] * f2));//Asignamos el valor de la nueva estimacion del punto y al nodo que se genero con anterioridad
	
	float aux1;
	
	if(fabs(xyz->sig->x) > fabs(xyz->sig->y))//Se obtiene el valor del denominador
	{
		aux1 = fabs(xyz->sig->x);//Se obtiene el error relativo
	}else
	{
		aux1 = fabs(xyz->sig->y);//Se obtiene el error relativo
	}
	
	if(fabs(xyz->sig->x - xyz->x) > fabs(xyz->sig->y - xyz->y))
	{
		xyz->sig->error = (fabs(xyz->sig->x - xyz->x))/aux1;//Se obtiene el error relativo
	}else
	{
		xyz->sig->error = (fabs(xyz->sig->y - xyz->y))/aux1;//Se obtiene el error relativo
	}
	
	cont++;//El contador de cuantas iteraciones se han realizado aumenta
	er_act = xyz->sig->error; //Se actualiza el valor del ultimo error evaluado
}

VECTOR* crear_Nodo() //Aqui se asigna un tamaño y valores iniciales a los nodos
{
	VECTOR *aux = (VECTOR*)malloc(sizeof(VECTOR)); //Se reserva la memoria de un nodo
	aux->x = 0;
	aux->y = 0;
	aux->z = 0;
	aux->error = 0;
	aux->sig = NULL; //El siguiente nodo es nulo
	return aux; //Retorna el nodo
}

float* matrizInversa2(float *aux) //Aqui se calcula la matriz inversa para un sistema 2x2
{
	float *inv = (float*)malloc(4*sizeof(float)); //Este arreglo permitira almacenar la matriz inversa
	
	float det = (aux[0] * aux[3]) - (aux[2] * aux[1]); //Se calcula el determinante
	
	//Estos dos se invierten
	inv[0] = aux[3]/det;
	inv[3] = aux[0]/det;
	//En estos solo se cambia el signo
	inv[1] = (-(aux[1]))/det;
	inv[2] = (-(aux[2]))/det;
	
	return inv; //Se devuelve la matriz inversa
}

float* matrizInversa3(float *aux) //Aqui se calcula la matriz inversa para un sistema 2x2
{
	float *inv = (float*)malloc(9*sizeof(float));//Este arreglo permitira almacenar la matriz inversa
	float det = ((aux[0]*aux[4]*aux[8])+(aux[3]*aux[7]*aux[2])+(aux[6]*aux[1]*aux[5]))-((aux[3]*aux[1]*aux[8])+(aux[0]*aux[7]*aux[5])+(aux[6]*aux[4]*aux[2])); //Se calcula el determinante
	if(det == 0) //Se comprueba que el determinante sea diferente de 0
	{
		printf("La inversa no existe!!"); //Si es 0 la inversa de la matriz no existe
		return 0;
	}
	float Trasp[3][3]; //Este arreglo permitira almacenar la matriz transpuesta 
	Trasp[0][0] = aux[0];
	Trasp[0][1] = aux[3];
	Trasp[0][2] = aux[6];
	Trasp[1][0] = aux[1];
	Trasp[1][1] = aux[4];
	Trasp[1][2] = aux[7];
	Trasp[2][0] = aux[2];
	Trasp[2][1] = aux[5];
	Trasp[2][2] = aux[8];
	
	float *adj = (float*)malloc(9*sizeof(float)); //En este arreglo se calculara la adjunta de la matriz transpuesta
	adj[0] = ((Trasp[1][1]*Trasp[2][2])-(Trasp[2][1]*Trasp[1][2]));
	adj[1] = -((Trasp[1][0]*Trasp[2][2])-(Trasp[2][0]*Trasp[1][2]));
	adj[2] = ((Trasp[1][0]*Trasp[2][1])-(Trasp[2][0]*Trasp[1][1]));
	adj[3] = -((Trasp[0][1]*Trasp[2][2])-(Trasp[2][1]*Trasp[0][2]));
	adj[4] = ((Trasp[0][0]*Trasp[2][2])-(Trasp[2][0]*Trasp[0][2]));
	adj[5] = -((Trasp[0][0]*Trasp[2][1])-(Trasp[2][0]*Trasp[0][1]));
	adj[6] = ((Trasp[0][1]*Trasp[1][2])-(Trasp[1][1]*Trasp[0][2]));
	adj[7] = -((Trasp[0][0]*Trasp[1][2])-(Trasp[1][0]*Trasp[0][2]));
	adj[8] = ((Trasp[0][0]*Trasp[1][1])-(Trasp[1][0]*Trasp[0][1]));
	
	//Finalmente se calcula la matriz inversa dividiendo la adjunta entre el determinante
	inv[0] = adj[0]/det;
	inv[1] = adj[1]/det;
	inv[2] = adj[2]/det;
	inv[3] = adj[3]/det;
	inv[4] = adj[4]/det;
	inv[5] = adj[5]/det;
	inv[6] = adj[6]/det;
	inv[7] = adj[7]/det;
	inv[8] = adj[8]/det;
	
	return inv; //Se regresa la matriz inversa
}

void imprimirTabla(VECTOR *xyz) //Esta funcion imprime en pantalla los valores en cada posicion, asi como su error relativo
{
	if(elec == '3' || elec == '4')//Aqui se imprime la informacion para las matrices 3x3
	{
		printf("\n=======================================================\n");
		printf("|%-10f| |%-10f| |%-10f| |%-14f|", xyz->x, xyz->y, xyz->z, xyz->error);
	}
	if(elec == '1' || elec == '2')//Aqui se imprime la informacion para las matrices 2x2
	{
		printf("\n==========================================\n");
		printf("|%-10f| |%-10f| |%-14f|", xyz->x, xyz->y, xyz->error);
	}
	if(xyz->sig != NULL) //Hasta que no se termine la lista se seguira llamando asi misma la funcion para que imprima los valores en la siguiente posicion
	{
		imprimirTabla(xyz->sig);
	}
}

