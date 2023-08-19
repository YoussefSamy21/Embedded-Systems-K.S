#include <stdio.h>

// C Program to store information (name,roll and marks) of a student using Structure
struct Students
{
	char name[50];
	int roll;
	float marks;
};
void main()
{
	struct Students stud_1;
	printf("Enter Information of student: \n");
	
	printf("Enter name: ");
	scanf("%s",&stud_1.name);
	
	printf("Enter roll number: ");
	scanf("%d",&stud_1.roll);
	
	printf("Enter marks: ");
	scanf("%f",&stud_1.marks);
	
	printf("###	Displaying Information ###\n");
	printf("Name: %s\n",stud_1.name);
	printf("Roll: %d\n",stud_1.roll);
	printf("Marks: %.2f\n",stud_1.marks);
	
	
}