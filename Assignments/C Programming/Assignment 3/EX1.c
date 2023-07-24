#include <stdio.h>

// C program to find Prime numbers between 2 Intervals

void findPrime(int n1,int n2);
void main()
{
	int n1,n2;
	printf("Enter two numbers (Intervals):\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	findPrime(n1,n2);
}

void findPrime(int n1,int n2)
{
	int flag = 0,count = 2;
	printf("Prime numbers between %d and %d are: ",n1,n2);
	if(n1 == 1 || n1 == 0)
	{
		n1 = 2;
	}
	while(n1 <= n2)
	{
		while(count < n1)
		{
			if( (n1 % count) == 0)
			{
				flag = 1; // not prime
				break;
			}
			count++;
		}
		count = 2;
		if(flag == 0)
		{
			printf("%d ",n1);
		}
		n1++;
		flag = 0;
	}
}

