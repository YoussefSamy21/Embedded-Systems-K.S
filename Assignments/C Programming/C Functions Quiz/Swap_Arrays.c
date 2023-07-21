// C Program Swapping 2 Arrays with different Lengths (arr1_size & arr2_size)
#include <stdio.h>
# define MAX_SIZE	100

void Input_Array(int *ptr, int elements);

void Swap_Arrays(int *ptr_arr1, int *ptr_arr2 , int arr1_size , int arr2_size);

void Print_Array(int *ptr, int elements);

void main()
{
	int arr1[MAX_SIZE] , arr2[MAX_SIZE];
	int arr1_size , arr2_size;
	
	printf("Enter size of First array: ");
	scanf("%d",&arr1_size);
	Input_Array(arr1 , arr1_size);
	
	printf("Enter size of Second array: ");
	scanf("%d",&arr2_size);
	Input_Array(arr2 , arr2_size);
	
	Swap_Arrays(arr1,arr2,arr1_size,arr2_size);
	
	printf("/*******   After Swapping   *******/\n");
	printf("Array1: ");
	Print_Array(arr1 , arr2_size);
	printf("\nArray2: ");
	Print_Array(arr2 , arr1_size);
}

void Swap_Arrays(int *ptr_arr1, int *ptr_arr2 , int arr1_size , int arr2_size)
{
	int i=0,temp;
	while(i<arr1_size || i<arr2_size)
	{
		temp = ptr_arr1[i];
		ptr_arr1[i] = ptr_arr2[i];
		ptr_arr2[i] = temp;
		i++;
	}
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

void Print_Array(int *ptr, int elements)
{
	int i = 0;
	while (i<elements)
	{
		printf("%d ",ptr[i]);
		i++;
	}
}