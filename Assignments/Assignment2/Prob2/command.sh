bison -d threeAdd.y
flex threeAdd.l
gcc threeAdd.tab.c lex.yy.c -lfl
./a.out
