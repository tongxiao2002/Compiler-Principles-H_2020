/*
 * exprL-pre.y : A simple yacc expression parser
 *          Based on the Bison manual example. 
 * This file fails in the conversion 
 * from infix expression to corresponding Polish expression.
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
%right UMINUS

%type  <val> exp

%%
input   :
	  { lineno ++; 
	  }
        |  
          input
	  { 
	    printf("Line %d (%d):\t", lineno++, @1.last_line);
	  }
          line
        ;

line    : EOL			{ printf("\n");}
        | exp EOL 		{ printf(" = %g at line %d\n",$1, @1.last_line);}

exp     : NUMBER                 { $$ = $1;        }
        | {printf(" + ");} exp PLUS  exp          { $$ = $2 + $4;   }
        | {printf(" - ");} exp MINUS exp          { $$ = $2 - $4;   }
        | {printf(" * ");} exp MULT  exp          { $$ = $2 * $4;   }
        | {printf(" / ");} exp DIV   exp          { $$ = $2 / $4;   }
        | {printf(" - ");} MINUS  exp %prec UMINUS { $$ = -$3;       }
        | {printf(" ** ");}exp EXPON exp          { $$ = pow($2,$4);}
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

