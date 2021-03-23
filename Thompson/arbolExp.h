#ifndef _arbolExp
#define _arbolExp

void generar_arbol(char *expresion, int longitud_expresion);

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct nodoarbol {
    char simbolo;
    struct nodoarbol *izquierda;
    struct nodoarbol *derecha;
    struct nodoarbol *padre;
}typedef nodoarbol;

nodoarbol generar_nodo(char simbolo, nodoarbol *izquierda, nodoarbol *derecha, nodoarbol *padre){
    
    nodoarbol nodo;

    //Asignar a nodo
    nodo.simbolo=simbolo;
    nodo.izquierda= izquierda;
    nodo.derecha= derecha;
    nodo.padre= padre;

    //Información solo para orientar

    printf("\n \t Nodo creado: %c \t", nodo.simbolo);
    return nodo;
}


void generar_arbol(char *expresion, int longitud_expresion){
    int i=0;
    
    //Crear raiz
    nodoarbol raiz= generar_nodo('.',NULL,NULL,NULL);

    for(i=0; i<longitud_expresion; i++){

        if(expresion[i]=='('){
            printf("abertura p\n");

        }

        else if(expresion[i]=='|'){
            printf("or\n");
        }

        else if(expresion[i]=='*'){
            printf("kleene \n");
        }

    }


}


    
#include "arbolExp.h"
#endif 