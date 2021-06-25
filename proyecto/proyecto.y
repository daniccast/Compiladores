%{
	#include <stdio.h>
	extern int column;
	extern FILE *yyin;
	void yyerror(char const *s);
%}

%union { 
    char *s; 
} 
%token <double> IDENTIFIER CONSTANT STRING_LITERAL 
%token LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP 
%token CHAR INT CONST
%token IF WHILE RETURN BREAK

%start translation_unit

%%

primary_expression
	: IDENTIFIER			{printf("IDENTIFIER");}
	| STRING_LITERAL
	| '(' expression ')'
	| CONSTANT				{printf("CONSTANT");}
	;

postfix_expression
	: primary_expression
	| postfix_expression '(' argument_expression_list ')'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

multiplicative_expression
	: postfix_expression
	| multiplicative_expression '*' postfix_expression
	| multiplicative_expression '/' postfix_expression
	| multiplicative_expression '%' postfix_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression {printf("add-int");}
	| additive_expression '-' multiplicative_expression
	;

relational_expression
	: additive_expression
	| relational_expression '<' additive_expression		{printf("< \t");}
	| relational_expression '>' additive_expression		{printf("> \t");}
	| relational_expression LE_OP additive_expression  	{printf("<= \t");}
	| relational_expression GE_OP additive_expression  	{printf(">= \t");}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression {printf("==\t");}
	| equality_expression NE_OP relational_expression {printf("!=\t");}
	;

logical_and_expression
	: equality_expression
	| logical_and_expression AND_OP equality_expression {printf("&&\t");}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression {printf("||\t");}
	;

conditional_expression
	: logical_or_expression
	;

assignment_expression
	: conditional_expression
	| postfix_expression '=' assignment_expression
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer {
									printf("Variable creada\n");
									printf("\t\tconst/16 v0 valorHX\n");
								 }
	;

type_specifier
	: CHAR
	| INT
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: CONST
	| type_qualifier_list CONST
	;

initializer
	: assignment_expression
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement					{ printf("Fin de IF\n");	}
	;

iteration_statement
	: WHILE '(' expression ')' statement {printf("Fin While\n");}
	;

jump_statement
	: BREAK ';'
	| RETURN ';'
	| RETURN expression ';' {printf("Devolver. Fin de programa.\n");}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%


void yyerror(char const *s) {
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main( int argc, char **argv){
	++argv, --argc; /* skip over program name */
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else	
		yyin = stdin;
	return yyparse();
}
