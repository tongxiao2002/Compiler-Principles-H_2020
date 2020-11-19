/*
 * expr.lex : Scanner for a simple
 *            expression parser.
 */

%{
#include "expr.tab.h"
#ifdef DEBUG
#define debug(a) printf("%s", a)
#else
#define debug(a) 
#endif
void yyerror(const char *);
/* handle locations */
int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
    yycolumn += yyleng;
%}

%option yylineno

%%

[0-9]+     { yylval.val = atol(yytext);
             debug(yytext);
             return(NUMBER);
           }
[0-9]+\.[0-9]+ {
             debug(yytext);
             sscanf(yytext,"%f",&yylval.val);
             return(NUMBER);
           }
"+"        { debug("+"); yylval.op = "+";
             return(PLUS);}
"-"        { debug("-"); yylval.op = "-"; return(MINUS);}
"**"       { debug("**"); yylval.op = "**"; return(EXPON);}
"*"        { debug("*"); yylval.op = "*"; return(MULT);}
"/"        { debug("/"); yylval.op = "/"; return(DIV);}
"("        { debug("("); yylval.op = "("; return(LB);}
")"        { debug(")"); yylval.op = ")"; return(RB);}
\n         { yycolumn = 1; debug(""); return(EOL);}
[\t ]*     /* throw away whitespace */
.          { yyerror("Illegal character"); 
             return(EOL);
           }
%%

