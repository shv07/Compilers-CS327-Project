%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>
int  yylex(void);
void yyerror (char  *); 

%}

%union {
char* string;
}


%token <string> text
%token <string> opentag
%token <string> closetag
%type <string> html 
%%

html : opentag text closetag {//$$ = strdup($2);
			 printf("ddd%s",$2);}
;
%%


int main(){
	yyparse();
    return 0;
}


void yyerror(char* str)
{
    printf("\n%s",str);
}
