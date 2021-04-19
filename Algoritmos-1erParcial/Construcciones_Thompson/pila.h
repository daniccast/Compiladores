#ifndef _pila
#define _pila

void push(Pila * pila, char simbolo);
char pop(Pila * pila);
void imprimir_pila( Pila * pila);


void push(Pila * pila, char simbolo){
    /* Función para agregar un nuevo elemento a la pila
       Recibe la pila, y el símbolo del elemento que agregará.
     */
    nodo_pila * auxiliar=  malloc(sizeof(nodo_pila));
    auxiliar->simbolo= simbolo;

    if(pila->inicio== NULL){
        pila->inicio= auxiliar;
        auxiliar->siguiente= NULL;
        auxiliar->anterior= NULL;
    } else{
        auxiliar->anterior= pila->tope;
        pila->tope->siguiente= auxiliar;

    }
    pila->tope= auxiliar;
}


char pop(Pila * pila){
     /* Función para sacar el último elemento de una pila,
    Devuelve el simbolo que contenía ese elemento, y elimina el nodo. */

    if (pila->inicio== NULL && pila->tope== NULL){
        printf("Sin elementos en la pila \n");
        return '\0';
    } 
    
    char simbolo= pila->tope->simbolo;

    if(pila->inicio== pila->tope){
        pila->inicio= NULL;
        pila->tope= NULL;
        return simbolo;
    }
    
    //printf("\tElemento en tope: %c", pila->tope->simbolo);
    nodo_pila *aux;
    aux= pila->tope;

    pila->tope= aux->anterior;
    pila->tope->siguiente= NULL;

    free(aux);

    return  simbolo;
}


void imprimir_pila( Pila * pila){
   /*
        Función para imprimir los elementos de una pila.
        Desde el inicio al final.
   */
    if(pila->inicio== NULL || pila->tope==NULL){
        printf("No hay elementos en la pila \n");
        return ;
    }

    nodo_pila * auxiliar;
    auxiliar=pila->inicio;
    
    do{
        printf("%c ",auxiliar->simbolo);
        auxiliar= auxiliar->siguiente;
    }while ( auxiliar !=NULL);

    printf("\n");
    free(auxiliar);
}

#include "pila.h"
#endif 