#include <stdio.h>
// C Function to count number of ones in binary number

int Binary_1_Counts(int num);

void main() 
{
	int x,res;
	printf("input:");
	scanf("%d",&x);
	res = Binary_1_Counts(x);
	printf("output:%d",res);
}

int Binary_1_Counts(int num)
{
	int ones=0;
	while(num>0)
    {
        if(num & 1) // OR  ===> if(num%2 != 0)
        {
            ones++;
        }
        num = num >>1; // Equivalent to num/=2
    }
	
	return ones;
}