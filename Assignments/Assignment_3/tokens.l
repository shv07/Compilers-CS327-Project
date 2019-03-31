/* Declaration section*/
%{ 
	#include<stdio.h>
    #include<stdlib.h>
    #include"parser.tab.h"
    #include<math.h>
%} 
  
%% 
[a-z]+ {yylval.string = yytext;
		return text;
		}
\n {return 0;}
"<"[a-z]+">" {return yytext;}
"</"[a-z]+">" {return yytext;}
%%     





