#include <stdio.h>
// C Function to take integer number and Sum all its digits 
int Sum_Digits(int num);
void main()
{
	int x,res;
	printf("input:");
	scanf("%d",&x);
	res = Sum_Digits(x);
	printf("output:%d",res);
}

int Sum_Digits(int num)
{
	int sum = 0;
	while(num > 0)
	{
		sum = sum + (num%10);
		num/=10;
	}
	return sum;
}