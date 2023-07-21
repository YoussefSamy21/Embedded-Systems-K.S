// C program to Get the Value of the nth Least Significant Bit EX: 10 = 1010 , 3rd bit = 1 (counting from 0) 
#include <stdio.h>

int nth_LSB(int num , int bit);

void main()
{
	int num,bit;
	printf("Enter number: ");
	scanf("%d",&num);
	printf("Enter nth Bit: ");
	scanf("%d",&bit);
		
	if(nth_LSB(num,bit))
	{
		printf("bit %d = 1",bit);
	}
	else
	{
		printf("bit %d = 0",bit);
	}
}


int nth_LSB(int num , int bit)
{
	return ((num>>bit)&1);
}