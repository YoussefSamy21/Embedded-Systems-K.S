#include <stdio.h>

// C program to print all the alphabets using a pointer.
void main()
{
	char alph[27];
    int i;
    char *ptr; 
    ptr = alph;     
    for(i=0;i<26;i++)
    {
        *ptr=i+'A';
        ptr++;
    }
    ptr = alph;

printf(" The Alphabets are : \n");
    for(i=0;i<26;i++)
    {
       printf(" %c ", *ptr);
        ptr++;
    }
}