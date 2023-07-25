#include <stdio.h>
//C Function to sum numbers from 1 to 100(WITHOUT LOOP)

int Sum_Interval(int start , int end);

void main()
{
	int n1,n2,sum=0;
	printf("Enter start number: ");
	scanf("%d",&n1);
	printf("Enter end number: ");
	scanf("%d",&n2);
	sum = Sum_Interval(n1,n2);
	printf("Sum of numbers between %d & %d = %d",n1,n2,sum);
}

int Sum_Interval(int start , int end)
{
	return((start+end) * ((end-start+1) / 2));
}