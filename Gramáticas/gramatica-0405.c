#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
Daniela Cortés Castillo
Reconocer en la siguiente gramática. 
A->aBa
B->bAb
B->c

Cadenas de la forma:
- abacaba
- aca
- ababacababa
Palíndromos con c en medio
*/

char cadena[]= "ababacababa" ;      //Cadena a reconocer
int indice=0;               //Indice del arreglo
int tamanio=0;              //Tamaño del arreglo

bool A(void);
bool B(void);
bool consumir(char c);

int main(void){
    tamanio= strlen(cadena); 

    if(A() && indice==tamanio){
        printf("Cadena aceptada\n");
    } else{
        printf("Cadena no aceptada\n");
    }

    return 0;
}

bool A(void){
    /*
        Símbolo inicial.
        Regla de producción: A-> aBa
    */
    if (consumir('a')){
        if( B() ){
                return consumir('a');   
        } 
    }
    
    return false;
}

bool B(void){
    /*
    Reglas de producción: 
    B-> bAb
    B-> c
    */
    
    if(consumir('b')){
        if (A()){
            return consumir('b');
        } 
    } else if (consumir('c')){
        return true;
    } 
    return false;
    
}

bool consumir(char c){
     if(cadena[indice]== c){
         indice++;
        return true;
    } else {
        return false;
    }
}
