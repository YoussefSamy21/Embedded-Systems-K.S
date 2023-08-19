// C program to Return the Last Occurrence of a number in given array , if number doesn't exist return -1
#include <stdio.h>
# define MAX_SIZE	100

void Input_Array(int *ptr, int elements);
int Find_Last_Occurrence(int *ptr_arr , int size , int num);
void main()
{
	int arr[MAX_SIZE];
	int size,num,index;
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	Input_Array(arr , size);
	
	printf("Enter your search number: ");
	scanf("%d",&num);
	
	index = Find_Last_Occurrence(arr , size , num);
	
	if(index != -1)
	{
		printf("index = %d",index);
	}
	else
	{
		printf("%d doesn't exist",num);
	}
	
}


int Find_Last_Occurrence(int *ptr_arr , int size , int num)
{
	int i = size-1;
	//int k = -1;
	while(i>=0)
	{
		if(ptr_arr[i] == num )
		{
			break;
		}
		i--;
	}
	
	return i;
}

void Input_Array(int *ptr_arr, int elements)
{
	int i;
	for(i = 0; i<elements ; i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&ptr_arr[i]);	
	}
}