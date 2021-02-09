#include<stdio.h>

int find_max(int a[], int n);

int main()
{	
	int i, n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int max;
	max = find_max(a,n);
	printf("%d",max);
	
	return 0;
}

int find_max(int a[], int n)
{
	int max = a[n-1];
	if(n==1)
	{
		max = a[n-1];
	}
	else
	{
		if(find_max(a,n-1)>max) 
		max = find_max(a,n-1);
	}

	return max;
}
