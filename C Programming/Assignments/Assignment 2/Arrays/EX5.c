#include <stdio.h>
//C program to search an element in array
void main()
{
	int a[30],ele,num,i;
	printf("Enter number of elements: ");
	scanf("%d",&num);
	printf("Enter the values: ");
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be searched: ");
	scanf("%d",&ele);
	i=0;
	while(i<num && ele!=a[i])
	{
		i++;
	}
	if(i<num)
	{
		printf("Number found at the location: %d",i+1);
	}
	else		
	{
		printf("Not found!");
	}
}