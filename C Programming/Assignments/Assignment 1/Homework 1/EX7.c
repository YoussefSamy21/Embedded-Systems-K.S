#include <stdio.h>
// C Program to Swap Two integers without temp variable
int main()
{
	int a,b,temp;
	printf("Enter value of a: ");
	scanf("%d",&a);
	printf("Enter value of b: ");
	scanf("%d",&b);
	a = a + b; //50
	b = a - b; //5
	a = a - b;
	printf("After Swapping, Value of a = %d\nAfter Swapping, Value of b = %d\n",a,b);
	
	/*
		Can use (* & /) instead of (+ & -)
		or (XOR operation)
	*/
	return 0;
}
