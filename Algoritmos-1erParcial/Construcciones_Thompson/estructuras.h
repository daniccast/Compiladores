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
int conteo;                         //Variable que llevará el valor del archivo
char conteo_s[5];                   //Variable para el valor en string
char nombre_archivo[15]= "AFNS/a";  //Ruta e inicio de nombre de archivo

#include "estructuras.h"
#endif 