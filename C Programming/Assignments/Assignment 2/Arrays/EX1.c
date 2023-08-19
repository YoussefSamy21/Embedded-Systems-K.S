#include <stdio.h>
// C program to find sum of 2 matrix of order 2*2
void main()
{
	float a[2][2] , b[2][2];
	printf("Enter the elements of 1st matrix:\n");
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	
	printf("Enter the elements of 2nd matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			scanf("%f",&b[i][j]);
		}
	}
	printf("Sum of Matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%.1f\t",a[i][j]+b[i][j]);
		}
		printf("\n");
	}
	
}