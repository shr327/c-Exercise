#include<stdio.h>
#include<stdlib.h>

typedef enum{false, true} bool;
bool Find(int matrix[4][4], int rows, int columns, int number)
{
	bool found = false;
	if(matrix!=NULL && rows>0 && columns>0)
	{
		int row = 0;
		int column = columns -1;
		while(row<rows && column>=0)
		{
			if(matrix[row][column]==number)
			{
				found = true;
				break;
			}
			else if(matrix[row][column]>number)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}
	return found;
}

int main()
{
	int rows=4, columns=4, number;
	int matrix[rows][columns];
	scanf("%d",&number);
	int i, j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<columns; j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	
	printf("%d",Find(matrix, rows, columns, number));
	return 0;
}

