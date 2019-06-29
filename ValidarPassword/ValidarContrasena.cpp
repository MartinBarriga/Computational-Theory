
/*
Longitud de más de 8 caracteres.
Letras mayúsculas (de la A a la Z) -> Por lo menos uno
Letras minúsculas (de la a a la z) -> Por lo menos uno
Números (del 0 al 9) -> Por lo menos uno
Símbolos no alfanuméricos: ` ~ ! @ # $ % ^ & * ( ) _ + - = { } | [ ] \ : " ; ' < > ? , . / -> Por lo menos uno
No escribir 2 o más caracteres identicos colocados de forma consecutiva, juntos (*aa,abbZ,993,ñ122b?)
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define REGLAS 6
#define ErrorLong 0
#define ErrorMay 1
#define ErrorMin 2
#define ErrorNum 3
#define ErrorSimb 4
#define ErrorCons 5
void longitud (char*, int*, int*);
void mayusculas_minusculas_numeros_simbolos(char *, int*, int*);
void caracteres_consecutivos(char*, int*, int*);

int main()
{
	int errores[REGLAS]={0,0,0,0,0,0};
	int existenciaDeError, i;
	char *contra = (char *) malloc (sizeof(char));
	cout << "Introduce la contrasenia: ";
	do{
		existenciaDeError = 0;
		for(i = 0; i < REGLAS; i++) errores[i] = 0;
		cin >> contra;
		cout << contra;
		printf("%ld\n", strlen(contra));
		longitud(contra, errores, &existenciaDeError);
		mayusculas_minusculas_numeros_simbolos(contra, errores, &existenciaDeError);
		caracteres_consecutivos(contra, errores, &existenciaDeError);
		if(existenciaDeError == 1) printf("\n*Error* Contrasena Invalida.\n");
		for(i = 0; i < REGLAS; i++)
		{
			if( (i == ErrorLong) && (errores[ErrorLong] == 1) ) printf("La longitud de la contrasena debe ser de mas de 8 caracteres.\n");
			if( (i == ErrorMay) && (errores[ErrorMay] == 1) ) printf("La contrasena debe contener al menos una letra en mayuscula.\n");
			if( (i == ErrorMin) && (errores[ErrorMin] == 1) ) printf("La contrasena debe contener al menos una letra en minuscula.\n");
			if( (i == ErrorNum) && (errores[ErrorNum] == 1) ) printf("La contrasena debe contaner al menos un numero.\n");
			if( (i == ErrorSimb) && (errores[ErrorSimb] == 1) ) printf("La contrasena debe contener al menos un simbolo no alfanumerico.\n");
			if( (i == ErrorCons) && (errores[ErrorCons] == 1) ) printf("La contrasena no puede tener dos caracteres identicos colocados de forma consecutiva.\n");
		}
		if(existenciaDeError == 1) printf("\n\nIntroduce una contrasena valida: " );
		else printf("\nLa contrasena cumple con todos los requisitos. Contrasena validada con exito.");
	} while(existenciaDeError == 1);	
	return 0;
}

void longitud(char *contra, int *errores, int *existenciaDeError)
{
	if(strlen(contra) < 9) 
	{	errores[ErrorLong] = 1;
		*existenciaDeError = 1;
	}	
}

void mayusculas_minusculas_numeros_simbolos(char *contra, int *errores, int *existenciaDeError)
{
	int banderaMay = 0,banderaMin = 0,banderaNum = 0,banderaSimb = 0 ;
	for(int i = 0; i < strlen(contra); i++)
	{
		if( (contra[i] > 64) && (contra[i] < 91)) banderaMay = 1;
		else if( (contra[i] > 96) && (contra[i] < 123) ) banderaMin = 1;
		else if( (contra[i] > 47) && (contra[i] < 58) ) banderaNum = 1;
		else banderaSimb = 1;
	}
	if(banderaMay == 0) {
		errores[ErrorMay] = 1;
		*existenciaDeError = 1;
	}
	if(banderaMin == 0) {
		errores[ErrorMin] = 1;
		*existenciaDeError = 1;
	}
	if(banderaNum == 0) { 
		errores[ErrorNum] = 1;
		*existenciaDeError = 1;
	}
	if(banderaSimb == 0) { 
		errores[ErrorSimb] = 1;
		*existenciaDeError = 1;
	}
}

void caracteres_consecutivos(char *contra, int *errores, int *existenciaDeError)
{
	for(int i = 0; i < (strlen(contra) -1) ; i++)
	{
		if(contra[i] == contra[i+1])
		{
			errores[ErrorCons] = 1;
			*existenciaDeError = 1;
			break;
		}
	}
}
