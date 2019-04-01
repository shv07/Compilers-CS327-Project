/* Declaration section*/
%{ 
#include<stdio.h>
#include<stdlib.h>
#include"sample.tab.h"
%} 
  
%% 

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

"<p>" {//yylval.string = strcat(yytext,"\0");
		return openp;
		}
"</p>" {//yylval.string = yytext;
		return closep;
		}

"<h1>" {//yylval.string = strcat(yytext,"\0");
		return openh;
		}
"</h1>" {//yylval.string = yytext;
		return closeh;
		}

"<table>" {return opentable;}
"</table>" {return closetable;}

"<tr>" {return opentr;}
"</tr>" {return closetr;}

"<th>" {return openth;}
"</th>" {return closeth;}

[a-z |0-9| ]+ {yylval.string =strdup(yytext);
		//sscanf(yytext,"%s",&yylval);	
		return text;
		}


\n {}
.  {return yytext[0];}
%%     


