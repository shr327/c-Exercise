#include<stdio.h>

void Permutation(int a[], int Left, int Right);
void LeftShift(int a[], int Left, int Right);
void RightShift(int a[], int Left, int Right);

int main()
{
	int i, n;
	scanf("%d",&n);
	int a[n];
	
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	
	Permutation(a, 0, n-1);
	return 0;
}

void Permutation(int a[], int Left, int Right)
{
	if(Left==Right)
	{
		int i;
		for(i=0; i<=Right;i++)
		{
			printf("%d",a[i]);
		}
		printf("\n");
	}
	else
	{
		int i;
		for(i=Left;i<=Right;i++)
		{
			RightShift(a, Left, i);
			Permutation(a, Left+1, Right);
			LeftShift(a, Left, i);
		}
	}
	
}

void LeftShift(int a[], int Left, int Right)
{
	int tmp=a[Left];
	int i;
	for(i=Left;i<Right;i++)
	{
		a[i] = a[i+1];
	}
	a[Right] = tmp;
}

void RightShift(int a[], int Left, int Right)
{
	int tmp = a[Right];
	int i;
	for(i=Right;i>Left;i--)
	{
		a[i] = a[i-1];
	}
	a[Left] = tmp;
}

