#ifndef _pila_AFN
#define _pila_AFN

void push_AFN( Pila_AFN * pila, AFN * AFN);
AFN * pop_AFN(Pila_AFN * pila);

/* 
    Insertar AFN al último de una pila de AFNs.
    Recibe la pila y el AFN a insertar-
*/
void push_AFN( Pila_AFN * pila, AFN * AFN){
    if(pila->inicio== NULL){
        pila->inicio= AFN;
        AFN->siguiente=NULL;
        AFN->anterior=NULL;
    } else{
        pila->tope->siguiente= AFN;
        AFN->anterior=pila->tope; 
    }
    
    AFN->siguiente= NULL;
    pila->tope= AFN;

}

/*  Retira el último elemento de una pila de AFN's.
    Recibe la pila de AFN's. 
    Devuelve el útlimo AFN agregado a la pila.
*/
AFN * pop_AFN(Pila_AFN * pila){
    
    if (pila->inicio== NULL && pila->tope== NULL){
        printf("Sin elementos en la pila \n");
        return NULL;
    } 
    
    AFN *aux;
    aux= pila->tope;

    if(pila->inicio== pila->tope){
        pila->inicio= NULL;
        pila->tope= NULL;
        return aux;
    }
    
    pila->tope= aux->anterior;
    pila->tope->siguiente= NULL;
    
    aux->anterior=NULL;
    aux->siguiente=NULL;

    return  aux;
}


#include "pila_AFN.h"
#endif 