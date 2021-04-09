#ifndef _Infija_Postfija
#define _Infija_Postfija


Lista * pasar_cadena(Lista * lista);
void prueba();

#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "pila.h"
#include "lista.h"

int precedencia(char c){
    if (c=='*')
        return 3;
    else if (c=='.')
        return 2;
    else if (c=='|')
        return 1;
    else
        return 0;
}

Lista * pasar_cadena(Lista * infija){

    if(infija->principio== NULL){
        printf("No hay elementos en la lista infija");
        return NULL;
    }

    Pila * pila= malloc(sizeof(Pila));
    pila->tope= NULL;
    pila->inicio= NULL;

    Lista * postfija= malloc(sizeof(Lista));
    postfija->principio= NULL;
    postfija->fin= NULL;

    char char_aux='\0';

    do{
       

        //Si es ( agregar directamente a la pila
        if( infija->principio->simbolo=='('){
            push(pila,  infija->principio->simbolo);
        }
           // SI ES )
        else if( infija->principio->simbolo==')'){

            do{
                
                char_aux= pop(pila);
                agregar_Elemento(postfija,char_aux);

                if(pila->tope->simbolo=='(')
                    break;
                
                
            }while (1);
            
            
        }
        //SI ES UN OPERADOR.
        else if( infija->principio->simbolo=='*' ||  infija->principio->simbolo=='.' ||  infija->principio->simbolo=='|'){
            if(pila->tope==NULL){
                push(pila,  infija->principio->simbolo);
            } else {
                if(precedencia(pila->tope->simbolo) < precedencia( infija->principio->simbolo) ){
                    push(pila,  infija->principio->simbolo);
                }
                else{
                    do{
                        char_aux= pop(pila);
                        printf("Se sacó %c\n", char_aux);
                        agregar_Elemento(postfija,char_aux);
                        
                    }while( precedencia(pila->tope->simbolo) >= precedencia( infija->principio->simbolo) );
                
                    push(pila,  infija->principio->simbolo);
                
                }
           }
        } 
        // SI NO ES NINGUNO
        else{
            agregar_Elemento(postfija, infija->principio->simbolo);
        }

        liberar_nodo_principio(infija);

printf("\t IT \n");
imprimir_pila(pila);
imprimir_lista(infija);
imprimir_lista(postfija);
     }while (  infija->principio != NULL );
   
    while (pila->tope!=NULL){
        char_aux= pop(pila);
        agregar_Elemento(postfija,char_aux);
    }
    
    free(pila);

    return postfija;
}



/*
imprimir_pila(pila);
imprimir_lista(infija);
imprimir_lista(postfija);
*/

#include "Infija_Postfija.h"
#endif 