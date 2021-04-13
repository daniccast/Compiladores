#ifndef   _generar_arbol
#define  _generar_arbol

nodo_pa * armar_arbolExp(Lista * lista);
void imprimir_arbolExp(nodo_pa * raiz_arbol, int contador);

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "estructuras.h"
#include "pila_arbol.h"


bool es_terminal(char c){
    /* Función para determinar si un símbolo es terminal o no.
        Devuelve false si es igual a . * | 
                 true por el contrario
    */
    if (c!='.' && c!='|' && c!='*')
        return true;
    else 
        return false;
}


nodo_pa * armar_arbolExp(Lista * lista){
    /* 
        Funció para armar árbol de expresión de una expresión postfija.
        Recibe lista que contiene la expresión postfija.
        Devuelve raíz del árbol.
    */
    if(lista->principio== NULL){
            printf("No hay elementos en la lista \n");
            return NULL;
    }

    Pila_A * pila= malloc(sizeof(pila));
    pila->inicio= NULL;
    pila->tope= NULL;

    nodo_pa * raiz;

    nodo_lista * auxiliar;
    auxiliar=lista->principio;

        
    do{
        nodo_pa * nodo = malloc(sizeof(nodo_pa));
        nodo->simbolo= auxiliar->simbolo;

        if(es_terminal(auxiliar->simbolo)){ //Si es un símbolo terminal
            nodo->izquierda= NULL;
            nodo->derecha= NULL;
        } else{
            if(auxiliar->simbolo=='.' || auxiliar->simbolo=='|'){
                nodo->derecha= pop_A(pila);
                nodo->izquierda= pop_A(pila);
            } else { //case *
                nodo->izquierda= pop_A(pila);
                nodo->derecha=NULL;
            }
        }
        push_A(pila, nodo); 
        auxiliar= auxiliar->siguiente;

    //    imprimir_pila_A(pila);
    }while (auxiliar !=NULL);
    
    raiz= pop_A(pila);

    free(auxiliar);
    free(pila);

    return raiz;
}


void imprimir_arbolExp(nodo_pa * nodo, int contador){
    /*
        Función para imprimir un árbol binario.
        Recibe nodo y contador para los espacios
    */
    if(nodo == NULL){
        return ;
    }

    imprimir_arbolExp(nodo->derecha, contador+2);

    for(int i=0; i<contador; i++){
        printf(" ");
    }
    printf("%c\n", nodo->simbolo);

    imprimir_arbolExp(nodo->izquierda, contador+2);
}


#include "generar_arbol.h"
#endif 