#include <stdio.h>
// C Program to check whether a number is even or not
int main()
{
	int x;
	printf("Enter an integer you want to check: ");
	scanf("%d",&x);
	if(x%2 == 0)
	{
		printf("%d is Even",x);
	}
	else
	{
		printf("%d is Odd",x);
	}
	
	return 0;
}