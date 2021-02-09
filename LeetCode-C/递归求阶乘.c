#include<stdio.h>

int Factorial(int n);

int main()
{
	int n, answer;
	scanf("%d",&n);
	answer = Factorial(n);
	printf("%d",answer);
	return 0;
}

int Factorial(int n)
{
	int answer = n;
	if(n==1 ||n==0)
	{
		answer = 1;
	}
	else
	{
		answer *=Factorial(n-1); 
		
	}
	
	return answer;
}
