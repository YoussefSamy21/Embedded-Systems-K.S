#include <stdio.h>

// C Program to check whether a character is an alphabet or not
int main()
{
	char x;
	printf("Enter a Character: ");
	scanf("%c",&x);
	if( (x>= 'a' && x<= 'z') || (x>= 'A' && x<= 'Z') )
	{
		printf("%c is an alphabet",x);
	}
	else
	{
		printf("%c is not an alphabet",x);
	}
	
	return 0;
}