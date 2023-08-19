
// C Program to Find Area of a Circle ,Passing Arguments to Macros
#include <stdio.h>

#define PI	3.1415
#define area(r)	(PI * r * r)

void main()
{
	int radius;
	printf("Enter the Radius: ");
	scanf("%d",&radius);
	printf("Area = %.2f",area(radius));
}