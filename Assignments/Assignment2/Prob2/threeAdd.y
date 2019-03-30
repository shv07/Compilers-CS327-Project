/* How to compile 
$bison -d threeAdd.y
$flex threeAdd.l
$gcc threeAdd.tab.c lex.yy.c -lfl
Reference: http://dinosaur.compilertools.net/bison/bison_5.html
	 : https://stackoverflow.com/questions/35891282/3-address-code-generation-using-lex-and-yacc

*/

%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>

int k=97;   // for the three address code variables - a, b, c, ........

int  yylex(void);
void yyerror (char  *); 
char gencode(char word[],char first,char op,char second);
%}

%union {
char   val;  /* For returning numbers.                   */
}

%token <val>  NUM        
%type  <val>  exp

%right '='
%left '-' '+'
%left '*' '/'

/* Grammar follows */

%%
input:  input line{printf("shiv\n");}
|
;
line:
          '\n'
        | exp '\n'   { printf("\nt = %c \n",$1); }
        | error '\n' { 		yyerrok;                  }
;

exp:      NUM                { $$ = $1;                         }
        | exp '+' exp        { 	
				char word[3]="t";
        			char test=gencode(word,$1,'+',$3);
        			$$=test;
			     }

        | exp '-' exp        {

				char word[3]="t";
				char test=gencode(word,$1,'-',$3);
				$$=test;
				//free(test);
				
                       	     }

        | exp '*' exp        { 
				char word[3]="t";
				char test=gencode(word,$1,'*',$3);
				$$=test;
				//free(test);
                             }

        | exp '/' exp        { 
				char word[3]="t";
				char test=gencode(word,$1,'/',$3);
				$$=test;
				//free(test);
	                     }


        | '(' exp ')'        { $$ = $2;                         }
;


/* End of grammar */
%%





int main()
{
        yyparse();
        return 0;
}

void yyerror(char* str)
{
        printf("\n%s",str);
}
char gencode(char word[],char first,char op,char second)
{
    char x=k;
    k++;
    printf("%c = %c %c %c\n",x,first,op,second);
    return x; //Returns variable name like a,b,c, ...
}

