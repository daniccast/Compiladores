#ifndef   _archivo_dot
#define   _archivo_dot


void  abrir_archivo_dot(){
    FILE* archivo;
    strcat(nombre_archivo, conteo_s);
    strcat(nombre_archivo,".txt");

    archivo = fopen (nombre_archivo, "w");

    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
   
    fputs("digraph G {\n rankdir=LR \n { node [shape=plaintext] \"inicio\"; }\n", archivo);
    fclose(archivo);
}
 
void cerrar_archivo_dot(FILE * archivo){
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
   
    fputs("}", archivo);
    fclose(archivo);
}

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

void agregar_final(FILE * archivo, int estado){
   
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
    char cadena1[10];
    sprintf(cadena1, "%d", estado);
    fprintf(archivo,"{%s [label=\"%s\" shape=doublecircle]; }\n",cadena1,cadena1);

}

void agregar_inicio(FILE * archivo, int estado){
   
    if(archivo == NULL){
        fclose (archivo);
        return ;
    }
    char cadena1[10];
    sprintf(cadena1, "%d", estado);
    fprintf(archivo,"\"inicio\"->%s;\n",cadena1);

}

void obtener_Conteo(){
    FILE* cont;
    cont = fopen ("AFNS/conteo.txt", "r+");

    if(cont == NULL){
        fclose (cont);
        return ;
    }
    char linea[10];
    fgets(linea,10,cont);
    int number = (int) strtol(linea, NULL, 10) + 1;
    sprintf(linea, "%d", number);

    rewind(cont);
    fputs(linea, cont);

    fclose (cont);
    conteo= number - 1;

    sprintf(conteo_s, "%d", conteo);
}


#include "archivo_dot.h"
#endif