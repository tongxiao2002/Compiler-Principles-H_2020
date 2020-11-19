/*
 * exprL-pre-s3.y : A simple yacc expression parser
 *          Based on the Bison manual example. 
 * You need add rules with actions to complete the conversion 
 * from infix expression to corresponding Polish expression.
 */

%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXLEN 100
int yylex();
void yyerror(const char *s);
int lineno = 0;
typedef struct Expr
{
   float val;
   char expression[MAXLEN];
}Expr;
%}

%union {
   Expr expr;
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

%type  <expr> exp

%%
input   :
	  { lineno ++; }
        |  
          input
	  { 
	    printf("Line %d:\n\t", lineno++);
	  }
          line
        ;

line    : EOL			{ printf("\n");}
        | exp EOL 		{ printf("%s = %g at line %d\n", $1.expression, $1.val, @1.last_line);}
        ;

exp     : NUMBER                 
          { 
			$$.val = $1;
		    memset($$.expression, '\0', MAXLEN);
            sprintf($$.expression, "%g ", $1);
		  }
        | exp PLUS exp          
          {
			$$.val = $1.val + $3.val;
			memset($$.expression, '\0', MAXLEN);
			sprintf($$.expression, " + ");
            strcat($$.expression, $1.expression);
			strcat($$.expression, $3.expression);
		  }
        | exp MINUS exp          
          {
			$$.val = $1.val - $3.val;
			memset($$.expression, '\0', MAXLEN);
			sprintf($$.expression, " - ");
            strcat($$.expression, $1.expression);
			strcat($$.expression, $3.expression);
		  }
        | exp MULT exp          
          {
			$$.val = $1.val * $3.val;
			memset($$.expression, '\0', MAXLEN);
			sprintf($$.expression, " * ");
            strcat($$.expression, $1.expression);
			strcat($$.expression, $3.expression);
		  }
        | exp DIV exp          
          {
			$$.val = $1.val / $3.val;
			memset($$.expression, '\0', MAXLEN);
			sprintf($$.expression, " / ");
            strcat($$.expression, $1.expression);
			strcat($$.expression, $3.expression);
		  }
        | MINUS exp %prec UMINUS
          {
			$$.val = -$2.val;
			memset($$.expression, '\0', MAXLEN);
			sprintf($$.expression, " - ");
			strcat($$.expression, $2.expression);
		  }
        | exp EXPON exp          
          {
			$$.val = pow($1.val, $3.val);
			memset($$.expression, '\0', MAXLEN);
			sprintf($$.expression, " ** ");
            strcat($$.expression, $1.expression);
			strcat($$.expression, $3.expression);
		  }
        | LB exp RB              
          {
			$$.val = $2.val;
			memset($$.expression, '\0', MAXLEN);
			strcat($$.expression, $2.expression);
		  }
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

