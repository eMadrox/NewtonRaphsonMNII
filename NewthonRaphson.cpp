#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo{
	float x;
	float y;
	float z;
	float error;
	struct nodo *sig;
}VECTOR;

char elec;
float er_rel;
int num_ite;
float tol;
int cont;
float er_act;

//PROTOTIPOS
VECTOR* crear_Nodo();
float calculoNR(VECTOR *xyz);
void calculoNR2(VECTOR *xyz);
float* matrizInversa3(float *aux);
float* matrizInversa2(float *aux);
void imprimirTabla(VECTOR *xyz);


int main()
{
	char opc, opc1;
	opc1 = '1';
	while(opc != '0')
	{
		system("cls");
		printf("\tBIENVENIDO A RESOLUCION DE SISTEMAS POR METODO DE NEWTON RHAPSON!!!\n");
		printf("\tPROGRAMA ELABORADO POR:\n\n");
		printf("\t-\n");
		printf("\t-GUZMAN MORENO ERICK MIGUEL\n");
		printf("\t-MORALES CAMPOS ISAAC ULISES\n");
		printf("\t-\n\n");
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
			
			VECTOR *xyz;
			
			switch(elec)
			{
				case '1':
					while(opc1 == '1')
					{
						system("cls");
						er_act = 100;
						xyz = crear_Nodo();
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
						while(er_act > tol && cont != num_ite)
						{
							calculoNR2(xyz);
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("TOLERANCIA = %f", tol);
						printf("\n==========================================\n");
						printf("|%-10s| |%-10s| |%-14s|", "X", "Y","Error Relativo");
						imprimirTabla(xyz);
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
						xyz = crear_Nodo();
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
						while(er_act > tol && cont != num_ite)
						{
							calculoNR2(xyz);
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("TOLERANCIA = %f", tol);
						printf("\n==========================================\n");
						printf("|%-10s| |%-10s| |%-14s|", "X", "Y","Error Relativo");
						imprimirTabla(xyz);
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
						xyz = crear_Nodo();
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
						while(er_act > tol && cont != num_ite)
						{
							calculoNR(xyz);
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("Z = %f\n", xyz->z);
						printf("TOLERANCIA = %f", tol);
						printf("\n=======================================================\n");
						printf("|%-10s| |%-10s| |%-10s| |%-10s|", "X", "Y", "Z", "Error Relativo");
						imprimirTabla(xyz);
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
						xyz = crear_Nodo();
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
						while(er_act > tol && cont != num_ite)
						{
							calculoNR(xyz);
						}
						printf("VALORES INICIALES:\n");
						printf("X = %f\n", xyz->x);
						printf("Y = %f\n", xyz->y);
						printf("Z = %f\n", xyz->z);
						printf("TOLERANCIA = %f", tol);
						printf("\n=======================================================\n");
						printf("|%-10s| |%-10s| |%-10s| |%-14s|", "X", "Y", "Z", "Error Relativo");
						imprimirTabla(xyz);
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

float calculoNR(VECTOR* xyz)
{
	while(xyz->sig != NULL)
	{
		xyz = xyz->sig;
	}
	xyz->sig = crear_Nodo();
	float *jacob = (float*)malloc(9*sizeof(float));
	
	float f1;
	float f2;
	float f3;
	
	if(elec == '3')
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
	if(elec == '4')
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
	float *inversa = matrizInversa3(jacob);
	
	xyz->sig->x = xyz->x-((inversa[0] * f1)+(inversa[1] * f2)+(inversa[2] * f3));
	xyz->sig->y = xyz->y - ((inversa[3] * f1) + (inversa[4] * f2) + (inversa[5] * f3));
	xyz->sig->z = xyz->z - ((inversa[6] * f1) + (inversa[7] * f2) + (inversa[8] * f3));
	
	float aux1;
	
	if(fabs(xyz->sig->x) > fabs(xyz->sig->y) && fabs(xyz->sig->x) > fabs(xyz->sig->z))
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
	
	if(fabs(xyz->sig->x - xyz->x) > fabs(xyz->sig->y - xyz->y) && fabs(xyz->sig->x - xyz->x) > fabs(xyz->sig->z - xyz->z))
	{
		xyz->sig->error = (fabs(xyz->sig->x - xyz->x))/aux1;
	}else
	{
		if(fabs(xyz->sig->y - xyz->y) > fabs(xyz->sig->x - xyz->x) && fabs(xyz->sig->y - xyz->y) > fabs(xyz->sig->z - xyz->z))
		{
			xyz->sig->error = (fabs(xyz->sig->y - xyz->y))/aux1;
		}else
		{
			xyz->sig->error = (fabs(xyz->sig->z - xyz->z))/aux1;
		}
	}
	
	cont++;
	er_act = xyz->sig->error;
}

void calculoNR2(VECTOR *xyz)
{
	while(xyz->sig != NULL)
	{
		xyz = xyz->sig;
	}
	
	xyz->sig = crear_Nodo();
	
	float *jacob = (float*)malloc(4*sizeof(float));
	float f1,f2;
	
	if(elec == '1')
	{
		jacob[0] =2*(xyz->x) + xyz->y;
		jacob[1] = xyz->x;
		jacob[2] = 3 * (xyz->y * xyz->y);
		jacob[3] = 1 + (6 * xyz->x * xyz->y);
		f1 = (xyz->x * xyz->x) + (xyz->x * xyz->y) - 10;
		f2 = xyz->y + (3 * xyz->x * (xyz->y * xyz->y)) - 50;
	}
	if(elec == '2')
	{
		jacob[0] = 2 * xyz->x;
		jacob[1] = 2 * xyz->y;
		jacob[2] = -exp(xyz->x);
		jacob[3] = -2;
		f1 = (xyz->x*xyz->x) + (xyz->y * xyz->y) - 9;
		f2 = (-exp(xyz->x)) - (2 * xyz->y) - 3;
	}
	
	float *inversa = matrizInversa2(jacob);
	
	xyz->sig->x = xyz->x - ((inversa[0] * f1) + (inversa[1] * f2));
	xyz->sig->y = xyz->y - ((inversa[2] * f1) + (inversa[3] * f2));
	
	float aux1;
	
	if(fabs(xyz->sig->x) > fabs(xyz->sig->y))
	{
		aux1 = fabs(xyz->sig->x);
	}else
	{
		aux1 = fabs(xyz->sig->y);
	}
	
	if(fabs(xyz->sig->x - xyz->x) > fabs(xyz->sig->y - xyz->y))
	{
		xyz->sig->error = (fabs(xyz->sig->x - xyz->x))/aux1;
	}else
	{
		xyz->sig->error = (fabs(xyz->sig->y - xyz->y))/aux1;
	}
	
	cont++;
	er_act = xyz->sig->error;
}

VECTOR* crear_Nodo()
{
	VECTOR *aux = (VECTOR*)malloc(sizeof(VECTOR));
	aux->x = 0;
	aux->y = 0;
	aux->z = 0;
	aux->error = 0;
	aux->sig = NULL;
	return aux;
}

float* matrizInversa2(float *aux)
{
	float *inv = (float*)malloc(4*sizeof(float));
	
	float det;
	
	det = (aux[0] * aux[3]) - (aux[2] * aux[1]);
	
	float *depaso = (float*)malloc(4*sizeof(float));
	
	inv[0] = aux[3]/det;
	inv[3] = aux[0]/det;
	inv[1] = (-(aux[1]))/det;
	inv[2] = (-(aux[2]))/det;
	
	return inv;
}

float* matrizInversa3(float *aux)
{
	float *inv = (float*)malloc(9*sizeof(float));
	float det = ((aux[0]*aux[4]*aux[8])+(aux[3]*aux[7]*aux[2])+(aux[6]*aux[1]*aux[5]))-((aux[3]*aux[1]*aux[8])+(aux[0]*aux[7]*aux[5])+(aux[6]*aux[4]*aux[2]));
	if(det == 0)
	{
		printf("La inversa no existe!!");
		return 0;
	}
	float Trasp[3][3];
	Trasp[0][0] = aux[0];
	Trasp[0][1] = aux[3];
	Trasp[0][2] = aux[6];
	Trasp[1][0] = aux[1];
	Trasp[1][1] = aux[4];
	Trasp[1][2] = aux[7];
	Trasp[2][0] = aux[2];
	Trasp[2][1] = aux[5];
	Trasp[2][2] = aux[8];
	
	float *adj = (float*)malloc(9*sizeof(float));
	adj[0] = ((Trasp[1][1]*Trasp[2][2])-(Trasp[2][1]*Trasp[1][2]));
	adj[1] = -((Trasp[1][0]*Trasp[2][2])-(Trasp[2][0]*Trasp[1][2]));
	adj[2] = ((Trasp[1][0]*Trasp[2][1])-(Trasp[2][0]*Trasp[1][1]));
	adj[3] = -((Trasp[0][1]*Trasp[2][2])-(Trasp[2][1]*Trasp[0][2]));
	adj[4] = ((Trasp[0][0]*Trasp[2][2])-(Trasp[2][0]*Trasp[0][2]));
	adj[5] = -((Trasp[0][0]*Trasp[2][1])-(Trasp[2][0]*Trasp[0][1]));
	adj[6] = ((Trasp[0][1]*Trasp[1][2])-(Trasp[1][1]*Trasp[0][2]));
	adj[7] = -((Trasp[0][0]*Trasp[1][2])-(Trasp[1][0]*Trasp[0][2]));
	adj[8] = ((Trasp[0][0]*Trasp[1][1])-(Trasp[1][0]*Trasp[0][1]));
	
	inv[0] = adj[0]/det;
	inv[1] = adj[1]/det;
	inv[2] = adj[2]/det;
	inv[3] = adj[3]/det;
	inv[4] = adj[4]/det;
	inv[5] = adj[5]/det;
	inv[6] = adj[6]/det;
	inv[7] = adj[7]/det;
	inv[8] = adj[8]/det;
	
	return inv;
}

void imprimirTabla(VECTOR *xyz)
{
	if(elec == '3' || elec == '4')
	{
		printf("\n=======================================================\n");
		printf("|%-10f| |%-10f| |%-10f| |%-14f|", xyz->x, xyz->y, xyz->z, xyz->error);
	}
	if(elec == '1' || elec == '2')
	{
		printf("\n==========================================\n");
		printf("|%-10f| |%-10f| |%-14f|", xyz->x, xyz->y, xyz->error);
	}
	if(xyz->sig != NULL)
	{
		imprimirTabla(xyz->sig);
	}
}

