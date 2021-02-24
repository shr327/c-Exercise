#include<stdio.h>
#include<string.h>
typedef enum{false, true} bool;
bool b[1001]={0};
char s[1001], ans[1001];
int len;

void dfs(int i)
{
	int j;
	for(j=0; j<len; j++)
	{
		if(!b[s[j]])
		{
			b[s[j]] = 1;
			ans[i] = s[j];
			if(i == len-1) printf("%s\n",ans);
			else dfs(i+1);
			b[s[j]] = 0;
		}
	}
}

int main()
{
	scanf("%s",s);
	len = strlen(s);
	dfs(0);
	return 0;
}
