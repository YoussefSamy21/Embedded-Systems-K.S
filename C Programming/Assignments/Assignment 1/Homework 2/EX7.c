#include <stdio.h>
// C program to find Factorial of a number
int main()
{
	int num,fact=1;
	printf("Enter an Integer: ");
	scanf("%d",&num);
	if(num<0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	else
	{
		while(num!=1)
		{
			fact*=num;
			num--;
		}
		printf("Factorial = %d",fact);		
	}
	
	return 0;
}