#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tratar_cadenas.h"
#include "lista.h"


/*
Considraciones en la expresion regular.
La letra 'E' será considerada como la cadena vacía épsilon.
El carácter '.' será tomado como la operación de concatenación.
*/


int main(int argc, char *argv[]){
    char *expresion;
    if(argc>1){
        expresion=argv[1];
    } else{
        return 0;
    }

    printf("\n\t Se ingresó la expresión:\t%s \n",expresion);               //Imprimir expresión
    
    int longitud_expresion= strlen(expresion);                              //Obtener longitud de expresión
    
    bool validacion= validar_operadores(expresion,longitud_expresion);      //Validar expresión
    if(!validacion){                                                        //Terminar programa si hay algún error en la expresión
        printf("Hay algún error en tu cadena, revisala\n");
        return 0;
    }
    
    Lista * lista= malloc(sizeof(Lista));
    lista= cadena_a_lista(expresion, longitud_expresion);                   //Pasar espresion a lista
    //imprimir_lista(lista);

    printf("\n");
    
    ver_concatenaciones(lista);                                             //Agregar concatenaciones
    imprimir_lista(lista);

    Lista * lista_postfija= malloc(sizeof(Lista));
    lista_postfija=pasar_Postfija(lista);

    free(lista);
    free(lista_postfija);
}

