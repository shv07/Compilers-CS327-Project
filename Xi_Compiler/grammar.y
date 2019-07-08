
/* How to compile 
$bison calc.c
$gcc calc.tab.c -lm
Reference: http://dinosaur.compilertools.net/bison/bison_5.html
*/

%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>/* For math functions, cos(), sin(), etc. */
#include "calc.h"  /* Contains definition of `symrec'        */
int  yylex(void);
void yyerror (char  *); 
%}
%union {
double   val;  /* For returning numbers.                   */
int len;
symrec  *tptr;   /* For returning symbol-table pointers      */
char *string;
}


%token <string> VAR   /* Variable and Function            */
%token <string> use
%token <string> IDENTIFIER
%token <string> int
%token <string> bool
%token <string> STRING
%token <string> CONSTANT
%token <string> IF
%token <string> ELSE
%token <string> WHILE
%token <string> GOTO
%token <string> CONTINUE
%token <string> BREAK
%token <string> RETURN
%type  <val>  exp
%type  <string>  program
%type  <string>  header_list
%type  <string>  function_declaration
%type  <string>  header
%type  <string>  parameter_list
%type  <string>  type_list
%type  <string>  block
%type  <string>  blocks
%type  <string>  type
%type  <string>  declaration_list
%type  <string>  declaration
%type  <string>  expression
%type  <string>  assignment_expression
%type  <string>  cast_expression
%type  <string>  assignment_expression
%type  <string>  unary_expression
%type  <string>  additive_expression
%type  <string>  postfix_expression
%type  <string>  argument_expression_list
%type  <string>  unary_operator
%type  <string>  multiplicative_expression
%type  <string>  relational_expression
%type  <string>  equality_expression
%type  <string>  assignment_expression
%type  <string>  statement_list
%type  <string>  statement
%type  <string>  compound_statement
%type  <string>  expression_statement
%type  <string>  selection_statement
%type  <string>  iteration_statement
%type  <string>  jump_statement
%token <string> INUM



%right '='
%left '-' '+'
%left '*' '/'
%left NEG     /* Negation--unary minus */
 //%right '^'    /* Exponentiation        */

/* Grammar follows */

%%
program
	: header_list'\n' function_declaration
	;

header_list
	: header'\n'
	| header'\n' header_list
	;

header
	: use IDENTIFIER
	;

function_declaration
	: IDENTIFIER'('parameter_list')'':'type_list block
	;

type_list
	: type',' type_list
	| type
	;

type
	: int
	| bool
	| str
	| int'[INUM]'
	;

parameter_list
	: declaration_list
	;

declaration_list
	: declaration'\n' declaration_list
	| declaration
	;

declaration
	: IDENTIFIER':'type
	| IDENTIFIER':'type '=' expression
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

assignment_expression
	: unary_expression '=' assignment_expression
	| cast_expression
	| additive_expression
	;

unary_expression
	: postfix_expression
	| unary_operator cast_expression
	;

postfix_expression
	: IDENTIFIER
	| CONSTANT
	| STRING
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '!'
	| '|'
	;

cast_expression
	: unary_expression
	| cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

relational_expression
	: additive_expression
	| relational_expression '<' additive_expression
	| relational_expression '>' additive_expression
	| relational_expression '<=' additive_expression
	| relational_expression '>=' additive_expression
	;

equality_expression
	: relational_expression
	| equality_expression '==' relational_expression
	| equality_expression '!=' relational_expression
	;

blocks
	: '{' block '}'
	| block
	;

block
	: '{' statement_list '}'
	;

statement
	:
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	| function_declaration
	;

statement_list
	: statement
	| statement_list statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	;


iteration_statement
	: WHILE '(' expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
;
/* End of grammar */
%%


/* The symbol table: a chain of `struct symrec'.  */
symrec *sym_table = (symrec *)0;



symrec * putsym (char *sym_name,int sym_type){
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  ptr->name = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->name,sym_name);
  ptr->type = sym_type;
  ptr->value = 0; /* set value to 0 even if fctn.  */
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec *getsym (char *sym_name){
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}

int main ()
{
   yyparse ();
}

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}


//8888888888888888888888888888888888888888888
#include <ctype.h>
int yylex ()
{
  int c;

  /* Ignore whitespace, get first nonwhite character.  */
  while ((c = getchar ()) == ' ' || c == '\t');

  if (c == EOF)
    return 0;

  /* Char starts a number => parse the number.         */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval.val);
      return NUM;
    }

  /* Char starts an identifier => read the name.       */
  if (isalpha (c))
    {
      symrec *s;
      static char *symbuf = 0;
      static int length = 0;
      int i;

      /* Initially make the buffer long enough
         for a 40-character symbol name.  */
      if (length == 0)
        length = 40, symbuf = (char *)malloc (length + 1);

      i = 0;
      do
        {
          /* If buffer is full, make it bigger.        */
          if (i == length)
            {
              length *= 2;
              symbuf = (char *)realloc (symbuf, length + 1);
            }
          /* Add this character to the buffer.         */
          symbuf[i++] = c;
          /* Get another character.                    */
          c = getchar ();
        }
      while (c != EOF && isalnum (c));

      ungetc (c, stdin);
      symbuf[i] = '\0';

      s = getsym (symbuf);
      if (s == 0)
        s = putsym (symbuf, VAR);
      yylval.tptr = s;
      return s->type;
    }

  /* Any other character is a token by itself.        */
  return c;
}
