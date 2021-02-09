#include<stdio.h>
void Division_Algorithm(int x, int y); 

int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	Division_Algorithm(x, y);
	return ;
}

void Division_Algorithm(int x, int y)
{
	int a,b;
	a = y;
	b = x%y;
	if(b==0)
	{
		printf("%d",y);
	}
	else
	{
		Division_Algorithm(a,b);
	}
	
}

