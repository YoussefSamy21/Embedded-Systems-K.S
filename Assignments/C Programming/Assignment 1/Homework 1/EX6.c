#include <stdio.h>
// C Program to Swap Two integers
int main()
{
	int a,b,temp;
	printf("Enter value of a: ");
	scanf("%d",&a);
	printf("Enter value of b: ");
	scanf("%d",&b);
	temp = a;
	a = b;
	b = temp;
	printf("After Swapping, Value of a = %d\nAfter Swapping, Value of b = %d\n",a,b);
	
	return 0;
}