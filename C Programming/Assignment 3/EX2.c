#include <stdio.h>

// C program to Calculate Factorial of a number using Recursion
int factorial(int num);
void main()
{
	int x,res=1;
	printf("Enter a Positive number: ");
	scanf("%d",&x);
	res = factorial(x);
	printf("Factorial of %d = %d",x,res);
}
	
int factorial(int num)
{
	if(num>1)
	{
		return(num*factorial(num-1));
	}
}

