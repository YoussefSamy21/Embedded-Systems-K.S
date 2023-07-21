// C Program that Reverses an input array ,  EX: input: 1,2,3,4,5,6  , output: 6,5,4,3,2,1
#include <stdio.h>
# define MAX_SIZE	100

void Input_Array(int *ptr, int elements);

void Reverse_Array(int *ptr, int elements);

void Print_Array(int *ptr, int elements);

void main()
{
	int arr[MAX_SIZE];
	int size;
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	Input_Array(arr , size);
	
	Reverse_Array(arr , size);
	
	Print_Array(arr, size);
	
}


void Input_Array(int *ptr, int elements)
{
	int i;
	for(i = 0; i<elements ; i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&ptr[i]);	
	}
}
void Reverse_Array(int *ptr, int elements)
{
	int j = elements - 1;
	int i  = 0,temp;
	while(i <= j)
	{
		temp = ptr[j];
		ptr[j] = ptr[i];
		ptr[i] = temp;
		i++;
		j--;
	}
}

void Print_Array(int *ptr, int elements)
{
	int i = 0;
	printf("Reversed Array: ");
	while (i<elements)
	{
		printf("%d ",ptr[i]);
		i++;
	}
}

