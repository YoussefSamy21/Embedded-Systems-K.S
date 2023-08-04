#include <stdio.h>

//a program in C to demonstrate how to handle the pointers in the program.
void main()
{
	int *ab;
	int m;
	m = 29;
	printf("How to handle the pointers in the program\n");
	printf("Here in the Declration , ab is a pointer to integer , int m = 29\n\n");
	
	printf("address of m = %p\n",&m);
	printf("Value of m = %d\n\n",m);
	
	ab = &m;
	printf("Now ab is assigned with the address of m\n");
	printf("address of ab = %p\n\n",ab);
	printf("Value of m = %d\n\n",*ab);
	
	m = 34;
	printf("Now m is assigned with value 34 \n");
	printf("address of pointer ab = %p\n\n",ab);
	printf("content of pointer ab  = %d\n\n",*ab);
	
	
	*ab = 7;
	printf("the pointer ab is assigned to value 7 now\n");
	printf("address of m = %p\n",&m);
	printf("Value of m = %d\n",m);
	
	
	
	
}
	