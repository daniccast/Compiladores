#ifndef _estructuras
#define _estructuras

//.......::::::::::: LISTA ::::::::::::.................

struct nodo{
    char simbolo;
    struct nodo* siguiente;
};
typedef struct nodo nodo_lista;

struct Lista{
	struct nodo * principio;
	struct nodo * fin;
};
typedef struct Lista Lista;

//.......::::::::::: PILA ::::::::::::.................

struct nodop{
    char simbolo;
    struct nodop *siguiente;
    struct nodop *anterior;
};
typedef struct nodop nodo_pila;

struct pila{
    struct nodop *tope;
    struct nodop *inicio;
};
typedef struct pila Pila;

#include <stdio.h>
#include <stdlib.h>



#include "estructuras.h"
#endif 