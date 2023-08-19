#include <stdio.h>
// C program to print the elements of an array in reverse order.
// Input the number of elements to store in the array (max 15) : 5
void main()
{
	int n, i, arr[15];
	int *ptr;
	printf(" Input the number of elements in the array (max 15) : ");
	scanf("%d",&n);
	ptr = arr;
	printf(" Input %d number of elements in the array : \n",n);
	for(i=0;i<n;i++)
	{
		printf(" element - %d : ",i+1);
		scanf("%d",&ptr[i]);
	} 	
	
	ptr = &arr[n - 1];

	printf("\n The elements of array in reverse order are :");

	for (i = n; i > 0; i--) 
	{
      printf("\n element - %d : %d  ", i, *ptr);
	  ptr--;
	}
}