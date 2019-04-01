%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>
int  yylex(void);
void yyerror (char  *); 
typedef unsigned char utf8_t; 		
%}

%union {
char* string;
}


%token <string> text
%token <string> openhtml
%token <string> closehtml

%token <string> opentitle
%token <string> closetitle

%token <string> openhead
%token <string> closehead

%token <string> openbody
%token <string> closebody

%token <string> openp
%token <string> closep

%token <string> openh
%token <string> closeh

%token <string> opentable
%token <string> closetable

%token <string> openth
%token <string> closeth

%token <string> opentr
%token <string> closetr

%type <string> html 
%type <string> head
 
%type <string> body
%type <string> inbody

%type <string> inhead
%type <string> paragraph

%type <string> heading
%type <string> table
%type <string> rows
%type <string> col

%type <string> intable

%type <string> inhtml 

%%

html :                                                                                        {char *x= "\\documentclass[11pt]{article} \n\\usepackage{amsmath,textcomp,amssymb,geometry,graphicx,enumerate} \n\\usepackage{algorithm} \n\\usepackage[noend]{algpseudocode}   \n\\usepackage{hyperref}  \n\\usepackage{tabto}\n\n" ;
printf( "\n%s\n" ,x);} openhtml inhtml closehtml
;


inhtml : head body {printf("\n");}
;

head : openhead inhead closehead {printf("\n");}
;
inhead : opentitle text closetitle text	{printf("\n\\title{ %s}", $4);free($4);}
	|text		{printf("\n\\title{ %s}", $1); free($1); }
;


body :  {printf("\n\\begin{document} \n\\maketitle \n"); }     
	openbody inbody closebody 
	{
	//printf("\n\n%s\n\n", $2); 
	printf("\nend{document} \n"); 
	}
;


inbody : text                   {printf("%s",$1);}
				//printf("\n%s\n",$1);}
	|paragraph inbody	{/*printf("para\n");$$=strdup(strcat(strdup($1),strdup($2)));*/ }
	|heading inbody 	{/*printf("head\n");$$=strdup(strcat(strdup($1),strdup($2)));*/ }
	|table inbody		{/*printf("fda\n");$$=strdup(strcat(strdup($1),strdup($2)));*/}
	
;


paragraph : openp text closep	
	{
	//char *x=strdup(strcat(strcat(strdup("\\newline\n"),strdup($2)),strdup("\n\\newline \n"))); 
	printf("\n\\newline\n%s\\newline\n", $2);
	}
;


heading : openh text closeh	            
	{
	/*char *y=strdup(strcat(strdup(strcat(strdup("\\newline\n \\section{"),strdup($2))),strdup("} \n\\newline\n")));*/ 
	printf("\n\n\\section{%s}\n", $2);}
;


table :  opentable intable closetable  {$$=strdup("\ntable\n");}
;
intable : opentr rows closetr intable	{printf("\n");}
		   | opentr rows closetr	{printf("\n");}
;
rows : openth col closeth rows	{printf("\n");}
	| 	{printf("\n");} //strcpy($$,"abc");}
;
col : text	{printf("\n");}//strcpy($$,"abc");}
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
