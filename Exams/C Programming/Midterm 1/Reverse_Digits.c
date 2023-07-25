#include <stdio.h>
// C Function to revers digits in number

int Reverse_Digits(int num);

void main()
{
	int x,res;
	printf("input:");
	scanf("%d",&x);
	res = Reverse_Digits(x);
	printf("output:%d",res);
}

int Reverse_Digits(int num)
{
	int res = 0;
	while(num > 0)
	{
		res = (res*10) + (num%10);
		num/=10;
	}
	return res;
}