%{

#include <stdio.h>

%}

%%

"<"	{printf("(relop,<)");}
"<="	{printf("(relop,<=)");}
"="	{printf("(relop,=)");}
">"	{printf("(relop,>)");}
">="	{printf("(relop,>=)");}
"<>"	{printf("(relop,<>)");}
[^<>=\r\n]+	{printf("(other,%d)", yyleng);}
[\r\n]	{return 0;}

%%

void flex_analyze()
{
	yylex();
}

int yywrap()
{
	return 1;
}
