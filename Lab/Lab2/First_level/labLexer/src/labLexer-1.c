#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_LENGTH 100
#define EQ 1	// =
#define L 2		// <
#define LE 3	// <=
#define NE 4	// <>
#define G 5		// >
#define GE 6	// >=

int getRelop(char *Input, int *i)	//从第 i 位开始检测到关系运算符
{
	int state = 0;	//接收状态为 0
	while(1)
	{
		switch(state)
		{
			case 0:
				if (Input[*i] == '=')
				{
					(*i)++;
					state = 5;	// '='
					break;
				}
				else if (Input[*i] == '<')
				{
					state = 1;
					(*i)++;
					break;
				}
				else if (Input[*i] == '>')
				{
					state = 6;
					(*i)++;
					break;
				}
				else
				{
					return 0;	//读取到非法字符, 关系符读入结束, 结果为空
				}

			case 1:		//读入了 '<'
				if (Input[*i] == '=')
				{
					(*i)++;
					state = 2;	// '<='
					break;
				}
				else if (Input[*i] == '>')
				{
					(*i)++;
					state = 3;	// '<>' or '!='
					break;
				}
				else
				{
					state = 4;
					break;
				}
				
			case 2:
				return LE; //关系运算符读入结束, 结果为 '<='

			case 3:
				return NE;	//读入 '<>', 即 '!='

			case 4:
				return L;	//读取遇到非法字符, 结束, 结果为 '<'

			case 5:		//读入了 '='
				return EQ;	//关系符读入结束, 结果为 '='

			case 6:
				if (Input[*i] == '=')
				{
					(*i)++;
					state = 7;
					break;
				}
				else
				{
					state = 8;
					break;
				}
				
			case 7:
				return GE;	//读入 '>=', 结束

			case 8:
				return G;	//读取遇到非法字符, 结束, 结果为 '>'
		}
	}
}

int isRelop(char c)
{
	if(c == '=' || c == '<' || c == '>')
	{
		return 1;
	}
	else return 0;
}

int getWord(char *Input, int *i)
{
	int length = 0;
	while (Input[*i] != '\0' && !isRelop(Input[*i]))	//一直读取直到读到关系运算符
	{
		(*i)++;
		length++;
	}
	return length;	//返回字长度
}

const char *transRelop(int Relop)
{
	switch (Relop)
	{
		case EQ:
			return "=";

		case LE:
			return "<=";
	
		case NE:
			return "!=";		// !=
	
		case L:
			return "<";
	
		case GE:
			return ">=";
		
		case G:
			return ">";

		default:
			return NULL;
	}
}

int main()
{
	int i = 0;	//loop variable
	char *Input = (char *)malloc(sizeof(char) * MAX_LENGTH);
	memset(Input, '\0', MAX_LENGTH * sizeof(char));		// initialize
	gets(Input);	// get input

	while (Input[i] != '\0')	//循环读取, 直到到达数组末尾
	{
		int length = getWord(Input, &i);
		if (length != 0)
		{
			printf("(other,%d)", length);
		}
		int relop = getRelop(Input, &i);
		if (relop != 0)
		{
			printf("(relop,%s)", transRelop(relop));
		}
	}

	return 0;
}
