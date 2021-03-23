#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolExp.h"

int main(int argc, char *argv[]){
    char *expresion;
    if(argc>1){
        expresion=argv[1];
    } else{
        return 0;
    }
    printf("\tSe ingresó la expresión:\t%s \n",expresion);
    int longitud_expresion= strlen(expresion);
    
    generar_arbol(expresion, longitud_expresion);

    
    
}

