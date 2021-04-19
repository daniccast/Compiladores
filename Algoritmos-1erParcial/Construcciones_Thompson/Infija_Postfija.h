#ifndef _Infija_Postfija
#define _Infija_Postfija

Lista * pasar_cadena(Lista * lista);

#include "estructuras.h"
#include "pila.h"
#include "lista.h"

int precedencia(char c){
    /* Función que devuelve la precedencia de un operador  * |  .
    Si no se manda un operador como los anteriores, devuelve cero.
    */
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
    /*
        Función para pasar una expresión regular infija a postfija.
        Implementación del Shunting-Yard Algorithm.
        Ingresa una lista con expresión infija, devuelve una lista con expresión postfija.
    */

    if(infija->principio== NULL){                                   //Verificar que la lista contenga algo.
        printf("No hay elementos en la lista infija");
        return NULL;
    }

    Pila * pila= malloc(sizeof(Pila));                              //Crear lista para los operadores.
    pila->tope= NULL;
    pila->inicio= NULL;

    Lista * postfija= malloc(sizeof(Lista));                        //Crear lista para la expresión postfija.
    postfija->principio= NULL;
    postfija->fin= NULL;

    char char_aux='\0';

    do{
       
        if( infija->principio->simbolo=='('){                       //Si es ( agregar directamente a la pila
            push(pila,  infija->principio->simbolo);
        }
        else if( infija->principio->simbolo==')'){                  // SI ES ), sacar hasta que encontremos ( 

            do{
                char_aux= pop(pila);
                agregar_Elemento(postfija,char_aux);
                if(pila->tope->simbolo=='('){
                    break;
                }   
                
            }while(1);
            pop(pila);
            
        }
        else if( infija->principio->simbolo=='*' ||  infija->principio->simbolo=='.' ||  infija->principio->simbolo=='|'){      //SI ES UN OPERADOR
            if(pila->tope==NULL){                                                                                               //Si no hay nada en pila, agregar directamente.
                push(pila,  infija->principio->simbolo);
            } else {                                                                                                            //Si no, sacar hasta que la preedencia sea menor, y agregar.
                if(precedencia(pila->tope->simbolo) < precedencia( infija->principio->simbolo) ){
                    push(pila,  infija->principio->simbolo);
                }
                else{
                    do{
                        char_aux= pop(pila);
                        agregar_Elemento(postfija,char_aux);
                        if(pila->tope==NULL)
                            break;

                    }while( precedencia(pila->tope->simbolo) >= precedencia( infija->principio->simbolo));
                
                    push(pila,  infija->principio->simbolo);
                }
           }
        } 
        else{                                                                       // SI NO ES NINGUNO, es un simbolo final y se grega directamente a la lista postfija
            agregar_Elemento(postfija, infija->principio->simbolo);
        }

        liberar_nodo_principio(infija);                                             //Se pasa a la siguiente posición de a lista.
     }while (  infija->principio != NULL );
   
    while (pila->tope!=NULL){                                                       //Vaciamos los operadores que queden en la lista
        char_aux= pop(pila);
        agregar_Elemento(postfija,char_aux);
    }
    free(pila);
    return postfija;
}


#include "Infija_Postfija.h"
#endif 