#ifndef   _archivo_dot
#define   _archivo_dot

/*
    Escribe o genera el archivo txt para generar automáta,
    el label que contiene la expresión que se convirtió,define la dirección 
    en la que dibujaran los nodos en dot. Además define la etiqueta/label de 
    inicio para usar posteriormente.
    Recibe una cadena de carácteres que contiene la expresión que se está pasando a AFN.
*/
void  abrir_archivo_dot(char * expresion){
    FILE* archivo;
    strcat(nombre_archivo, conteo_s);
    strcat(nombre_archivo,".txt");

    archivo = fopen (nombre_archivo, "w");

    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
    
    fprintf(archivo, "digraph G {\nlabel= \"%s\";\nrankdir=LR \n{ node [shape=plaintext] \"inicio\"; }\n", expresion);
   
    fclose(archivo);
}

/*
    Esribe en el archivo txt para generar automáta,
    el parentesís final y cierra el archivo.
    Recibe el apuntador del archivo a cerrar.
*/
void cerrar_archivo_dot(FILE * archivo){
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
   
    fputs("}", archivo);
    fclose(archivo);
}

/*
    Esribe en el archivo txt para generar automáta,
    la transición de un estado a otro.
    Recibe el apuntador del archivo en dónde se escribirá
    y el número de estado(int), el símbolo(char) y el número de estado al que lleva ese símbolo(int).
*/
void agregar_transicion(FILE * archivo, int estado, char simbolo, int estado_siguiente){
   
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
    char cadena1[10],cadena2[10];
    
    sprintf(cadena1, "%d", estado);
    sprintf(cadena2, "%d", estado_siguiente);

    fprintf(archivo,"%s->%s [label=\"%c \"];\n",cadena1,cadena2,simbolo);

}

/*
    Esribe en el archivo txt para generar automáta,
    el código para definir el nodo del  estado final.
    Recibe el apuntador del archivo en dónde se escribirá
    y el número del estado final.
*/
void agregar_final(FILE * archivo, int estado){
   
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
    char cadena1[10];
    sprintf(cadena1, "%d", estado);
    fprintf(archivo,"{%s [label=\"%s\" shape=doublecircle]; }\n",cadena1,cadena1); //Para el doble círculo
}

/*
    Esribe en el archivo txt para generar automáta,
    la transición de inicio al estado inicial del AFN.
    Recibe el apuntador del archivo en dónde se escribirá
    y el número del estado inicial.
*/
void agregar_inicio(FILE * archivo, int estado){
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
    char cadena1[10];
    sprintf(cadena1, "%d", estado);
    fprintf(archivo,"\"inicio\"->%s;\n",cadena1);
}


/*
    Obtiene del archivo conteo.txt 
    el último número de automáta generado.
    Lo guarda en la variable global conteo.
*/
void obtener_Conteo(){
    //Definir apuntador de archivo y abrir para lectura y escritura.
    FILE* cont;
    cont = fopen ("AFNS/conteo.txt", "r+");

    if(cont == NULL){
        fclose (cont);
        return ;
    }

    char linea[10];
    //Obetener número
    fgets(linea,10,cont);
    //Convertir número a entero
    int number = (int) strtol(linea, NULL, 10) + 1;

    //Escribir nuevo n+úmero en línea
    sprintf(linea, "%d", number);

    //Escribir nuevo número en archivo
    rewind(cont);
    fputs(linea, cont);

    fclose (cont);

    //Asignar a variables el número de automáta
    conteo= number - 1;
    sprintf(conteo_s, "%d", conteo);
}


#include "archivo_dot.h"
#endif