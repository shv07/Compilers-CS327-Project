/* Declaration section*/
%{ 
#include<stdio.h>
#include<stdlib.h>
#include"sample.tab.h"
%} 
  
%% 

"<htm>" {//yylval.string = strcat(yytext,"\0");
		return opentag;
		}
"</htm>" {//yylval.string = yytext;
		return closetag;
		}
[a-z| ]+ {yylval.string = strdup(yytext);
	//sscanf(yytext,"%s",&yylval);	
	return text;
		}


\n {return 0;}
.  {return yytext[0];}
%%     


