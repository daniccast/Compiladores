#ifndef _pila
#define _pila


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

struct pila pila;

#include <stdio.h>
#include <stdlib.h>

void push(char simbolo){
    /* Agrega un nuevo elemento a la pila */
    STACK.elementos++;
    struct nodo auxiliar;
      auxiliar.simbolo= simbolo;
    if(STACK.tope== NULL){
        auxiliar.siguiente=NULL;
    } else{
        auxiliar.siguiente= STACK.tope;
    }
    STACK.tope= &auxiliar;
}

nodo * pop(){
    printf("\n\nElementos en pila: %d", STACK.elementos);
    printf("\tElemento en tope: %d", STACK.tope->simbolo);
    
    return  STACK.tope;
}


#include "pila.h"
#endif 