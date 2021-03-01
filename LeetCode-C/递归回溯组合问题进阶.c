#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{false, true} bool;

char ans[1001];
bool b[1001];
char s[1001] = "123456789";
int sum1(const char str[], int k);

void combination(int n, int k, int count, int m);

int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	
	combination(n, k, 0, 0);
	return 0;
}

void combination(int n, int k, int count, int m)
{
	int i;
	if(m==k)// 另一个条件必须写在下面，有些奇怪 
	{
		if(sum1(ans, k)==n)
		printf("%s\n",ans);
	}
	else for(i=count; i<9; i++)
	{
		if(!b[s[i]])
		{
			ans[m] = s[i];
			b[s[i]] = 1;
			combination(n, k, i+1, m+1);
			b[s[i]] = 0;
		}
	}
}

int sum1(const char str[ ], int k)
{
	int i, x=0;
	for(i=0;i<k;i++)
	{
		x+=(int)str[i] - 48;
		//printf("%c",str[i]);
	}
	//printf("\n");
	//printf("%d\n",x); 
	return x;
}

