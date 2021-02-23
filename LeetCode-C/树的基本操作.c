#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef char ElementType;
typedef struct TNode* BinTree;
typedef struct SNode* Stack;

struct SNode{
	BinTree* Data;
	int Top;
	int MaxSize;
};

struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (BinTree*)malloc(MaxSize*sizeof(BinTree));
	S->MaxSize = MaxSize;
	S->Top = -1;
	return S;
}

int IsEmpty(Stack S)
{
	return S->Top == -1;
}

int IsFull(Stack S)
{
	return S->MaxSize - 1 == S->Top;
}

void Push(Stack S, BinTree X)
{
	if(!IsFull(S))
	{
		S->Data[++(S->Top)] = X;
	}
	else printf("Stack is Full!\n");
}

BinTree Pop(Stack S)
{
	if(!IsEmpty(S))
	{
		return S->Data[S->Top--];
	}
	else printf("Stack is Empty!\n");
}


BinTree CreateTree() // 先序遍历创建二叉树 
{
	ElementType X;
	BinTree BT;
	scanf("%c",&X);
	if(X == '#') BT = NULL;
	else
	{
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = X;
		BT->Left = CreateTree();
		BT->Right = CreateTree();
	}
	return BT;
}

void InorderTraversal(BinTree BT) // 非递归中序遍历 
{
	Stack S = CreateStack(MAX);
	while(BT || !IsEmpty(S))
	{
		while(BT)
		{
			Push(S, BT);
			BT = BT->Left;
		}
		BT = Pop(S);
		printf("%c",BT->Data);
		BT = BT->Right;
	}
}


int main()
{
	BinTree BT = CreateTree();
	InorderTraversal(BT);
	return 0;
}


