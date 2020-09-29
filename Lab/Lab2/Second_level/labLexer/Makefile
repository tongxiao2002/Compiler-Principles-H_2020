CC = gcc -g
LEX = flex -i -I
INC = -I../pl0/include

all: labLexer-2 labLexer-2m

labLexer-2: ./grammer/relop.lex
	$(LEX) ./grammer/relop.lex
	$(CC) $(INC) -DLEXERGEN lex.yy.c ./src/labLexer-2.c -o labLexer-2
	
labLexer-2m: ./src/labLexer-2.c
	$(CC) ./src/labLexer-2.c -o labLexer-2m

clean:
	rm -f *.o repo *.yy.c labLexer*
