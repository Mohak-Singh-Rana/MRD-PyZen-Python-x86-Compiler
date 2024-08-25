bison -d -t -v parser.y
flex -i lexer.l
g++ -g lex.yy.c parser.tab.c -o output -lfl

./output ../tests/mile3.py > asm.s 2> stack.txt

gcc -c asm.s -o asm.o
gcc asm.o -o asm
./asm