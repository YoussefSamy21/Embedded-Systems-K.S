#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//C program to find frequency of chracters in string
void main()
{
	char c[1000],ch;
	int i,count=0;
	printf("Enter a String: ");
	gets(c);
	printf("Enter a character to find frequency: ");
	scanf("%c",&ch);
	for(i=0;c[i]!='\0';i++)
	{
		if(ch == c[i])
		{
			count++;
		}
	}
	printf("Frequency of %c = %d",ch,count); 
	
	
}