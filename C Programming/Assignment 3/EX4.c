#include <stdio.h>

// C program to Calculate the Power of a Number using Recursion
int Power(int power,int base);
void main()
{
	int power,res = 1,base;
	printf("Enter base number: ");
	scanf("%d",&base);
	printf("Enter Power number (positive number): ");
	scanf("%d",&power);
	res = Power(power,base);
	printf("%d^%d = %d",base,power,res);
}

int Power(int power,int base)
{
	if(power != 0)
	{
		return (base * Power((power-1) , base) );
	}
	else
	{
		return 1;
	}
}