#include<stdio.h>

int count;

void backtracking(int num, int factor);

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int num;
	for(i=0; i<n; i++)
	{
		count = 0;
		scanf("%d",&num);
		backtracking(num, 2);
		printf("%d",count);
	}
	return 0;
}

void backtracking(int num, int factor)
{
	int i;
	if(num==1) count++;
	else for(i = factor; i<=num; i++)
	{
		if(num%i==0)
		backtracking(num/i, i);
	}
	
}
