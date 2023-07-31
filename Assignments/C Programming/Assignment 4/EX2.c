#include <stdio.h>

// C Program to add Two Distances (in Inch-Feet) System using Structures

struct Distance
{
	int feet;
	float inch;
}d1,d2,sum;

void main()
{
	printf("Enter Information for 1st Distance:\n");
	
	printf("Enter Feet: ");
	scanf("%d",&d1.feet);
	
	printf("Enter Inch: ");
	scanf("%f",&d1.inch);
	
	
	printf("Enter Information for 2nd Distance:\n");
	
	printf("Enter Feet: ");
	scanf("%d",&d2.feet);
	
	printf("Enter Inch: ");
	scanf("%f",&d2.inch);
	
	sum.feet = d1.feet + d2.feet;
	sum.inch = d1.inch + d2.inch;
	/*	If inch is greater than 12 , changing it to Feet */
	if(sum.inch > 12.0)
	{
		sum.inch = sum.inch - 12;
		sum.feet++;
	}
	printf("Sum of Distances = %d\'-%.1f\"",sum.feet,sum.inch);
	
}