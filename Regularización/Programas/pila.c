#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int numero;
    struct nodo *siguiente;
};

struct pila{
    struct nodo *tope;
    int elementos;
};

struct pila STACK;

void iniciar_pila(){
    STACK.elementos=0;
    STACK.tope=NULL;
}

void push(int numero){
    /* Agrega un nuevo elemento a la pila */
    STACK.elementos++;
    struct nodo auxiliar;
      auxiliar.numero= numero;
    if(STACK.tope== NULL){
        auxiliar.siguiente=NULL;
    } else{
        auxiliar.siguiente= STACK.tope;
    }
    STACK.tope= &auxiliar;
}

void pop(){
    printf("\n\nElementos en pila: %d", STACK.elementos);
    printf("\tElemento en tope: %d", STACK.tope->numero);
}
int main(void){
    iniciar_pila();
    push(1);
    push(3);
    pop();
    push(5);
    pop();
 
    return 0; 
}