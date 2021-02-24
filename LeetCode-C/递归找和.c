#include<stdio.h>

typedef enum{false, true} bool;

void sum(int a[], int n, int m);
bool flag = false;
int main()
{
	int i, N;
	scanf("%d",&N);
	int a[10];
	for(i=0; i<N; i++)
	{
		scanf("%d",&a[i]);
	}
	int M;
	scanf("%d",&M);
	
	sum(a, N-1, M);
	flag==true?printf("YES"):printf("NO");
	
	return 0;
}

void sum(int a[], int n, int m)
{
	if(a[n] == m) flag = true;
	else if(n==0) ;
	else
	{
		sum(a, n-1, m-a[n]);
		sum(a, n-1, m);
	}
}



