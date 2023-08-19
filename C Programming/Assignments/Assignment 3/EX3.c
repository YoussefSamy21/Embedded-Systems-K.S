#include <stdio.h>

// C program to Reverse a sentence using Recursion
void Reverse_Sentence();
void main()
{
	printf("Enter a Sentence: ");
	Reverse_Sentence();
}

void Reverse_Sentence()
{
	char c;
	scanf("%c",&c);
	if(c != '\n')
	{
		Reverse_Sentence();
		printf("%c",c);
	}
	
}