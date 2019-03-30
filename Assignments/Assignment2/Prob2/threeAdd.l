%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"threeAdd.tab.h"
    #include<math.h>
    
%}

%%
[0-9]+ {
	yylval.val=yytext[0];
	return NUM;
}

\n {return 0;}
. {return yytext[0];}
%%

