// C program takes string from the user and check if it the same USERNAME or not
#include <stdio.h>
int Compare(char *ptr_x, char *ptr_str);
void main()
{
	char str[100] = "Youssef Samy";
	char x[100];
	printf("Enter your User name: ");
	gets(x);
	if(Compare(x,str))
	{
		printf("Correct User");
	}
	else
	{
		printf("Wrong User");
	}
}

int Compare(char *ptr_x, char *ptr_str)
{
	int i = 0;
	while(ptr_x[i] != '\0' || ptr_str[i] != '\0')
	{
		if(ptr_x[i] != ptr_str[i])
		{
			return 0;
		}
		i++;
	}
	return 1;
}