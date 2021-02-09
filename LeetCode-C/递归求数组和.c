#include<stdio.h>

int ArraySum(int a[], int n); 

int main()
{
	int n, sum;
	scanf("%d",&n);
	int a[n], i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sum = ArraySum(a, n);
	printf("%d",sum);
	return 0;
}

int ArraySum(int a[], int n)
{
	int sum;
	if(n==1) sum=a[n-1];
	else
	{
		sum = a[n-1]+ArraySum(a, n-1);
	}
	
	return sum;
}

