#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
Daniela Cortés Castillo
Reconocer en la siguiente gramática. 
A->BCDEa
B->bCD
C->cA 
D->d
E->e 
C->f 
B->a 

Ejemplos:
bcafdeadfdea
bfdfdea
afdea
bcacafdeadeadfdea
acafdeadea

*/

char cadena[]= "afdea" ;      //Cadena a reconocer
int indice=0;                        //Indice del arreglo

bool A(void);
bool B(void);
bool C(void);
bool D(void);
bool E(void);
bool F(void);
bool consumir(char c);

int main(void){
    int tamanio=0;              //Tamaño del arreglo
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
        Regla de producción: 
        A->BCDEa
    */

    if (B()){
       if(C()){
           if (D()){
               if (E()){
                   return consumir('a');
               }   
           }
        }
    }

    return false;
}

bool B(void){
    /*
        B->bCD
        B->a 
    */

    if (consumir('b')){
        if(C()){
            return D();
        }
    } else if(consumir('a')){
        return true;
    }

    return false;
}

bool C(void){
    /*
        Reglas de producción:
            C->cA 
            C->f 
    */
    if (consumir('c')){
            return A();
        } else if(consumir('f')){
            return true;
        }
    return false;
}

bool D(void){
    /*
        Reglas de producción:
           D->d 
    */
    if (consumir('d')){
            return true;
    }
    return false;
}

bool E(void){
    /*
        Reglas de producción:
           E->e
    */
    if (consumir('e')){
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
