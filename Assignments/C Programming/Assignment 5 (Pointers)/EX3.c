
// C program to print a string in reverse using a pointer
#include <stdio.h>
#define MAX_SIZE	100

void Get_String(char *ptr);

int String_Length(char *ptr);

void Reverse_String(char *ptr);

void Print_String(char *ptr);


void main()
{
	char arr[MAX_SIZE];
	printf("Enter Your String: ");
	Get_String(arr);
	Reverse_String(arr);
	printf("Reversed String: ");
	Print_String(arr);
}

void Get_String(char *ptr)
{
	int i = 0;
	while(i<=(MAX_SIZE-1))
	{
		scanf("%c",&ptr[i]);
		if(ptr[i] == '\n')
		{
			ptr[i] = '\0';
			break;
		}
		i++;
	}
}

int String_Length(char *ptr)
{
	int i = 0;
	while(ptr[i] != '\0')
	{
		i++;
	}
	return i;
}

void Reverse_String(char *ptr)
{
	int temp;
	int i=0,j=String_Length(ptr)-1;
	while(i<j)
	{
		temp = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = temp;
		i++;
		j--;
	}
}

void Print_String(char *ptr)
{
	int i = 0;
	while(ptr[i] != '\0')
	{
		printf("%c",ptr[i]);
		i++;
	}
}