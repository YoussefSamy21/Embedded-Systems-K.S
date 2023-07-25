//C Program to return unique number in array of integers with one loop
#include <stdio.h>
#define MAX_SIZE	100

void Input_Array(int *ptr, int elements);

int unique_array_num(int *ptr_arr,int size);

void main()
{
	int arr[MAX_SIZE];
	int size,res;
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	Input_Array(arr , size);
	
	res = unique_array_num(arr,size);
	
	printf("Unique Number: %d",res);
}

int unique_array_num(int *ptr_arr,int size)
{
	int i,unique=0;
	for(i=0;i<size;i++)
	{
		unique^=ptr_arr[i];
	}
	
	return unique;	
}

void Input_Array(int *ptr, int elements)
{
	int i;
	printf("Enter numbers of array\n");
	for(i = 0; i<elements ; i++)
	{
		scanf("%d",&ptr[i]);	
	}
}
