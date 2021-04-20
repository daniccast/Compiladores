#ifndef _ColaEdos
#define _ColaEdos

//Definir nodos y cola para el recorrido del AFN
struct nodo_Estado{
    estado * estado;
	struct nodo_Estado * siguiente;
};
typedef struct nodo_Estado nodo_edo;

struct Cola_Edos{
	nodo_edo * principio;
	nodo_edo * fin;
};
typedef struct Cola_Edos cola_edos;


void encolar( cola_edos * lista, estado * edo);
void desencolar_Elemento(cola_edos * lista);

#include "estructuras.h"

/*  Crea el nodo para la cola y lo agrega al final de la misma.
	Recibe un estado.
	*/
void encolar( cola_edos * cola, estado * edo){
	
	if (edo == NULL){
		return ;
	}
	
	//printf("Recibe edo: %d \n", edo->no_estado);
	
	nodo_edo * nestado = malloc(sizeof(nodo_edo));
	nestado->estado= edo;


	if (cola->principio == NULL){
		cola->principio= nestado;
	} else{
		cola->fin->siguiente = nestado;
	}
	cola->fin= nestado;
	nestado->siguiente= NULL; 
}


/* Eliminar el primer nodo en la cola
	Recibe la cola a la que se le quitará el nodo.
	*/
void desencolar_Elemento(cola_edos * lista){
	if (lista->principio == NULL){
		printf("No hay elementos en la lista");
		return ;
	}
	
	if (lista->principio== lista->fin){
		free(lista->principio);
		lista->principio= NULL;
		lista->fin=NULL;
		return ;
	}
	
	nodo_edo * aux;
	aux= lista->principio;
	lista->principio= aux->siguiente;

	free(aux);
}


#include "ColaEdos.h"
#endif 