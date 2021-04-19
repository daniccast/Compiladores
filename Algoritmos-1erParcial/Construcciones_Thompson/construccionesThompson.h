#ifndef   _construccionesThompson
#define  _construccionesThompson

AFN * construirThompson(Lista * lista);
void Imprimir_AFD(AFN * AFN);

#include "pila_AFN.h"
#include "ColaEdos.h"

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


AFN * armar_AFN_terminal(char simbolo, int no_Estado){
    /* Función que devuelve la estructura AFN de un símbolo terminal.
    Recibe el símbolo, y el número de estado final en el conteo.
    */
    AFN * afn = malloc(sizeof(AFN));

    estado * estado1= malloc(sizeof(estado));
    estado * estado2= malloc(sizeof(estado));

    estado1->no_estado= no_Estado+1;
    estado2->no_estado= no_Estado+2;

    estado1->izquierda= estado2;
    estado1->derecha= NULL;

    estado2->izquierda=NULL;
    estado2->derecha=NULL;

    estado1->transicion_izq= simbolo;
    estado1->transicion_der='\0';

    estado2->transicion_izq='\0';
    estado2->transicion_der='\0';

    estado1->inicial=true;
    estado1->fin=false;

    estado2->inicial=false;
    estado2->fin=true;

    afn->inicio= estado1;
    afn->fin=estado2;

    return afn;    
}


AFN * armar_AFN_concatenacion(AFN * afn1, AFN * afn2){
    /* Función que devuelve la estructura AFN de una concatenación.
    Recibe los dos AFN que serán concatenados.
    Orden:    afn1 . afn2
    */

    afn1->fin->izquierda= afn2->inicio->izquierda;
    afn1->fin->transicion_izq= afn2->inicio->transicion_izq;

    afn1->fin->derecha = afn2->inicio->derecha;
    afn1->fin->transicion_der = afn2->inicio->transicion_der;

    afn2->fin->no_estado= afn2->fin->no_estado-1;

    afn1->fin->fin= false;
    
    free(afn2->inicio);
    
    afn1->fin= afn2->fin;

    afn2->inicio=NULL;
    afn2->fin=NULL;
    free(afn2);
    
    afn1->inicio->inicial= true;
    return afn1;
}


AFN * armar_AFN_union(AFN * afn1, AFN * afn2){
    /* Función que devuelve la estructura AFN de una unión.
    Recibe los dos AFN que serán unidos.
    Orden:    afn1 | afn2
    */

    estado * ini= malloc(sizeof(estado));
    estado * fin= malloc(sizeof(estado));
   
    //--------------- NODO INICIAL
    ini->izquierda= afn1->inicio; 
    ini->transicion_izq= 'E';

    ini->derecha= afn2->inicio;
    ini->transicion_der='E';


    afn1->inicio->inicial = false;
    afn2->inicio->inicial = false;
    
    ini->inicial= true;
    ini->fin= false;
    ini->no_estado= afn2->fin->no_estado+1;     //último estado en conteo + 1

    //--------------- NODO FINAL
    fin->izquierda= NULL;
    fin->transicion_izq= '\0';

    fin->derecha= NULL;
    fin->transicion_der='\0';

    afn1->fin->fin = false;
    afn2->fin->fin = false;

    fin->inicial= false;
    fin->fin= true;
    fin->no_estado= ini->no_estado + 1 ;

    afn1->fin->izquierda= fin;
    afn1->fin->transicion_izq= 'E';

    afn2->fin->izquierda= fin;
    afn2->fin->transicion_izq= 'E';
    
    //--------------- Cambiar AFN1
    afn1->inicio= ini;
    afn1->fin= fin;

    afn2->inicio=NULL;
    afn2->fin=NULL;
    free(afn2);
    
    return afn1;
}


AFN * armar_AFN_kleene(AFN * afn1){
    /* Función que devuelve la estructura AFN de una función estrella.
    Recibe el AFN al que se le aplicará.
    Orden:    afn1*
    */

    estado * ini= malloc(sizeof(estado));
    estado * fin= malloc(sizeof(estado));

    //----------Nodo inicial
    ini->no_estado= afn1->fin->no_estado + 1;
    ini->izquierda= afn1->inicio;
    ini->transicion_izq= 'E';
    ini->derecha= fin;
    ini->transicion_der= 'E';
    ini->inicial= true;
    ini->fin=false;

    //----------Nodo final
    fin->no_estado= ini->no_estado +1;
    fin->izquierda= NULL;
    fin->transicion_izq= '\0';
    fin->derecha= NULL;
    fin->transicion_der= '\0';
    fin->inicial= false;
    fin->fin=true;
    
    //------------Estados intermedios
    afn1->inicio->inicial= false;
    afn1->fin->fin= false;

    afn1->fin->izquierda= afn1->inicio;
    afn1->fin->transicion_izq= 'E';
    afn1->fin->derecha= fin;
    afn1->fin->transicion_der= 'E';

    //------------Cambiar AFN
    afn1->inicio= ini;
    afn1->fin= fin;

    return afn1;
}


AFN * construirThompson(Lista * lista){
    /* Función que realiza el algoritmo de Thompson.
    Devuelve la estructura AFN, que apunta al nodo inicial del AFN y al final
    */
    
      if(lista->principio== NULL){
        printf("No hay elementos en la lista \n");
        return NULL;
    }

    nodo_lista * auxiliar;
    auxiliar=lista->principio;
    
    Pila_AFN *pila= malloc(sizeof(Pila_AFN));                   //Definir pila de AFN's      
    pila->inicio=NULL;
    pila->tope=NULL;

    AFN * afn_aux;
    AFN * AFN_aux1;
    AFN * AFN_aux2;

    int edo;
    do{
        
        //Si el simbolo es terminal
        if(es_terminal(auxiliar->simbolo)){
            if (pila->tope!=NULL)
                edo=pila->tope->fin->no_estado;
            else 
                edo=0;   
            afn_aux= armar_AFN_terminal(auxiliar->simbolo, edo);
            push_AFN(pila,afn_aux);
        } else{
            if(auxiliar->simbolo=='.'){                                  //Operación de concatenación a.b 
                AFN_aux1= pop_AFN(pila);
                AFN_aux2= pop_AFN(pila);
                afn_aux= armar_AFN_concatenacion(AFN_aux2,AFN_aux1);
                push_AFN(pila, afn_aux);
            } else if (auxiliar->simbolo=='|'){                          //Operación de unión a|b
                AFN_aux1= pop_AFN(pila);
                AFN_aux2= pop_AFN(pila);
                afn_aux= armar_AFN_union(AFN_aux2,AFN_aux1);
                push_AFN(pila, afn_aux);
            } else if (auxiliar->simbolo=='*'){                         //Operación estrella
                AFN_aux1= pop_AFN(pila);
                afn_aux= armar_AFN_kleene(AFN_aux1);
                push_AFN(pila, afn_aux);
            }
        }
        auxiliar= auxiliar->siguiente;
    }while ( auxiliar !=NULL);                                          //Hasta terminar la lista postfija

    free(auxiliar);

    afn_aux= pop_AFN(pila);
    free(pila);
   
    return afn_aux;
}


void Imprimir_AFD(AFN * AFN){ 
    /*
        Función para recorrer el AFN,e imprimir sus estados y transiciones.
        Utiliza el recorrido BFS para ello.
    */

    bool estados_visitados[AFN->fin->no_estado];                                    //Arreglo de estados visitados
    long int longitud= sizeof(estados_visitados) / sizeof(estados_visitados[0]);
    
    for(int i=0; i<longitud; i++)                                                   //Inicializar arreglo
        estados_visitados[i]= false;


    cola_edos * cola= malloc(sizeof(cola_edos));                                    //Definir cola de estados
    cola->principio=NULL;
    cola->fin=NULL;
  
    encolar(cola, AFN->inicio);                                                     //Iniciar con el nodo inicial del AFN

    while (cola->principio != NULL){                                                //Hasta que no hayan elementos en la cola
        
        printf("----ESTADO %d ----", cola->principio->estado->no_estado);
        
        if (cola->principio->estado->inicial)
            printf("\t  Inicial");
        if (cola->principio->estado->fin)
            printf("\t  Fin");

        printf("\n");

        if (cola->principio->estado->fin && cola->principio->siguiente==NULL)
            break;

        if (!estados_visitados[cola->principio->estado->no_estado]){                        //Si el nodo no ha sido visitado
              //Izquierda
            if(cola->principio->estado->izquierda!= NULL){                                  //Ver si tiene algo en su rama izquierda, e imprimir
                printf("%d,%c -> %d \n",cola->principio->estado->no_estado, 
                cola->principio->estado->transicion_izq, cola->principio->estado->izquierda->no_estado );
                
                if(!estados_visitados[cola->principio->estado->izquierda->no_estado] && cola->principio->estado->izquierda!= cola->fin->estado)
                    encolar(cola, cola->principio->estado->izquierda);
            }
             //Derecha
            if(cola->principio->estado->derecha!= NULL){                                    //Ver si tiene algo en su rama derecha, e imprimir
                printf("%d,%c -> %d \n",cola->principio->estado->no_estado, 
                cola->principio->estado->transicion_der, cola->principio->estado->derecha->no_estado );
                
                if(!estados_visitados[cola->principio->estado->derecha->no_estado] && cola->principio->estado->derecha!= cola->fin->estado)
                    encolar(cola, cola->principio->estado->derecha);
            }
        estados_visitados[cola->principio->estado->no_estado]= true;                        //Marcar el estado como visitado
        desencolar_Elemento(cola);                                                          //Quitar ese estado de la lista
        }   
    } 

}


#include "construccionesThompson.h"
#endif