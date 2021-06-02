#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
Daniela Cortés Castillo
Reconocer en la siguiente gramática. 
S-> abSA
S-> bA
A-> aA
A-> c
ababbcacc

*/

char cadena[]= "ababbcaccc" ;      //Cadena a reconocer
int indice=0;               //Indice del arreglo
int tamanio=0;              //Tamaño del arreglo
bool A(void);
bool S(void);
bool consumir(char);


int main(void){
    tamanio= strlen(cadena); 

    if(S() && indice==tamanio){
        printf("Cadena aceptada\n");
    } else{
        printf("Cadena no aceptada\n");
    }

    return 0;
}

bool S(void){
    /*
        Símbolo inicial.
        Regla de producción: 
        S-> abSA
        S-> bA
    */

    if (consumir('a')){
        if (consumir('b')){
            if (S()){
                return A();
            } 
        }
    } else if(consumir('b')) {
            return A();
    } 
    
    return false;
}


bool A(void){
    /*
    Reglas de producción: 
    A-> aA
    A-> c
    */
    
    if(consumir('a')){
        return A();
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
