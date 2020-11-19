/*
 * expr.y : A simple yacc expression parser
 *          Based on the Bison manual example. 
 * The parser uses precedence declarations to eliminate conflicts.
 */

%{
#include <stdio.h>
#include <math.h>
int yylex();
void yyerror(const char *s);
int lineno = 0;
%}

%union {
   float val;
   char *op;
}
%locations

%token <val> NUMBER
%token <op> PLUS MINUS MULT DIV EXPON
%token EOL
%token LB RB

%left  MINUS PLUS
%left  MULT DIV
%right EXPON

%type  <val> exp

%%
input   :
	  { lineno ++; }
        |  
          input
	  { printf("Line %d (%d):\t", lineno++, @1.last_line);
	  }
          line
        ;

line    : EOL			{ printf("\n");}
        | exp EOL 		{ printf(" = %g at line %d\n",$1, @1.last_line);}

exp     : NUMBER                 { $$ = $1; printf("%g ", $1);       }
        | exp PLUS  exp          { $$ = $1 + $3; printf(" + ");  }
        | exp MINUS exp          { $$ = $1 - $3; printf(" - ");  }
        | exp MULT  exp          { $$ = $1 * $3; printf(" * ");  }
        | exp DIV   exp          { $$ = $1 / $3; printf(" / ");  }
        | MINUS  exp %prec MINUS { $$ = -$2; printf(" - ");      }
        | exp EXPON exp          { $$ = pow($1,$3); printf(" ** ");}
        | LB exp RB              { $$ = $2;        }
        ;

%%

void yyerror(const char *message)
{
  printf("%s\n",message);
}

int main(int argc, char *argv[])
{
  yyparse();
  return(0);
}

