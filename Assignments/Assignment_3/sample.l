/* Declaration section*/
%{ 
#include<stdio.h>
#include<stdlib.h>
#include"sample.tab.h"
%} 
  
%% 
"<!DOCTYPE html>" {yylval.string =strdup(yytext);
		return doctype;
		}

"<html>" {yylval.string =strdup(yytext);
		return openhtml;
		}
"</html>" {//yylval.string = yytext;
		return closehtml;
		}
"<head>" {//yylval.string = strcat(yytext,"\0");
		return openhead;
		}
"</head>" {//yylval.string = yytext;
		return closehead;
		}
"<title>" {//yylval.string = strcat(yytext,"\0");
		return opentitle;
		}
"</title>" {//yylval.string = yytext;
		return closetitle;
		}

"<body>" {//yylval.string = strcat(yytext,"\0");
		
		return openbody;
		}
"</body>" {//yylval.string = yytext;
		return closebody;
		}

"<p>" {yylval.string =strdup(yytext);
		return openp;
		}
"</p>" {yylval.string =strdup(yytext);
		return closep;
		}
"<b>"        	{yylval.string =strdup(yytext); return openbold;}
"</b>"       	{yylval.string =strdup(yytext); return closebold;}
"<i>"        	{yylval.string =strdup(yytext); return openit;}
"</i>"       	{yylval.string =strdup(yytext); return closeit;}
"<em>"       	{yylval.string =strdup(yytext); return openem;}
"</em>"      	{yylval.string =strdup(yytext); return closeem;}
"<strong>"   	{yylval.string =strdup(yytext); return openstrong;}
"</strong>"  	{yylval.string =strdup(yytext); return closestrong;}
"<mark>"	{yylval.string =strdup(yytext); return openmark;}
"</mark>"  	{yylval.string =strdup(yytext); return closemark;}
"<small>"	{yylval.string =strdup(yytext); return opensmall;}
"</small>"  	{yylval.string =strdup(yytext); return closesmall;}
"<del>"		{yylval.string =strdup(yytext); return opendel;}
"</del>"  	{yylval.string =strdup(yytext); return closedel;}
"<ins>" 	{yylval.string =strdup(yytext); return openins;}
"</ins>"  	{yylval.string =strdup(yytext); return closeins;}
"<sub>"		{yylval.string =strdup(yytext); return opensub;}
"</sub>"  	{yylval.string =strdup(yytext); return closesub;}
"<sup>"		{yylval.string =strdup(yytext); return opensup;}
"</sup>"  	{yylval.string =strdup(yytext); return closesup;}


"<h1>" {//yylval.string = strcat(yytext,"\0");
		return openh1;
		}
"</h1>" {//yylval.string = yytext;
		return closeh1;
		}
"<h2>" {//yylval.string = strcat(yytext,"\0");
		return openh2;
		}
"</h2>" {//yylval.string = yytext;
		return closeh2;
		}
"<h3>" {//yylval.string = strcat(yytext,"\0");
		return openh3;
		}
"</h3>" {//yylval.string = yytext;
		return closeh3;
		}

"<table>" {yylval.string = strdup(yytext);
			return opentable;}
"</table>" {yylval.string = strdup(yytext);
		return closetable;}
"<caption>" {yylval.string = strdup(yytext);
		return opencaption;}
"</caption>" {yylval.string = strdup(yytext);
		return closecaption;}


"<tr>" {yylval.string = strdup(yytext);
		return opentr;}
"</tr>" {yylval.string = strdup(yytext);
		return closetr;}

"<th>" {yylval.string = strdup(yytext);
		return opentd;}
"</th>" {yylval.string = strdup(yytext);
		return closetd;}

"<td>" {yylval.string = strdup(yytext);
		return openth;}
"</td>" {yylval.string = strdup(yytext);
		return closeth;}

[A-Z| a-z |0-9| ]+ {yylval.string =strdup(yytext);
		//sscanf(yytext,"%s",&yylval);	
		return text;
		}


\n {}
.  {return yytext[0];}
%%     


