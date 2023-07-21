// C program that Clears Specific Bit in a Given number
#include <stdio.h>
int Clear_Bit(int num , int bit);
void main()
{
	int num , bit , res;
	printf("Input number: ");
	scanf("%d",&num);
	printf("Bit Position: ");
	scanf("%d",&bit);
	res = Clear_Bit(num,bit);
	printf("Result = %d",res);
}
int Clear_Bit(int num , int bit)
{
	num = num & (~(1<<bit));
	return num;
}