/*
 INSTITUTO POLITÉCNICO NACIONAL
 ESCUELA SUPERIOR DE CÓMPUTO
 ESTRUCTURAS DE DATOS
 GRUPO: 1CV8
 ALUMNOS:
 MARTÍN EDUARDO BARRIGA VARGAS
 _____________
 PROFESOR: BENJAMÍN LUNA BENOSO
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 IMPLEMENTACION DE LAS FUNCIONES BASISCAS DE LA PILA

 FECHA: MARTES 14 DE FEBRERO DEL 2017
*/

#include "ordenpila.h"

typedef int TipoDato;
//funcion para inicializar el valor de la cima 

void CrearPila(PILA *P)
{
	P->cima=-1;
}

//funcion para insertar elementos en la pila 

void InsertarPila(PILA *P, TipoDato elemento)
{
	if(PilaLlena(*P)==1)
	{
		puts("Error, Pila Llena");
		system("PAUSE");
		exit(-1);
	}
	P->cima++;
	P->ar[P->cima]=elemento;
}

//función para sacar los elementos de una pila
int QuitarPila(PILA *P)
{
	int aux;
	if(PilaVacia(*P)==1)
	{
		puts("Error, Pila Vacia");
		system("PAUSE");
		exit(-1);
	}
	aux=P->ar[P->cima];
	P->cima--;
	return aux;
}

//función que reinicia el valor de la cima a -1
void LimpiarPila(PILA *P)
{
	P->cima=-1;
}

//función que regresa el elemento que está en la cima sin sacarlo
int CimaPila(PILA P)
{
	return (P.ar[P.cima]);
}

//función que comprueba si una pila se encuentra llena
int PilaLlena(PILA P)
{
	if(P.cima==tam-1)
	return 1;
	return 0;
}

//función que comprueba si una pila se encuentra vacía
int PilaVacia(PILA P)
{
	if(P.cima==-1)
	return 1;
	return 0;
}
