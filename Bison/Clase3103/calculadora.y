%{

/*
	bison
	Que está inspirado en YACC. La extensión es .y
	Recibe gramaticas libres de contexto.
	Terminales en mayúsculas, no terminales minúscula.
*/

#include<stdio.h>

void yyerror(char *mensaje){
	printf("Error: %s", mensaje);
}

%}

%token NUMERO

%%

entrada:
%empty
;
entrada: linea
;
linea: '\n'
;
linea: expresion '\n' {printf("Resultado = ?\n");}
;
expresion: NUMERO
;
expresion: expresion expresion '+'
;
expresion: expresion expresion '-'
;
expresion: expresion expresion '*'
;
expresion: expresion expresion '/'
;

%%

int main(void){
	yyparse();
	return 0;
}





