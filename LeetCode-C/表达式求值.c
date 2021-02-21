#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define INFINITY 1e9

typedef double ElementType;
typedef struct SNode* Stack;
typedef enum{num, opr, end} Type;

struct SNode{
	ElementType* Data;
	int MaxSize;
	int Top;
};

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->MaxSize = MaxSize;
	S->Top = -1;
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	return S;
}

int IsFull(Stack S)
{
	return S->Top==S->MaxSize-1;
}

int IsEmpty(Stack S)
{
	return S->Top==-1;
}

void Push(Stack S, ElementType X)
{
	S->Data[++(S->Top)]=X;
}

ElementType Pop(Stack S)
{
	return S->Data[(S->Top)--];
}

Type GetOp(char *Expr, int *start, char*str)
{
	int i = 0;
	
	while(1)
	{
		str[i] = Expr[*start];
		if(str[i]==' ')
		{
			str[i] = '\0';
			(*start)++;
			break;
		}
		else if(str[0] == '\0')
		{
			return end;
		}
		else
		{
			i++;
			(*start)++;
			if(Expr[*start]=='\0')
			{
				str[i] = '\0';
				break;
			}
		}
	}
	if(isdigit(str[0])||isdigit(str[1])) return num;
	else return opr;
}

ElementType PostfixExp(char *Expr)
{
	Stack S;
	Type T;
	ElementType Op1, Op2;
	char str[MAXOP];
	int start = 0;
	S = CreateStack(MAXOP);
	while((T = GetOp(Expr, &start, str))!=end)
	{
		if(T == num) Push(S, atof(str));
		else
		{
			if(!IsEmpty(S)) Op2 = Pop(S);
			else return -1;
			if(!IsEmpty(S)) Op1 = Pop(S);
			else return -1;
			switch(str[0])
			{
				case '+':
					Push(S, Op1+Op2); break;
				case '-':
					Push(S, Op1-Op2); break;
				case '*':
					Push(S, Op1*Op2); break;
				case '/':
					if(Op2==0)
					{
						return INFINITY;
					}
					Push(S, Op1/Op2); break;
				default:
					printf("未知运算符%s\n",str); break; 
			}
		}
	}
	if(!IsEmpty(S))
	{
		return Pop(S);
	}
	else return -1;
	
}

int main()
{
	char Expr[MAXOP];
	ElementType f;
	gets(Expr);
	f = PostfixExp(Expr);
	
	if(f==INFINITY)
	{
		printf("除数为0\n");
	}
	else if(f==-1)
	{
		printf("错误\n");
	}
	else
	{
		printf("%f\n",f);
	}
	return 0;
}
