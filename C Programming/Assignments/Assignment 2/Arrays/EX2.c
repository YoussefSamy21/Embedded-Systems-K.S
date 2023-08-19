#include <stdio.h>
// C program to calculate average using arrays
void main()
{
	int size,i;
	float arr[100],sum=0.0,average;
	printf("Enter the number of data should be from 1 to 100: ");
	scanf("%d",&size);
	while(size > 100 || size<=0)
	{
		printf("Error!");
	}
	for(i=0;i<size;i++)
	{
		printf("%d. Enter number: ",i+1);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
	average = sum/size;
	printf("Average = %.2f",average);
}