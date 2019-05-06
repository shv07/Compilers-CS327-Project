/* Declaration section*/
/*
 * Collaborators:
 * Deepak
 */
%{ 
#include <stdio.h>
#include "cal.h"
#include "cal.tab.h"
#include <ctype.h>

// for stripping the strings
char *strstrip(char *s)
{
        size_t size;
        char *end;

        size = strlen(s);

        if (!size)
                return s;

        end = s + size - 1;
        while (end >= s && isspace(*end))
                end--;
        *(end + 1) = '\0';

        while (*s && isspace(*s))
                s++;

        return s;
}

%} 

DIGIT    [0-9]
ID       [a-zA-Z][A-Za-z]*
IDS {ID}[_]?{DIGIT}+?{ID}?
OPSPACE  " "+
SINGLE "//"                                                 
NOTNEWLINE [^\n] 

%% 
"use" {
						yylval.string =strdup(strstrip(yytext));
						return USE;
}
"if"	{
						yylval.string =strdup(strstrip(yytext));
						return IF;
							}

"else"	{
						yylval.string =strdup(strstrip(yytext));
						return ELSE;
							}

"int"	{
						yylval.string =strdup(strstrip(yytext));
						return INT;
							}

"while"	{
						yylval.string =strdup(strstrip(yytext));
						return WHILE;
							}

"goto"	{
						yylval.string =strdup(strstrip(yytext));
						return GOTO;
							}

"return"	{
						yylval.string =strdup(strstrip(yytext));
						return RETURN;
							}

"break"	{
						yylval.string =strdup(strstrip(yytext));
						return BREAK;
							}


"continue"	{
						yylval.string =strdup(strstrip(yytext));
						return CONTINUE;
							}

"bool"	{				
						yylval.string =strdup(strstrip(yytext));
						return BOOL;
							}

"main"	{				
						yylval.string =strdup(strstrip(yytext));
						return MAIN;
							}

'_' {
	yylval.string = strdup(strstrip(yytext));
	return SUDODEC;
}

{IDS} {
				struct symrec *ptr;
				ptr = (struct symrec *) malloc (sizeof (struct symrec));
				ptr->name = strdup(strstrip(yytext));
				// printf ("id isss: %s\n", ptr->name);
				yylval.tptr = ptr;
				return IDENTIFIER;
            }

{DIGIT}+	{yylval.val = atoi(strdup(strstrip(yytext)));
		return INUM;
		}

{SINGLE}{NOTNEWLINE}* {
            // printf( "Single line comment: %s  comment end\n", yytext);
            }

[ \t\n]+          /* eat up whitespace */
'\n' /*dont give a blah*/

.  {
	return yytext[0];
}
%%     

