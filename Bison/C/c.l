D			[0-9]
L			[a-zA-Z_]

%{
#include <stdio.h>
#include "c.tab.h"

void count();
%}
%%

"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"else"			{ count(); return(ELSE); }
"break"			{ count(); return(BREAK); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"return"		{ count(); return(RETURN); }
"void"			{ count(); return(VOID); }
"while"		{ count(); return(WHILE); }

{L}({L}|{D})*		{ count(); return(check_type()); }
L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }
{D}			{ count(); return(CONSTANT); }

"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
"&"			{ count(); return('&'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
[ \t\v\f\n]		{ count(); }
.			{ /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}

int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/
	return(IDENTIFIER);
}
