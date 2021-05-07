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

char cadena[]= "acaa" ;      //Cadena a reconocer
int indice=0;               //Indice del arreglo
int tamanio=0;              //Tamaño del arreglo

bool A(void);
bool B(void);
bool consumir_a(void);
bool consumir_b(void);
bool consumir_c(void);

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
    if (consumir_a()){
        if( B() ){
            if (consumir_a()){
                return true;
            } else{
                return false;
            }
        } else {
            return false;
        }
    } else{
        return false;
    }

}

bool B(void){
    /*
    Reglas de producción: 
    B-> bAb
    B-> c
    */
    
    if(consumir_b()){
        if (A()){
            if (consumir_b()){
                return true;
            }
            else{
                return false;
            }
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