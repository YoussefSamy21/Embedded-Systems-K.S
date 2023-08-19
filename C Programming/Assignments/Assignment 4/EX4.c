#include <stdio.h>

// C Program to store information (name,roll and marks) of Students using Structure

struct Students
{
	char name[50];
	int roll;
	float marks;
};
void main()
{
	struct Students s[10];
	int i;
	
	printf("Enter Information of students: \n");
	for(i=0;i<10;i++)
	{
		printf("###### For Student %d  #####\n\n",i+1);
		printf("Enter name: ");
		scanf("%s",&s[i].name);
		
		printf("Enter roll number: ");
		scanf("%d",&s[i].roll);
		
		printf("Enter marks: ");
		scanf("%f",&s[i].marks);
	}
	
	
	
	printf("#########  Displaying Information of Students  #########\n");
	for(i=0;i<10;i++)
	{
		printf("###### For Student %d  #####\n\n",i+1);
		printf("Name: %s\n",s[i].name);
		printf("Roll: %d\n",s[i].roll);
		printf("Marks: %.2f\n",s[i].marks);
	}	
	
}