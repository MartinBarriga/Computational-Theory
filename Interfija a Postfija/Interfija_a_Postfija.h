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
 ARCHIVO DE CABECERA PARA LA DEFINICIÓN DEL LA PILA

 FECHA: LUNES 20 DE FEBRERO DEL 2017
*/

#include <stdio.h>
#include <stdlib.h>
#define tam 100

typedef int TipoDato;

//definición de la pila
typedef struct pila 
{
	char ar[tam];
	int cima;
} PILA;

//operaciones fundamentales de la pila

void CrearPila(PILA *P);
void InsertarPila(PILA *P, char n);
int QuitarPila(PILA *P);
void LimpiarPila(PILA *P);
int CimaPila(PILA P);
int PilaLlena(PILA P);
int PilaVacia(PILA P);
int Preced(char viejo, char nuevo);