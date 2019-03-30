/* How to compile 
$bison calc.c
$gcc calc.tab.c -lm
Reference: http://dinosaur.compilertools.net/bison/bison_5.html
*/

%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>
int k=97;
int  yylex(void);
void yyerror (char  *); 
char gencode(char word[],char first,char op,char second);
//int yywrap(void);
%}
%union {
char   val;  /* For returning numbers.                   */

//symrec  *tptr;   /* For returning symbol-table pointers      */
}

%token <val>  NUM        /* Simple double precision number   */
//%token <tptr> VAR FNCT  /* Variable and Function            */
%type  <val>  exp

%right '='
%left '-' '+'
%left '*' '/'
%left NEG     /* Negation--unary minus */
 //%right '^'    /* Exponentiation        */

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
    //char *res=malloc(sizeof(char)*4);
    //char temp[2];
    //sprintf(temp,"%d",k);
    char x=k;
    //strcpy(res, word);
     //strcat(res,temp);
    //word[1]=temp[0];
    k++;
    printf("%c = %c %c %c\n",x,first,op,second);
    //strcpy(res, word);
    return x; //Returns variable name like t1,t2,t3... properly
}
/*int yywrap()
{
    return 1;
}*/

