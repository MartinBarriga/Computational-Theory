#include <stdio.h>
#include <stdlib.h>
//Martin Eduardo Barriga Vargas
typedef struct elemento
{
    char dato[1000];
    struct elemento *sig;
}Elemento;
typedef struct ListaIdentificar
{
    Elemento *inicio;
    Elemento *fin;
    int tamano, numcaracteres;
}Lista;
void inicializa(Lista *);
Elemento * creaNodo(char);
Elemento * crearNodo(char[]);
void imprime(Lista *);
int inserta_primer_elem(Lista *, Elemento *);
int inserta_al_final(Lista *, Elemento *);

void potencia(Lista *, Lista, int, int);
int cont=0;
int main()
{
    int n, k, i = 0;
    char car;
	Lista lista1, lista2, lista3;
	Elemento *nvo;
	inicializa(&lista1);
	printf("Introduce el numero de elementos en tu alfabeto: ");
	scanf("%d",&n);
	if(n<1) return 0;
	getchar();
	printf("Introduce el simbolo numero %d de tu alfabeto: ", i+1);
	scanf("%c", &car);
	getchar();
	nvo = creaNodo(car);
	inserta_primer_elem(&lista1, nvo);
	for(i = 1; i< n; i++)
	{
		printf("Introduce el simbolo numero %d de tu alfabeto: ", i+1);
		scanf("%c", &car);
		getchar();
		nvo = creaNodo(car);
		inserta_al_final(&lista1, nvo);
	}
	
	printf("Introduce su potencia: ");
	scanf("%d", &k);
	if(k==1)
	{
		imprime(&lista1);
		return 0;
	}
	if(k == 0)
	{
		printf("El conjunto esta vacio\n");
	}
	potencia(&lista1, lista1, k, n);

	return 0;
}

void inicializa(Lista *l)
{
	l->inicio = NULL;
	l->fin = NULL;
	l->tamano = 0;
	l->numcaracteres = 1;

}
Elemento * creaNodo(char caracter)
{
	Elemento *nvo = (Elemento *) malloc(sizeof(Elemento));
	if(nvo!= NULL)
	{
		nvo->dato[0] = caracter;
		nvo->dato[1] = '\0';
		nvo->sig = NULL;
	} 
	return nvo;
}

Elemento * crearNodo(char *caracter)
{
	Elemento *nvo = (Elemento *) malloc(sizeof(Elemento));
	if(nvo!= NULL)
	{
		int i;
		for(i = 0; i <999; i++)
		{
			nvo->dato[i] = caracter[i];
		}
		nvo->dato[999] = '\0';
		nvo->sig = NULL;
	} 
	return nvo;
}
void imprime(Lista *l)
{
	Elemento *aux = l->inicio;
	while(aux!=NULL)
	{
		if(aux->sig != NULL) printf("%s --> ", aux ->dato);
		else printf("%s\n", aux -> dato);
		aux = aux -> sig;
	}
}

int inserta_primer_elem(Lista *l, Elemento *nvo)
{
	if(l->tamano == 0)
	{
		l->inicio = nvo;
		l->fin = nvo;
		l->tamano++;
		return 1;
	}
	return 0;
}

int inserta_al_final(Lista *l, Elemento *nvo)
{
	if(l->tamano != 0)
	{
		l->fin->sig = nvo;
		l->fin = nvo;
		l->tamano++;
		return 1;
	}
	return 0;
}


void potencia( Lista *l, Lista l2, int k, int n)
{
	int i, j, y;
	
	Lista l3;
	inicializa(&l3);
	Elemento *aux = l->inicio;
	Elemento *aux2 = l2.inicio;
	Elemento *aux3;	
	Elemento *nvo;
	for(i = 0; i < k-1; i++)
	{
		while (aux!= NULL)
		{
			while (aux2!= NULL)
			{
				char ar[1000];
				for(y = 0; y < i+1; y++)
				{
					ar[y] = aux->dato[y];
				}
			
				ar[y] = aux2->dato[0];
			
				
				nvo = crearNodo(ar);
				//printf("Arreglo %s\n", nvo->dato);
				if(aux2 == l2.inicio && aux == l->inicio)
				{
					inserta_primer_elem(&l3, nvo);
				}
				else {
					inserta_al_final(&l3, nvo);
				}
				aux2 = aux2->sig;
			}	
			//imprime(&l3);
			aux = aux->sig;
			aux2 = l2.inicio;
		}
		inicializa(l);
		inserta_primer_elem(l, l3.inicio);
		aux3 = l3.inicio->sig;
		while(aux3!=NULL)
		{
			inserta_al_final(l, aux3);
			aux3=aux3->sig;
		}
		aux = l->inicio;
		inicializa(&l3);
		aux2 = l2.inicio;
	}
	printf("El conjunto potencia es el siguiente: \n");
	imprime(l);
}

