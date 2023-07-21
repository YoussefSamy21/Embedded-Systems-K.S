#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//C program to find length of string
void main()
{
	char s[1000],i;
	printf("Enter a string: ");
	scanf("%s",s);
	for(i=0;s[i]!= '\0';i++);
	
	printf("Length of String: %d",i);
}