#include <stdio.h>
#include <stdlib.h>
// Martín Eduardo Barriga Vargas

int revisa(char , char * , int );
void introducir_alfabeto(char *);
int introducir_palabra(char *, char *, int );
void prefijos(char *, int);
void sufijos(char *, int);
void potenciar(char *, int);
void evaluar(char *, char *);


int main()
{
	char alfabeto[10000],w1[10000], w2[10000] ;
	int tamW1,tamW2;
	introducir_alfabeto(alfabeto);
	
	printf("Tu alfabeto es Σ = {%s}\n\n",alfabeto);
	
	tamW1 = introducir_palabra(alfabeto,w1,1);
	tamW2 = introducir_palabra(alfabeto,w2,2);

	printf("\na) |w1| = %d y |w2| = %d\n\n", tamW1, tamW2 );
	prefijos(w1, tamW1);
	sufijos(w1, tamW1);
	printf("c) w1w2: %s%s\n\n", w1,w2);
	printf("d) |w1w2|: %d\n\n", (tamW1 + tamW2));
	potenciar(w2,tamW2);
	evaluar(alfabeto,w1);
	return 0;
}

int revisa(char aux, char * alf, int tam)
{
	int j;
	for(j = 0; j < tam; j++ )
	{
		if( aux == alf[j]) return 1;
	}
	return 0;
}

void introducir_alfabeto(char *alf)
{
	int i= 0, repetido = 0;
	char aux;
	printf("Define tu alfabeto (introduce un espaio para dejar de introducir simbolos):\n");
	do{
		scanf("%c",&aux);
		getchar();
		if(i > 0) repetido = revisa(aux, alf, i);
		if((aux!=' ') && (aux!='\n') && (repetido == 0))
	    {
	    	alf[i]= aux;
	    	i++;
		} 
		else 
		{
			if(repetido == 1) printf("*Error* No puedes introducir simbolos iguales, Introduce simbolos diferentes:\n"); 
			else if(i < 3) printf("*Error* El minimo de simbolos es 3, Introduce mas simbolos:\n");
		}
	}while ((aux!=' ')  || (i < 3 ) || (repetido == 1));
	alf[i] = '\0';
	
}

int introducir_palabra(char *ar, char *w, int num)
{
	int bandera, i,x;
	char wAux[10000];
	do{
		printf("Introduce tu palabra w%d: ",num);
		scanf("%s",wAux);	
		i=0;
		do{
			bandera = 0;
			x=0;
			do{
				if(ar[x] == wAux[i]) bandera = 1;
				x++;
			}while((ar[x]!='\0') && (bandera ==0));
			i++;
		}while((wAux[i]!='\0') && (bandera == 1));
		
	if(bandera == 0)printf("\n*Error* Tu palabra debe contener letras de tu alfabeto Σ = {%s}\n\n",ar);
	}while(bandera == 0);
	i=0;
	do{
		w[i] = wAux[i];
		i++;
	}while(w[i-1] != '\0' );
	return (i-1);
}

void prefijos(char *w, int tam)
{
	int i, j;
	printf("b) Prefijos de w1:\n\n   λ\n");
	for(i = 1; i<= (tam -1); i++)
	{	printf("   ");
		for(j = 0; j < i; j++)
		{
			printf("%c", w[j]);
		}
		printf(" -> Propio\n");
	}
	printf("   %s\n\n", w);
	
}

void sufijos(char *w, int tam)
{
	int i, j;
	printf("   Sufijos de w1:\n\n   λ\n");
	for(i = 1; i<= (tam -1); i++)
	{	printf("   ");
		for(j = (tam-i); j < tam; j++)
		{
			printf("%c", w[j]);
		}
		printf(" -> Propio\n");
	}
	printf("   %s\n\n", w);
}

void potenciar(char *w, int tam)
{
	int n,i;
	char wInv[10000];
	printf("e) Introduce el valor de n: ");
	scanf("%d", &n);
	if(n>0)
	{
		printf("\nW2^%d = ", n);
		for(i = 0; i < n; i++)
		{
			printf("%s", w);
		}
	}
	else if(n<0)
	{
		for(i = 0; i < tam; i++)
		{
			wInv[(tam-1)-i] = w[i];
		}
		wInv[i] = '\0';
		n*=-1;
		printf("\nW2^(-%d) = ", n);
		for(i = 0; i < n; i++)
		{
			printf("%s", wInv);
		}
	}
	else{
		printf("\nW2^(%d) = λ", n);

	}
	printf("\n\n");
}
void evaluar(char *alfabeto, char *w)
{
	int contador = 0, i, bandera = 0, j;
	char n;
	printf("f) Introduce tu letra N: ");
	do{
		getchar();
		scanf("%c", &n);
		i = 0;
		do{
			if(n == alfabeto[i])
			{
				bandera = 1;
				j=0;
				do{
					if(n == w[j]) contador++;
					j++;
				} while( w[j] != '\0');
			}
			i++;
		}while((alfabeto[i] !='\0') && (bandera == 0));
		if(bandera == 0) printf("*Error* N tiene que ser una letra de tu alfabeto, introduce N: ");
	} while(bandera == 0);
	printf("\n|w1|N = %d\n\n", contador);
}

