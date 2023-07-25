//C Program to reverse words in string
/*
	My algorithm is taking every word and reverse its characters in the input array , then reversing the whole array
	EX: Youssef Mohamed Samy
		fessuoY demahoM ymaS
		Samy Mohamed Youssef
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE	100

void Reverse_Words(char *ptr_arr);

void Reverse_chars(char *ptr_word_start , char* end_address);

void main()
{
	char str[MAX_SIZE];
	printf("input:");
	fgets(str,MAX_SIZE,stdin);
	Reverse_Words(str);
	
	printf("output:%s",str);
	
}


void Reverse_Words(char *ptr_arr)
{
	int i = 0,end;
	end = strlen(ptr_arr)-1;
	char *ptr_word_start = ptr_arr;
	while(i <= end)
	{
		if(ptr_arr[i] == ' ' || ptr_arr[i] == '\n')
		{
			Reverse_chars(ptr_word_start , ptr_arr+i-1);
			ptr_word_start = ptr_arr+i+1;
		}
		i++;
	}
	
	/*	After reversing each word in the string , then Reversing the Whole Array*/
	
	Reverse_chars(ptr_arr , ptr_arr+end-1);
}

void Reverse_chars(char *ptr_word_start , char* end_address)
{
	int i=0,j,temp;
	j = end_address - ptr_word_start;
	while(i<j)
	{
		temp = ptr_word_start[i];
		ptr_word_start[i] = ptr_word_start[j];
		ptr_word_start[j] = temp;
		i++;
		j--;
	}
}