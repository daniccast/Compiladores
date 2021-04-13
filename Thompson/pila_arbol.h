#ifndef _pila_arbol
#define _pila_arbol

void push_A(Pila_A* pila, nodo_pa * nodo);
nodo_pa * pop_A(Pila_A * pila);
void imprimir_pila_A( Pila_A * pila);


#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

void push_A(Pila_A* pila, nodo_pa * nodo){
    /* Función para agregar un nuevo elemento a la pila
       Recibe la pila, y el nodo que agregará.
     */
    
    if(pila->inicio== NULL){
        pila->inicio= nodo;
        nodo->siguiente= NULL;
        nodo->anterior= NULL;
    } else{
        nodo->anterior= pila->tope;
        pila->tope->siguiente= nodo;

    }
    pila->tope= nodo;
}


nodo_pa * pop_A(Pila_A * pila){
     /* Función para sacar el último elemento de una pila,
    Devuelve el elemento. */

    if (pila->inicio== NULL && pila->tope== NULL){
        printf("Sin elementos en la pila \n");
        return NULL;
    } 
    
    nodo_pa *aux;
    aux= pila->tope;


    if(pila->inicio== pila->tope){
        pila->inicio= NULL;
        pila->tope= NULL;
         aux->anterior=NULL;
        aux->siguiente=NULL;
        return aux;
    }
    
    pila->tope= aux->anterior;
    pila->tope->siguiente= NULL;
    
    aux->anterior=NULL;
    aux->siguiente=NULL;

    return  aux;
}


void imprimir_pila_A( Pila_A * pila){
   /*
        Función para imprimir los elementos de una pila.
        Desde el inicio al final.
   */
    if(pila->inicio== NULL || pila->tope==NULL){
        printf("No hay elementos en la pila \n");
        return ;
    }

    nodo_pa * auxiliar;
    auxiliar=pila->inicio;
    
    do{
        printf("%c ",auxiliar->simbolo);
        auxiliar= auxiliar->siguiente;
    }while ( auxiliar !=NULL);

    printf("\n");
    free(auxiliar);
}


#include "pila_arbol.h"
#endif 