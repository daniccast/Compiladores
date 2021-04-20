#ifndef _lista
#define _lista

void agregar_Elemento( Lista * lista, char simbolo);
void imprimir_lista( Lista * lista);
void agregar_concatenacion(nodo_lista * auxiliar);

/*
    Agrega elemento al final de la lista.
    Recibe la lista a la que le agregaremos el elemento y
    el simbolo que irá en el nodo que vamos a agregar.    
*/
void agregar_Elemento(Lista * lista, char simbolo){
    
    if (simbolo=='\0'){
        return ;
    }
   
    nodo_lista *nodo = malloc(sizeof(nodo_lista));      
    nodo->simbolo= simbolo;

    if(lista->principio == NULL)
        lista->principio= nodo;
    else
        lista->fin->siguiente= nodo;    
    nodo->siguiente=NULL;
    lista->fin= nodo;
}


/*
    Imprime los elementos de una lista.
*/
void imprimir_lista( Lista * lista){
   
    if(lista->principio== NULL){
        printf("No hay elementos en la lista \n");
        return ;
    }

    nodo_lista * auxiliar;
    auxiliar=lista->principio;
    
    do{
        printf("%c ",auxiliar->simbolo);
        auxiliar= auxiliar->siguiente;
    }while ( auxiliar !=NULL);

    printf("\n");
    free(auxiliar);
}

/*
    Agrega el elemento de concatenación.
    Se agrega, después del nodo que se recibe, un nodo que contenga el simbolo '.'
*/
void agregar_concatenacion(nodo_lista * nodo){
    
    nodo_lista * auxiliar = malloc(sizeof(nodo_lista));
    auxiliar->simbolo= '.';
   
    if(nodo!=NULL){
        auxiliar->siguiente= nodo->siguiente;
        nodo->siguiente= auxiliar;
    }
}

/*
    Eliminar el primer elemento de una lista.
    Recibe la lista a la que se le quitará dicho elemento.
*/
void liberar_nodo_principio(Lista * lista){
    
    if(lista->principio== NULL){
        printf("No hay elementos en la lista. \n");
        return ;
    }
    nodo_lista * auxiliar;

    auxiliar= lista->principio;
    lista->principio= auxiliar->siguiente;
    free(auxiliar);
}


#include "lista.h"
#endif 