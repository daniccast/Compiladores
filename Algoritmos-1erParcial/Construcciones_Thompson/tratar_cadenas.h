#ifndef _tratar_cadenas
#define _tratar_cadenas

bool validar_operadores(char * cadena, int longitud);
Lista *  cadena_a_lista(char * cadena, int longitud);
void ver_concatenaciones(Lista * lista);

#include "lista.h"

/*
    Valida que la expresión regular no tenga algo incorrecto.
    Regresará FALSE si encuentra un error.
    Regresará TRUE si no encuentra uno.
    */
bool validar_operadores(char * cadena, int longitud){
    
    int i=0;
    int parentesis_A=0, parentesis_C=0; 
    
    if(cadena[0]=='|' || cadena[0]=='.' || cadena[0]=='*')
        return false;

    if(cadena[longitud-1]=='|' || cadena[longitud-1]=='.' )
        return false;  

    for(i=0; i<longitud; i++){

        if (cadena[i]== '|' || cadena[i]== '.' || cadena[i]== '('){
            
            if (cadena[i+1]=='|')
                return false;
            else if (cadena[i+1]=='*')
                return false;
            else if (cadena[i+1]=='.')
                return false;
            else if (cadena[i+1]==')')
                return false;
            
            if( cadena[i]== '(')
                 parentesis_A++;

        } else if (cadena[i]== '*'){
            if (cadena[i+1]=='*')
                return false;
        } else if ( cadena[i]== ')'){
                parentesis_C++;
        } 
    }

    if(parentesis_A!=parentesis_C)
        return false;
    else
        return true;
}

/*
    Pasa cada carácter de la cadena a un elemento en unalista. 
    Devuelve la lista de elementos.
*/
Lista * cadena_a_lista(char * cadena, int longitud){
    
    int i=0;
  
    Lista * lista= malloc(sizeof(Lista));
    lista->fin=NULL;
    lista->principio=NULL;

    for(i=0; i<longitud; i++){
        agregar_Elemento(lista,cadena[i]);
    }
    
    return lista;
    
}

 /*
    Busca dónde hay concatenaciones y manda a llamar a la función 
    que agrega el nodo entre los elementos de la concatenación.
   */
void ver_concatenaciones(Lista * lista){
  
    if(lista->principio== NULL){
        printf("No hay elementos en la lista");
        return ;
    } else if(lista->principio == lista->fin){
        return ;
    }

    nodo_lista *auxiliar= malloc(sizeof(nodo_lista));
    auxiliar=lista->principio;
  
    do{
         
        if( auxiliar->simbolo!= '.' && auxiliar->simbolo!='|'  && auxiliar->simbolo!='(' ){
            
            if(auxiliar->siguiente->simbolo=='.'){
                //printf("Ya concatenación");
            }

            else if( auxiliar->siguiente->simbolo!='|' && auxiliar->siguiente->simbolo!=')' && auxiliar->siguiente->simbolo!='*' && auxiliar->siguiente!=NULL){
               //printf("concatenacion %c . %c \n",auxiliar->simbolo, auxiliar->siguiente->simbolo);
               agregar_concatenacion(auxiliar);
            }    
            
        }  
        auxiliar= auxiliar->siguiente;
    }  while (auxiliar != lista->fin);
    //free(auxiliar);   
}


#include "tratar_cadenas.h"
#endif 