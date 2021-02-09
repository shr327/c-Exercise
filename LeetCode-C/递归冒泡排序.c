#include<stdio.h>

int *BubbleSort(int a[], int n); 

int main()
{
	int n, i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int *arr;
	arr = BubbleSort(a, n);
	
	for(i=0;i<n;i++)
	{
		
		printf("%d ",arr[i]);
	}
	return 0; 
}


int* BubbleSort(int a[],int n)
{
	int *arr = a;
	if(n==1);
	else
	{
		int i;
		for(i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				int tmp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=tmp;
			}
		}
		arr = BubbleSort(a, n-1);
	}
	return arr;
}

