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

html : { char *x= " \\documentclass[11pt]{article} \n \\usepackage{amsmath,textcomp,amssymb,geometry,graphicx,enumerate} \\usepackage{algorithm} % \\n Boxes/formatting around algorithms \n \\usepackage[noend]{algpseudocode} \%\\ Algorithms  \n\\usepackage{hyperref}  \n\\usepackage{tabto}   \n\\hypersetup{   \ncolorlinks=true,    \nlinkcolor=blue,    \nfilecolor=magenta, \n  urlcolor=blue, \n}";
printf( "\n%s\n" ,x);
} openhtml inhtml closehtml 

;
inhtml : head body {printf("head started\n");}
;

head : openhead inhead closehead {printf("\n");}
;
inhead : opentitle text closetitle text		{printf("\\title{%s}\n",$2);}
	|text		{printf("only head : %s\n",$1);}
;
body : openbody inbody closebody {printf("bodystart\n");}
;
inbody : paragraph inbody	{printf("Start Paragraph\n");}
	|heading inbody 	{printf("Start heading\n");}
	|table inbody		{printf("Start table\n");}
	|text                    {$$=strdup($1);}
;
paragraph : openp text closep	{printf("\\newline\n%s\n\\newline",$2);}
;
heading : openh text closeh	{printf("\n\\section{%s}\n",$2);}
;
table : {printf("\\begin{tabular}")} opentable intable closetable  {printf("\\end{tabular}")}
;
intable : opentr rows closetr intable	{printf("Rows=\n");}
		   | opentr rows closetr	{printf("17\n");}
;
rows : openth col closeth rows	{printf("%s\n",$2);}
	| 	{printf("19\n");} //strcpy($$,"abc");}
;
col : text	{printf("20\n");}//strcpy($$,"abc");}
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
