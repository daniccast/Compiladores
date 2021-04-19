#ifndef _pila_AFN
#define _pila_AFN

void push_AFN( Pila_AFN * pila, AFN * AFN);
AFN * pop_AFN(Pila_AFN * pila);


void push_AFN( Pila_AFN * pila, AFN * AFN){
    /* Función para insertar AFN a una pila
    Recibe la pila y el AFN a insertar
    */
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


AFN * pop_AFN(Pila_AFN * pila){
    /* Función para retirar el último elemento de una pila.
    Recibe la pila. Devuelve el AFN.
	*/
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