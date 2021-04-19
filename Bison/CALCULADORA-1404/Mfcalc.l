%{
 #include <stdio.h>
 #include <stddef.h>
 #include "Mfcalc.tab.h"
 #include "calc.h"
%}

%%

[0-9]+[.][0-9]+	{return NUM; }
[*]		{return '*'; }
[+]		{return '+'; }
[-]		{return '-'; }
[/]		{return '/'; }
[\^]	{return '^'; }
[(]		{return '('; }
[)]		{return ')'; } 
\n		{return '\n';}
[a-zA-Z]+	{
		   symrec *s = getsym (*yytext);
           if (!s)
             s = putsym (*yytext, VAR);
           yylval = s; /* or yylval.FUN = s. */
           return VAR;
}
[ ]*
.

