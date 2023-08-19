// C program to check if a given number is a power of 3 (return 1 if true , otherwise return 0)
#include <stdio.h>

int Power3Check(int num);

void main()
{
	int x;
	printf("Enter number: ");
	scanf("%d",&x);
	
	if(Power3Check(x) && (x>0))
	{
		printf("%d is power of 3",x);
	}
	else
	{
		printf("%d is NOT power of 3",x);
	}
	
	
}

int Power3Check(int num)
{
	while(num > 1)
	{
		if( (num % 3) != 0)
		{
			return 0;
		}
		num/=3;
	}
	return 1;
}