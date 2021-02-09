#include<stdio.h>
#include<stdlib.h>
int Fibonacci(int n); 

int main()
{
	int n, answer;
	scanf("%d",&n);
	answer = Fibonacci(n);
	printf("%d",answer);
	system("pause");
	return 0;
}

int Fibonacci(int n)
{
	int answer;
	if(n==1||n==2)
	{
		answer = 1;
	}
	else
	{
		answer = Fibonacci(n-1) + Fibonacci(n-2);
	}
	return answer;
}


