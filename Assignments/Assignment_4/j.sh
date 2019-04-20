bison -d ershov.y
flex Lexical_ana.l
gcc -lfl lex.yy.c ershov.tab.c -g

