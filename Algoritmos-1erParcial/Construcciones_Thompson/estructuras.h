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


//.......::::::::::: PILA ARBOL ::::::::::................. NO

struct nodopa{
    char simbolo;
    struct nodopa *siguiente;
    struct nodopa *anterior;
    struct nodopa *izquierda;
    struct nodopa *derecha;
};
typedef struct nodopa nodo_pa;

struct pilaA{
    struct nodopa *tope;
    struct nodopa *inicio;
};
typedef struct pilaA Pila_A;

//.......::::::::::: GRAFO ::::::::::.................

struct nodo_grafo{
    int no_estado;
    struct nodo_grafo *izquierda;
    struct nodo_grafo *derecha;
    char transicion_izq;
    char transicion_der;
    bool inicial;
    bool fin;
};
typedef struct nodo_grafo estado;

struct inifinAFN{
    estado * inicio;
    estado * fin; 
    struct inifinAFN * siguiente;
    struct inifinAFN * anterior;
};
typedef struct inifinAFN AFN;

struct pilaAFN{
    AFN *tope;
    AFN *inicio;
};
typedef struct pilaAFN Pila_AFN;


// ------- Conteo achivos
int conteo;
char conteo_s[5];
char nombre_archivo[15]= "AFNS/a";


#include "estructuras.h"
#endif 