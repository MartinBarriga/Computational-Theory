#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Martín Eduardo Barriga Vargas

FILE *entrada;
FILE *salida;



void llenarMatriz(int***,int*,int*);
void imprimirMatriz(int***,int,int, int*);
int obtenerMedidaMatriz();

int main()
{
	int saltos,estadoInicial;
	int *estadosFinales=malloc(sizeof(int*)*saltos);

	saltos = obtenerMedidaMatriz();

	int ***matriz=malloc(sizeof(int*)*saltos);
	for (int i = 0; i <saltos; i++) 
	{
		matriz[i]=malloc(sizeof(int*)*3);
		for(int j = 0; j<3; j++) 
		{
			matriz[i][j] = malloc(sizeof(int)*saltos);
			for(int k= 0; k <saltos; k++)	matriz[i][j][k] = -1;
		}
	}


	llenarMatriz(matriz,&estadoInicial,estadosFinales);
	imprimirMatriz(matriz,saltos, estadoInicial, estadosFinales);
	printf("\nEjecucion finalizada. Observar resultados en archivo 'salida.txt\n'");
	return 0;
}

void imprimirMatriz(int ***matriz,int saltos,int estadoInicial,int *estadosFinales)
{
	int i,j,k,cantidadEstadosFinales;
	char estado[100];
	salida = fopen ( "salida.txt", "w" );
	fwrite( "", sizeof(char), 0, salida );
	fputs("A.F. = (Q,E,d,q0,F)\n" , salida);
	fputs("Q = {" , salida);
	for(i = 0; i < saltos; i++)
	{
		sprintf(estado, "%d", i);
		fputc('q',salida);
		fputs(estado, salida);
		if(i < saltos-1)fputc(',',salida);
	}
	fputs("}\n",salida);
	fputs("E = {a,b,c}\n\n",salida);

	for(i = 0; i < saltos; i++)
	{
		for(j = 0; j < 3; j ++)
		{
			fputs("d(q",salida);
			sprintf(estado, "%d", i);
			fputs(estado,salida);
			fputc(',',salida);
			if(j == 0) fputc('a',salida);
			if(j == 1) fputc('b',salida);
			if(j == 2) fputc('c',salida);
			fputs(") = {",salida);
			if(matriz[i][j][0] == -1) 
			{
				fputc('E', salida);

			}
			else 
			{
					k=0;
					do{
						fputc('q',salida);
						sprintf(estado, "%d", matriz[i][j][k]);	
						fputs(estado,salida);
						k++;
						if(matriz[i][j][k] != -1) fputc(',',salida);
					}
					while(matriz[i][j][k] != -1);
			}

			
			fputs("}\n\n",salida);
		}
		
	}
	fputs("qo = q",salida);
	sprintf(estado, "%d", estadoInicial);
	fputs(estado,salida);

	fputs("\nF = {",salida);
	cantidadEstadosFinales = 0;
	
	for(i = 0; i < saltos; i++)
	{
		
		if(estadosFinales[i] == 1)
		{
			sprintf(estado, "%d", i);
			if(cantidadEstadosFinales>0) fputs(", q",salida);
			else fputc('q',salida);
			fputs(estado,salida);
			cantidadEstadosFinales++;
		}
	}
	fputs("}\n",salida);
	fclose(salida);
}
int obtenerMedidaMatriz()
{
	char caracter;
	int saltos = 0;
	entrada = fopen ( "entrada.txt", "r+" );  
	
	while((caracter = fgetc(entrada)) != EOF)
	{
		if(caracter == '\n') saltos++;

	}
	fclose ( entrada );
	return saltos;

}

void llenarMatriz(int ***matriz, int *estadoInicial, int *estadosFinales)
{
	char linea[1000];
	int i=0,j,comas = 0,estado,estadoABC, primeralinea = 0,esfinal,numeroEstados; 
	entrada = fopen ( "entrada.txt", "r" );

	while (feof(entrada) == 0)
 	{
 		fgets(linea,1000,entrada);
 		if(primeralinea > 0)
 		{
	 		i = 0;
	 		for(comas = 0; comas<=5; comas++)
	 		{
	 			if(comas == 0)
	 			{
					while( (linea[i] != 'x') && (linea[i] != ',')) i++;	 
					if(linea[i] == 'x')
					{ 
						*estadoInicial = comas;
					}				
					while((linea[i] != ',')) i++;
					i++;
	 			}
	 			else if(comas == 1)
	 			{
					while( (linea[i] != 'x') && (linea[i] != ',')) i++;	 
					if(linea[i] == 'x')
					{
						esfinal = 1;
					}
					else {
						esfinal = 0;
					}
								
	 			}
	 			else 
	 			{
	 				while(linea[i] != ',') i++;
	 				i++;
	 				while(linea[i] == ' ' ) i++;
	 			}
	 			if(comas == 2)
	 			{
	 				estado = 0;

		 			while( (linea[i] < 48)  || (linea[i] > 57) ) i++;
		 				
		 			while( (linea[i] >= 48) && (linea[i] <= 57))
		 			{
		 				estado *= 10;
		 				estado += (linea[i] - '0');
						i++;
	 				}
		 			if(esfinal == 1) estadosFinales[estado] = 1;
		 			else estadosFinales[estado] = 0;
	 				
	 			}
	 			if(comas == 3 || comas == 4 || comas == 5)
	 			{
	 				if(linea[i] == '{')
	 				{
	 					numeroEstados = 0;
	 					do{
		 					
		 					estadoABC = 0;
			 				while( ((linea[i] < 48)  || (linea[i] > 57)) ) i++;
			 		
			 				
				 				while( (linea[i] >= 48) && (linea[i] <= 57))
				 				{
				 					estadoABC *= 10;
				 					estadoABC += (linea[i] - '0');
				 					i++;
				 					
				 				}
				 				if(comas == 3) matriz[estado][0][numeroEstados] = estadoABC;
				 				if(comas == 4) matriz[estado][1][numeroEstados] = estadoABC;
				 				if(comas == 5) matriz[estado][2][numeroEstados] = estadoABC; 
				 				numeroEstados++;
			 				
				 				
			 			}while(linea[i] != '}');
	 				}
	 				else
	 				{
		 				estadoABC = 0;
		 				while( ((linea[i] < 48)  || (linea[i] > 57)) && (linea[i] != '#') ) i++;
		 				if(linea[i] == '#') 
		 				{

		 					//if(comas == 3 )matriz[estado][0][0] = -1;
		 					//if(comas == 4 )matriz[estado][1][0] = -1;
		 					//if(comas == 5 )matriz[estado][2][0] = -1;
		 					i++;
		 				}
		 				else {
			 				while( (linea[i] >= 48) && (linea[i] <= 57))
			 				{
			 					estadoABC *= 10;
			 					estadoABC += (linea[i] - '0');
			 					i++;
			 					
			 				}
			 				if(comas == 3 )matriz[estado][0][0] = estadoABC; 
			 				if(comas == 4 )matriz[estado][1][0] = estadoABC; 
			 				if(comas == 5 )matriz[estado][2][0] = estadoABC; 
		 				}
	 				}

	 			}
	 			
	 		}	
 		}
 		primeralinea++;
 	
 	}
        
        
	fclose(entrada);	
}