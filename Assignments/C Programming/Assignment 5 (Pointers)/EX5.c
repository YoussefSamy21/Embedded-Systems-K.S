#include <stdio.h>
// C Program to show a pointer to an array which contents are pointer to structure.
struct employee
{
	char *empname;
	int empid;
};
void main()
{
	printf("\n\n Pointer : Show a pointer to an array which contents are pointer to structure :\n"); 
	static struct employee emp1= { "Jhon", 1001 } , emp2 = { "Alex" , 1002} , emp3 = { "Taylor" , 1003};
	
	struct employee(*arr[])={ &emp1 , &emp2 , &emp3};
	
	struct employee(*(*pt)[3])=&arr;

	printf(" Exmployee Name : %s \n",(**(*pt+1)).empname);
	printf(" Employee ID :  %d\n",(*(*pt+1))->empid);	
}