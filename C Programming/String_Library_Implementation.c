// Implementation of Common Functions related to Strings in C Programming
#include <stdio.h>
#define MAX_SIZE	100

void Get_String(char *ptr);

int String_Length(char *ptr);

void Reverse_String(char *ptr);

void Print_String(char *ptr);

void String_Copy(char *ptr1 , char *ptr2);

void String_Concatenate(char *ptr1 , char *ptr2);

void String_Lower_Case(char *ptr); // changes all string letters to the Lower case

void String_Upper_Case(char *ptr);	// changes all string letters to the Upper case

int String_to_Integer(char *ptr); // EX: "120KG" ==> 120  , "Cost is 30" ==> 30  ,  "1024" ==> 1024     

int String_Compare(char *ptr1 , char *ptr2);
/*
	String_Compare function compares two strings and produces one of three results:
	1- if the two string are identical it gives 0
	2- if the First string is lower in the alphabetic order it gives -1
	3- if the First string is higher in the alphabetic order it gives 1

	Remark:
	This function differentiate between Capital and Small Letters , 
	Where the ASCII code of the Capital letters is lower than the ASCII code of the Small letters , EX: MAGED is less than ahmed
	
	To Solve this Problem , we can convert both strings to the same case first (using String_Lower_Case or String_Upper_Case ), then Compare them.
*/


/********************************************************************************************/

/*	Testing the Functions */
void main()
{
	char arr[MAX_SIZE];
	printf("Enter Your String: ");
	Get_String(arr);

	// Reverse_String(arr);
	// printf("Reversed String: ");
	// Print_String(arr);

	// char arr2[MAX_SIZE];
	// String_Copy(arr2 , arr);
	// printf("\nCopied String: ");
	// Print_String(arr2);

	// String_Concatenate(arr2 , arr);
	// printf("\nConcatenated String: ");
	// Print_String(arr2);
	
	// String_Lower_Case(arr);
	// Print_String(arr);

	// printf("\n");

	// String_Upper_Case(arr);
	// Print_String(arr);

	// int res = String_Compare(arr , arr2);
	// printf("%d",res);

	// int res = String_to_Integer(arr);
	// printf("%d",res);
}

void Get_String(char *ptr)
{
	int i = 0;
	while(i < MAX_SIZE)
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
	int i = 0;
	int j = String_Length(ptr)-1;
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


void String_Copy(char *ptr1 , char *ptr2)
{
	int i = 0;
	while(ptr2[i] != '\0')
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	ptr1[i] = '\0';
}

void String_Concatenate(char *ptr1 , char *ptr2)
{
	int i = 0;
	int j = String_Length(ptr1); // j now has the index of '\0' in the destination array
	while(ptr2[i] != '\0')
	{
		ptr1[j] = ptr2[i];
		i++;
		j++;
	}
	ptr1[j] = '\0';
}

void String_Lower_Case(char *ptr)
{
	int i = 0;
	while(ptr[i] != '\0')
	{
		if((ptr[i]>= 'A') && (ptr[i]<= 'Z'))
		{
			ptr[i] = (ptr[i] - 'A') + 'a';
		}	
		i++;
	}
}

void String_Upper_Case(char *ptr)
{
	int i = 0;
	while(ptr[i] != '\0')
	{
		if((ptr[i]>= 'a') && (ptr[i]<= 'z'))
		{
			ptr[i] = (ptr[i] - 'a') + 'A';
		}	
		i++;
	}
}

int String_to_Integer(char *ptr)
{
	int num = 0 , i = 0;
	while(ptr[i] != '\0')
	{
		if(ptr[i]>= '0' && ptr[i]<= '9')
		{
			num = (num*10)+(ptr[i]- '0');
		}
		i++;
	}
	return num;
}

int String_Compare(char *ptr1 , char *ptr2)
{
	int res = 0 , i = 0;
	while( (ptr1[i] != '\0') && (ptr2[i] != '\0') )
	{
		if(ptr1[i] < ptr2[i])
		{
			res = -1;
			break;
		}
		else if(ptr1[i] > ptr2[i])
		{
			res = 1;
			break;
		}
		i++;
	}
	return res;
}