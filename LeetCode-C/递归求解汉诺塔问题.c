#include<stdio.h>

void move(char x, char z)
{
	printf("%c -> %c\n",x,z);
}

void hanoi(int n, char x, char y, char z)
{
	if(n==1)
	{
		move(x, z);
	}
	else
	{
		hanoi(n-1, x, z, y);
		move(x, z);
		hanoi(n-1, y, x, z);
	}
}

int main()
{
	int n;
	char a='a',b='b',c='c';
	scanf("%d",&n);
	hanoi(n, a,b,c);
	return 0;
}
