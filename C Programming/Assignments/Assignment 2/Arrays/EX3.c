#include <stdio.h>
// C program to find transpose of a matrix
void main()
{
	int a[10][10],i,j,r,c,trans[10][10];
	printf("Enter rows and columns of matrix:\n"); // max rows and columns are 10
	scanf("%d %d",&r,&c);
	if(r>10 || c>10)
	{
		printf("Error! max rows and columns are 10");
	}
	printf("Enter elements of matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter elements a%d%d: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n Entered Matrix: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nTranspose of matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			trans[j][i] = a[i][j];
		}
	}
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d ",trans[i][j]);
		}
		printf("\n");
	}
}