#include <stdio.h>

// C Program to check whether number positive or negative
int main()
{
	float x;
	printf("Enter a number: ");
	scanf("%f",&x);
	if(x > 0)
	{
		printf("%f is Positive",x);
	}
	else if(x < 0)
	{
		printf("%f is Negative",x);
	}
	else
	{
		printf("You Entered Zero");
	}
	
	return 0;
}