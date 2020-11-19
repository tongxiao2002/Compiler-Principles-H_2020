CINC	 = -Isrc
CONF	 = config
SRC	 = src
BIN	 = bin
UTILSRC  = $(SRC)/list.c $(SRC)/error.c $(SRC)/ast.c

CC       = gcc -g $(CINC)
CXX	 = g++ -g $(CINC)

LEX      = flex
YACC     = bison

EXPRLEX  = expr

all: expr expr1 exprL

# Generate a compiler for a simple expression language,
# expr: the grammar is ambiguous, and uses precedence declarations
# expr1: the grammar is disambiguous.
# exprL: there is embedded code in the rules.
# exprL1: there is embedded code in the rules, which sets its semantic value.
exp%:
	mkdir -p $(SRC)
	mkdir -p $(BIN)
	$(YACC) -d -y -r solved -b $@ -o $(SRC)/$@.tab.c $(CONF)/$@.y
	$(LEX) -i -I -o $(SRC)/expr.lex.c $(CONF)/$(EXPRLEX).lex
	$(CC) -DDEBUG -o $(BIN)/$@ $(SRC)/expr.lex.c $(SRC)/$@.tab.c -lfl -lm

exprL%:
	mkdir -p $(SRC)
	mkdir -p $(BIN)
	$(YACC) -d -y -r solved -b $@ -o $(SRC)/$@.tab.c $(CONF)/$@.y
	$(LEX) -i -I -o $(SRC)/expr.lex.c $(CONF)/$(EXPRLEX).lex
	$(CC) -o $(BIN)/$@ $(SRC)/expr.lex.c $(SRC)/$@.tab.c -lfl -lm

clean:
	rm -f *.BAK *.o core *~* *.a 
	rm -f $(SRC)/*.tab.*
	rm -f $(SRC)/*.lex.* $(SRC)/*.out*
	rm -f $(BIN)/*
