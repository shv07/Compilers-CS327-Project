%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>
#include "trying.h"
int  yylex(void);
void yyerror (char  *); 
typedef unsigned char utf8_t; 		
%}

%union {
	char* string;
	struct codes *test;
	struct top *testtt;
}

%token <string> doctype
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

%token <string> openbold
%token <string> closebold

%token <string> openit
%token <string> closeit

%token <string> openem
%token <string> closeem

%token <string> openstrong
%token <string> closestrong

%token <string> openmark
%token <string> closemark

%token <string> opensmall
%token <string> closesmall

%token <string> opendel
%token <string> closedel

%token <string> openins
%token <string> closeins

%token <string> opensub
%token <string> closesub

%token <string> opensup
%token <string> closesup

%token <string> opentable
%token <string> closetable

%token <string> opencaption
%token <string> closecaption

%token <string> openth
%token <string> closeth

%token <string> opentd
%token <string> closetd

%token <string> opentr
%token <string> closetr


%token <string> openh1
%token <string> closeh1

%token <string> openh2
%token <string> closeh2

%token <string> openh3
%token <string> closeh3

%type <string> html 
%type <string> head
 
%type <string> body
%type <string> inbody

%type <string> inhead
%type <string> paragraph
%type <string> inpara

%type <string> heading

%type <string> inhtml 

%type <test> table
%type <test> rows
%type <test> col
%type <test> intable
%type <testtt> incaption
%%

html :                                                                                        {    char *x= "\\documentclass[11pt]{article} \n\\usepackage{amsmath,textcomp,amssymb,geometry,graphicx,enumerate, ulem, xcolor} \n\\usepackage{algorithm} \n\\usepackage[noend]{algpseudocode}\n\\usepackage{hyperref}\n\\usepackage{tabto}\n\n" ;
printf( "%s\n" ,x);} doctype openhtml inhtml closehtml
;


inhtml : head body {}
;

head : openhead inhead closehead {}
;
inhead : opentitle text closetitle text	{printf("\n\\title{%s}", $4);free($4);}
	|text		{printf("\n\\title{%s}", $1); free($1); }
;


body :  {printf("\n\\begin{document} \n\\maketitle \n"); }     
	openbody inbody closebody 
	{
	//printf("\n\n%s\n\n", $2); 
	printf("\n\\end{document} \n"); 
	}
;


inbody : txt inbody            {/*printf("%s",$1);*/}
				//printf("\n%s\n",$1);}
	|paragraph inbody	{/*printf("para\n");$$=strdup(strcat(strdup($1),strdup($2)));*/ }
	|heading inbody 	{/*printf("head\n");$$=strdup(strcat(strdup($1),strdup($2)));*/ }
	|table inbody		{/*printf("fda\n");$$=strdup(strcat(strdup($1),strdup($2)));*/}
	|   			{}
;

txt : text {printf("%s", $1);} txt					
	| openbold text closebold {printf("\\textbf{%s}", $2);} txt				
	| openit text closeit 
								{
								printf("\n\\textit{%s}\n", $2);
										} txt
	
	| openit openbold text closebold closeit 
								{
								printf("\n\\textit{\\textbf{%s}}\n", $3);
										} txt

	| openbold openit text closeit closebold 
								{
								printf("\n\\textbf{\\textit{%s}}\n", $3);
										} txt



	| openem text closeem 
								{
								printf("\n\\emph{%s}\n", $2);	
								} txt

	| openstrong text closestrong 
										{
										printf("\n\\textbf{%s}\n", $2);	
										} txt
	| opendel text closedel 
											{
											printf("\n\\sout{%s}\n", $2);	
											} txt
	| openins text closeins 
											{
											printf("\n\\underline{%s}\n", $2);	
											} txt
	| openmark text closemark 
											{
											printf("\n\\colorbox{yellow}{%s}\n", $2);	
											} txt
	| text opensub text closesub 
											{
											printf("\n%s$_{%s}$\n", $1,$3);	
											} txt
	| text opensup text closesup 
											{
											printf("\n%s$^{%s}$\n", $1,$3);	
											} txt
	| opensmall text closesmall 
											{
											printf("\n\\small{%s}\n", $2);	
											} txt	
	| {}
;

paragraph : openp inpara closep {}
; 

inpara    : text inpara					{
								printf("\n\\par{%s}\n", $1);
								}
	| openbold text closebold inpara			{	
								printf("\n\\par{\\textbf{%s}}\n", $2);
									}
	| openit text closeit inpara
								{
								printf("\n\\par{\\textit{%s}}\n", $2);
										}
	
	| openit openbold text closebold closeit inpara
								{
								printf("\n\\par{\\textit{\\textbf{%s}}}\n", $3);
										}

	| openbold openit text closeit closebold inpara
								{
								printf("\n\\par{\\textbf{\\textit{%s}}}\n", $3);
										}



	| openem text closeem inpara
								{
								printf("\n\\par{\\emph{%s}}\n", $2);	
								}

	| openstrong text closestrong inpara
										{
										printf("\n\\par{\\textbf{%s}}\n", $2);	
										}
	| opendel text closedel inpara
											{
											printf("\n\\par{\\sout{%s}}\n", $2);	
											}
	| openins text closeins inpara
											{
											printf("\n\\par{\\underline{%s}}\n", $2);	
											}
	| openmark text closemark inpara
											{
											printf("\n\\par{\\colorbox{yellow}{%s}}\n", $2);	
											}
	| text opensub text closesub inpara
											{
											printf("\n\\par{%s$_{%s}$}\n", $1,$3);	
											}
	| text opensup text closesup inpara
											{
											printf("\n\\par{%s$^{%s}$}\n", $1,$3);	
											}
	| opensmall text closesmall inpara
											{
											printf("\n\\par{\\small%s}\n", $2);	
											}	
	| {}
;


heading : openh1 text closeh1	    {printf("\n\\section{%s}\n", $2);}
	| openh2 text closeh2	    {printf("\n\\subsection{%s}\n", $2);}
	| openh3 text closeh3	    {printf("\n\\subsubsection{%s}\n", $2);}
;
table : opentable incaption closetable   
				{
					$$->count = $2->count;																	
				//	$$->code = strdup($2->code);
					printf("\\begin{table}\n\\centering\n");
					printf("\n%s\n",$2->code1);
					printf("\\begin{tabular}{");	
					int temp;
					temp = $$->count;
					for(int i=0; i<temp; i++){
						printf("|c|");	
					}
					printf("}");
					printf("\n%s\n",$2->code2);
					printf("\\end{tabular}\n\\end{table}\n");	
					}
;
incaption : opencaption text closecaption intable	{   
														char* temp;
														char* temp2;
														temp=strdup(strcat(strdup("\\caption{"),strdup($2)));
														temp2=strdup(strcat(strdup(temp),strdup("}\n")));
														$$->code1 = strdup(strcat(strdup(temp),strdup("}\n")));
														$$->code2 = strdup($4->code);
														$$->count = $4->count;
													}													
			| intable		{
				$$->code2 = strdup($1->code);
				$$->count = $1->count;
				$$->code1 = strdup("");	
				}
;
intable : opentr rows closetr intable	{char* temp;
										temp=strdup(strcat(strdup($2->code),strdup(" \\\\ \n")));
										$$->code=strdup(strcat(temp,strdup($4->code)));
										$$->count = $2->count;
										free($2->code);free($4->code); 
										}
		| opentr rows closetr		{$$->code = strdup($2->code);   free($2->code);
									 }
;
rows : openth col closeth rows	{$$->code = strdup(strcat(strdup(strcat(strdup($2->code),strdup(" & "))),strdup($4->code)));
								$$->count = $4->count + 1;free($2->code);free($4->code);
							}
	|openth col closeth		{$$->code = strdup($2->code);
							$$->count = 1;free($2->code);
							}
	|opentd col closetd rows	{char* temp;
								char* temp2;
								char* temp3;
								temp=strdup(strcat(strdup("\\textbf{"),strdup($2->code)));
								temp2=strdup(strcat(strdup(temp),strdup("}")));
								temp3=strdup(strcat(strdup(temp2),strdup(" & ")));
								$$->code=strdup(strcat(temp3,strdup($4->code)));
								$$->count = $4->count + 1;free($2->code);free($4->code);
							}
	|opentd col closetd	  { char* temp;
							char* temp2;
							temp=strdup(strcat(strdup("\\textbf{"),strdup($2->code)));
							$$->code = strdup(strcat(strdup(temp),strdup("}")));
							$$->count = 1;free($2->code);
							}
;
col : text	{
		$$->code = strdup($1);
		} 
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
