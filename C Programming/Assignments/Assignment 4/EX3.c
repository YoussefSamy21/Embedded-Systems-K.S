#include <stdio.h>

// C Program to Add Two Complex Numbers by passing Strucute to a Function 

typedef struct complex
{
	float real;
	float imag;
}complex;

complex add(complex n1 , complex n2);

void main()
{
	complex n1 , n2 , res;
	printf("For First Complex Number:\n");
	printf("Enter Real and Imaginary Respectively: ");
	scanf("%f %f",&n1.real,&n1.imag);
	
	
	printf("For Second Complex Number:\n");
	printf("Enter Real and Imaginary Respectively: ");
	scanf("%f %f",&n2.real,&n2.imag);
	
	res = add(n1,n2);
	
	printf("Sum  = %.2f + j%.2f",res.real,res.imag);
}

complex add(complex n1 , complex n2)
{
	complex temp;
	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	
	return temp;
}