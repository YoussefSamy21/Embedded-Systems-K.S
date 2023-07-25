#include <stdio.h>
//C Program to count the max number of Binary ones between two zeros

/* EX: Input = 110(Decimal) =  0110 1110  , Output = 3 (max ones between each 2 zeros is 3 binary 1's)	*/  

int Max_Binary_Ones_bet_Zeros(int num);

void main()
{
	int num,res;
	printf("input:");
	scanf("%d",&num);
	res = Max_Binary_Ones_bet_Zeros(num);
	printf("output:%d",res);
}

int Max_Binary_Ones_bet_Zeros(int num)
{
	int count=0,max_count = 0,i;
	while(num > 0)
	{
		if((num & 1) == 0)
		{
			for(i=1; (num>>i)&1 ; i++)
			{
				count++;
			}
			//printf("Count = %d\n",count);
		}
		if(count > max_count)
		{
			max_count = count;
		}
		num = num>>(count+1);// to reduce outer loop iteration (better than num = num>>1) to get directly the next zero , 0110 1110 ==> 0000 0110
		count = 0;
	}
	
	return max_count;
}