#include<stdio.h>
#include <stdlib.h>

typedef char tipoDato;
#define TAM 1000

typedef struct Stack
{
	tipoDato pila[TAM];
	int top;
}stack;


int vacia(stack *);
int llena(stack *);
void push(stack *, tipoDato);
tipoDato pop(stack *);
void inicializa(stack *);
tipoDato cimaPila(stack *);
void menu(void);
void estadoUno(stack *,char *,int);
void estadoDos(stack *,char *,int);

int main()
{
	int res, num, numpop;
	char palabra[1000];
	stack pila;
	inicializa(&pila);
	push(&pila, 'Z');
	printf("\nAutomata de pila: < {c0,c1,c2}, {a,b,c}, {X,Y,Z0}, d, e0, Z0, {e2} >\n\n");
	printf("Introduce una cadena: ");
	scanf("%s",palabra);
	printf("\n");
	estadoUno(&pila,palabra,0);
	
	return 0;
}
void estadoDos(stack *p, char *palabra, int i)
{
	if(palabra[i] == 'a')
	{
		if( vacia(p) == 0 )
		{
			if(cimaPila(p) == 'X')
			{
				pop(p);
				i++;
				estadoDos(p, palabra,i);
			}
			else {
				printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c1.\n");
				exit(0);
			}
		}
		else{
			printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c1.\n");
			exit(0);
		}
	}
	else if(palabra[i] == 'b')
	{
		if( vacia(p) == 0 )
		{
			if(cimaPila(p) == 'Y')
			{
				pop(p);
				i++;
				estadoDos(p, palabra,i);
			}
			else {
				printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c1.\n");
				exit(0);
			}
		}
		else{
			printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c1.\n");
			exit(0);
		}
	}
	else if( (palabra[i] == '\0') && (cimaPila(p) == 'Z'))
	{
		printf("\nFelicidades, Cadena valida!!\nEl automata finalizo en el estado final c2!!!\n");
	}
	else{
		printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c1.\n");
		exit(0);
	}
}
void estadoUno(stack *p, char *palabra, int i)
{
	if(palabra[i] == 'a')
	{
		if( (cimaPila(p) == 'Z') )
		{
			push(p,'X');
		}
		else if( (cimaPila(p) == 'X') )
		{
			push(p,'X');
		}
		else if( (cimaPila(p) == 'Y') )
		{
			push(p,'X');
		}
		else{
			printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c0.\n");
			exit(0);
		}
		i++;
		estadoUno(p,palabra,i);
	}
	else if(palabra[i] == 'b')
	{
		if( (cimaPila(p) == 'Z') )
		{
			push(p,'Y');
		}
		else if( (cimaPila(p) == 'X') )
		{
			push(p,'Y');
		}
		else if( (cimaPila(p) == 'Y') )
		{
			push(p,'Y');
		}
		else {
			printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c0.\n");
			exit(0);
		}
		i++;
		estadoUno(p,palabra,i);
	}
	else if(palabra[i] == 'c')
	{
		if( (cimaPila(p) == 'Z') || (cimaPila(p) == 'X') || (cimaPila(p) == 'Y') )
		{
			i++;
			estadoDos(p,palabra,i);
		}
		else{
			printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c0.\n");
			exit(0);
		}
	}
	else {
		printf("\nERROR. Cadena invalida. No pertenece al lenguaje.\nEl automata finalizo en el estado c0.\n");
		exit(0);
	}

}
int vacia(stack *p)
{
	if(p->top==-1) return 1;
	return 0;
}

int llena(stack *p)
{
	if(p->top==TAM-1) return 1;
	return 0;
}

void push(stack *p, tipoDato elem)
{
	p->top++;
	p->pila[p->top]=elem;
}

tipoDato cimaPila(stack *p)
{
	return p->pila[p->top];
}

tipoDato pop(stack *p)
{
	return p->pila[p->top--];
}
void inicializa(stack *p)
{
	p->top=-1;
}
