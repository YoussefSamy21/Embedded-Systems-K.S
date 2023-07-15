#include <stdio.h>

// C program to Calculate Sum of Natural Numbers
int main()
{
	int num,sum=0;
	printf("Enter an Integer: ");
	scanf("%d",&num);
	while(num!=0)
	{
		sum+=num;
		num--;
	}
	printf("Sum = %d",sum);
	
	return 0;
}