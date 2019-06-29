#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char cad[1000];
char binarios[1000];
char resultado[1000];

int tamano();
void combinaciones(int);
void binario(int, int);

int main()
{
	int i,numCombinaciones,x=0,j;
	char ar[1000], caracter;
	FILE *entrada;
	FILE *salida;
	entrada = fopen ( "lenguaje.txt", "r+" );  
	
	while((caracter = fgetc(entrada)) != EOF)
	{
		if(caracter != ',' && caracter != '\n'){
			ar[x] = caracter;
			x++;
		}
	}
	ar[x] = '\0';
	fclose ( entrada );

	numCombinaciones = pow(2,strlen(ar));
	salida = fopen ( "combinaciones.txt", "r+" );
	fwrite( "", sizeof(char), 0, salida );

	
	fputs("El conjunto potencia es el siguiente:\nλ\n" , salida);
	for(i=1 ; i<numCombinaciones; i++)
	{
		x = 0;

		binario(i,0);
		combinaciones(strlen(ar));
		for(j=0; j<strlen(cad); j++)
		{
			if(cad[j] == '1'){
				resultado[x] = ar[j];
				x++;
			} 
			resultado[x] = '\0';
		}
		//printf("%s -> %s\n",cad, resultado);
		fputs( resultado, salida);
		fputc('\n', salida);
		
	}
	
	fclose ( salida );
	return 0;
}

void binario(int num,int pos)
{ 
	int aux;  
    
	if(num==0) return; 
         
    aux=num%2; 
    num=num/2; 
   
    binario(num,pos+1);
  
    if(aux==1) binarios[pos]= '1';
    else binarios[pos]='0';
   
}
int tamano()
{
	int x,cont=0;
	for(x=0; binarios[x]!='\0'; x++)
	{
		cont++;
	}
	return cont;
}

void combinaciones(int elementos)
{
	int tam=tamano();
	int j,i;
	for(j=0;j < (elementos- tam); j++)
	{
		cad[j]='0';
	}
	for(i=j; i< (tam+j) ; i++)
	{
		cad[i]=binarios[tam-(i-j)-1];
	
	}
}