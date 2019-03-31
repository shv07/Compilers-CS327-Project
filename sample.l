/* Declaration section*/
%{ 
#include<stdio.h>
#include<stdlib.h>
#include"sample.tab.h"
%} 
  
%% 

"<html>" {//yylval.string = strcat(yytext,"\0");
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

"<h>" {//yylval.string = strcat(yytext,"\0");
		return openh;
		}
"</h>" {//yylval.string = yytext;
		return closeh;
		}

"<table>" {return opentable;}
"</table>" {return closetable;}

"<tr>" {return opentr;}
"</tr>" {return closetr;}

"<th>" {return openth;}
"</th>" {return closeth;}

[a-z| ]+ {yylval.string = strdup(yytext);
		//sscanf(yytext,"%s",&yylval);	
		return text;
		}


\n {}
.  {return yytext[0];}
%%     


