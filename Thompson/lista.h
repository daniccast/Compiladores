#ifndef _lista
#define _lista

void agregar_Elemento( Lista * lista, char simbolo);
void imprimir_lista( Lista * lista);
void agregar_concatenacion(nodo_lista * auxiliar);

#include <stdio.h>
#include <stdlib.h>


void agregar_Elemento(Lista * lista, char simbolo){
    /*
        Función para agregar elementos al final de la lista
        Recibe: La lista a la que le agregaremos los elementos.
        El simbolo que irá en el nodo que vamos a agregar.    
    */
    nodo_lista *nodo = malloc(sizeof(nodo_lista));      
    nodo->simbolo= simbolo;

    if(lista->principio == NULL)
        lista->principio= nodo;
    else
        lista->fin->siguiente= nodo;    
    nodo->siguiente=NULL;
    lista->fin= nodo;

}



void imprimir_lista( Lista * lista){
   /*
        Función para imprimir los elementos de una lista.
        Desde el inicio al final.
   */
    if(lista->principio== NULL){
        printf("No hay elementos en la lista");
        return ;
    }

    nodo_lista * auxiliar;
    auxiliar=lista->principio;
    
    do{
        printf("%c ->",auxiliar->simbolo);
        auxiliar= auxiliar->siguiente;
    }while ( auxiliar !=NULL);

    printf("\n");
    free(auxiliar);
}



void agregar_concatenacion(nodo_lista * nodo){
    /*
        Función para agregar el elemento de concatenación.
        Se agrega después del nodo que se recibe un nodo que contenga el simbolo '.'
    */
    nodo_lista * auxiliar = malloc(sizeof(nodo_lista));
    auxiliar->simbolo= '.';
   
    if(nodo!=NULL){
        auxiliar->siguiente= nodo->siguiente;
        nodo->siguiente= auxiliar;
    }
}

#include "lista.h"
#endif 