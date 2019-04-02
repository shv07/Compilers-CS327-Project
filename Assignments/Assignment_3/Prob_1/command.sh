bison -d sample.y
flex sample.l
gcc sample.tab.c lex.yy.c -lfl
./a.out < standard_input.txt > output.txt
