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

%type <string> inhtml
%type <string> head
%type <string> body
%type <string> inhead
%type <string> html
%type <string> heading
%type <string> paragraph
%type <string> table
%type <string> inheading
%type <string> inpara
%type <string> rows
%type <string> col
%%
html: "<html>" inhtml "</html>"		{printf("1\n");}

inhtml: head body		{printf("2\n");}

head: "<head>" inhead "</inhead>"	{printf("3\n");}

inhead: "<title>" text "</title>" text	{printf("4\n");}
		| text 		{printf("5\n");}

body: "<body>" inbody "</body>"		{printf("6\n");}

inbody: heading inbody	{printf("7\n");}
		| paragraph inbody	{printf("8\n");}
		| table inbody	{printf("9\n");}
		|	{printf("10\n");}

heading : "<h1>" inheading "</h1>"	{printf("11\n");}

inheading : text	{printf("12\n");}

paragraph : "<p>" inpara "</p>"		{printf("13\n");}

inpara : text	{printf("14\n");}

table : "<table>" intable "</table>"	{printf("15\n");}

intable : "<tr>" rows "</tr>" intable	{printf("16\n");}
		   | "<tr>" rows "</tr>"	{printf("17\n");}

rows : "<th>" col "</th>" rows	{printf("18\n");}
		| "<th>" col "</th>"	{printf("19\n");}

col : text	{printf("20\n");}
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
  
		

