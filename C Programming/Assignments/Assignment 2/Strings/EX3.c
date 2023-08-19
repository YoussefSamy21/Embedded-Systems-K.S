#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//C program to reverse string without using Library function
void main()
{
	char str[100],temp;
	int i=0,j=0;
	printf("Enter the string: ");
	gets(str);
	j = strlen(str)-1;
	while(i<j)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}
	
	printf("\n Revered string : %s",str);
	
	
	
}