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

char cadena[]= "abbcc" ;      //Cadena a reconocer
int indice=0;               //Indice del arreglo
int tamanio=0;              //Tamaño del arreglo
bool A(void);
bool S(void);
bool consumir_a(void);
bool consumir_b(void);
bool consumir_c(void);

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

    if (consumir_a()){
        if (consumir_b()){
            if (S()){
                if (A()){
                    return true;
                } else{
                    return false;
                }
            } else{
                return false;
            }
        } else{
            return false;
        }
        
    } else if(consumir_b()) {
        if (A()){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }

}


bool A(void){
    /*
    Reglas de producción: 
    A-> aA
    A-> c
    */
    
    if(consumir_a()){
        if (A()){
            return true;
        } else {
            return false;
        }
    } else if (consumir_c()){
        return true;
    } else {
        return false;
    }
}

bool consumir_a(void){
    if(cadena[indice]=='a'){
        indice++;
        return true;
    } else {
        return false;
    }
}
bool consumir_b(void){
    if(cadena[indice]=='b'){
         indice++;
        return true;
    } else {
        return false;
    }
}

bool consumir_c(void){
    if(cadena[indice]=='c'){
         indice++;
        return true;
    } else {
        return false;
    }
}