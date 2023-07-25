#include <stdio.h>
// C Function to take an integer number and Calculate its Square Root (Using Binary Search)
float Square_Root(int num);
void main()
{
	int num;
	float res;
	printf("input:");
	scanf("%d",&num);
	res = Square_Root(num);
	printf("output:%.3f",res);
}

float Square_Root(int num)
{ 
    int low = 0, mid , high = num,i; 
    float ans;
	
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == num)
        {
            ans = mid;
            break;
        }
        if (mid * mid < num)
        {
			ans=low;
            low = mid + 1;
        }
        else
        { 
            high = mid - 1;
        }
    }
    float increment_value = 0.1;
    for (i = 0; i < 3; i++)
    {
        while (ans * ans <= num)
        {
            ans += increment_value;
        }
        ans = ans - increment_value;
        increment_value /= 10;
    }
	
    return ans;
}