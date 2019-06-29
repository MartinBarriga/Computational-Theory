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

#include "Interfija_a_Postfija.cpp"

int main()
{
	int n, x, y, i, z, r, pos = 0, longitud = 0;
	char car, arreglo[1000];
	PILA A;

	while((car = getchar()) != '\n')
	{
		if( (car > 96 && car < 123) || (car > 64 && car < 91))
		{
			arreglo[longitud] = car;
			longitud++;
		}
		else
		{
			while( !PilaVacia(A) && Preced(CimaPila(A), car) ) 
			{
				arreglo[longitud] = QuitarPila(&A);
				longitud++;
			}
			InsertarPila(&A, car);
		}
		
	}
	while(!PilaVacia(A))
	{
		arreglo[longitud] = QuitarPila(&A);
		longitud ++;
	}
	for(i = 0; i < longitud ; i++) printf("%c", arreglo[i]);
	return 0;
}