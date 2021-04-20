/*
Autora: Daniela Cortés Castillo
Compiladores.
Abril, 2021

Implementación del algoritmo de Thompson para pasar de una expresión regular a un AFN.

Considraciones en la expresion regular.
La letra 'E' será considerada como la cadena vacía épsilon.
El carácter '.' será tomado como la operación de concatenación.
Además de 'E . | *', todos los demás carácteres se tomarán como parte del alfabeto.

La expresión debe pasarse como parámetro en el omento de ejecutar. Ejemplo:
gcc thompson.c -o thompson <-Compila
./thompson "expresion"
./thompson "a|c"

Generará una imágen PNG con el automáta en la carpeta AFNS.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "estructuras.h"
#include "tratar_cadenas.h"
#include "Infija_Postfija.h"
#include "construccionesThompson.h"
 

int main(int argc, char *argv[]){
    char *expresion;
    if(argc>1){
        expresion=argv[1];
    } else{
        return 0;
    }

    int longitud_expresion= strlen(expresion);                              //Obtener longitud de expresión

    if (longitud_expresion==0){
        printf("Ingresa algo entre comillas\n");
        return 0;
    }
    
    printf("\n\t Se ingresó la expresión:\t%s \n",expresion);               //Imprimir expresión
    
    
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
    //imprimir_lista(lista);


    Lista * lista_postfija= malloc(sizeof(Lista));                          //Pasar expresión a postfija
    lista_postfija=pasar_cadena(lista);
    //imprimir_lista(lista_postfija); 
      
    AFN * raiz= malloc(sizeof(AFN));
    raiz= construirThompson(lista_postfija);                                //Construcción del grafo

    obtener_Conteo();                                                       //Conteo de AFNS para generar archivo
    abrir_archivo_dot(expresion);                                           //Iniciar archivo .txt para generar el gráfico
    printf("\t\t AFN GENERADO:\n");
    Imprimir_AFD(raiz);

    //------  GENERAR ARCHIVO TXT PARA DOT.
    
    printf("\n\nNombre de la imagen: \t");
    printf("a%d.png\n Encuentrala en la carpeta AFNS\n", conteo);

    char instruccion[25]={};

    strcat(instruccion, "dot -Tpng -O AFNS/a");
    strcat(instruccion,conteo_s);
    strcat(instruccion,".txt");

    system(instruccion);
    usleep(500);
    
    free(lista);
    free(lista_postfija);
    free(raiz);
}

