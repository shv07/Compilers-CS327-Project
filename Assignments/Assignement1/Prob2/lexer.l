/* scanner for a toy Pascal-like language */

%{
/* need this for the call to atof() below */
#include <math.h>
%}

DIGIT    [0-9]
ID       [a-zA-Z][A-Za-z]*
STR	 \"(\\.|[^"\\])*\"

%%

{DIGIT}+|{DIGIT}+"."{DIGIT}*    {
            printf( "A constant: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }
"\\"	    ;
"\'"	    ;

if|break|use|while|else|return|length|int|bool|true|false|println|print|readln|class|extends|new|this|null|continue|{ID}"("")"        {
            printf( "A keyword: %s\n", yytext );
            }

{ID}[_]?[']?{DIGIT}+?{ID}?|{STR}        printf( "An identifier: %s\n", yytext );

"+"|"-"|"*"|"!"|"&"|"|"|"*>>"|"%"|"/"|"<"|">"|"="|"!="|"=="|"<="|">="   printf( "An operator: %s\n", yytext );

"//"[^}\n]*     /* eat up one-line comments */

[ \t\n]+          /* eat up whitespace */

";"	    ;
"{"|"}"|"("|")"|"["|"]"|"_"|"'"|","|"."|":"   printf( "A special character: %s\n", yytext );

.           printf( "Unrecognized character: %s\n", yytext );

%%

void main( argc, argv )
int argc;
char **argv;
    {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
    }
