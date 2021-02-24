#include<stdio.h>

void gth(char ch[], int x);

int main()
{
	char ch[100];
	gets(ch);
	gth(ch, 0);
	return 0;
}

void gth(char ch[], int x)
{
	if(ch[x]!='!') gth(ch, x+1);
	else ;
	printf("%c",ch[x]); 
}
