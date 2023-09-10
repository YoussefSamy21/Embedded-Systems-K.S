#include "linked_list.h"

// struct S_Student * g_P_FirstStudent = NULL;

void main(void)
{	int choice = 1 ;
	while(choice)
	{
		printf("===================Welcome to the program====================\n");
		printf("Choose the number corresponding to the required option:\n");
		printf("=============================================================\n");
		printf("1- Add Student\n");
		printf("2- Delete Student\n");
		printf("3- view All\n");
		printf("4- Delete All\n");
		printf("5- view student with reference number\n");
		printf("6- view student with reference number from the end\n");
		printf("7- view database size\n");
		printf("8- view student with reference number at the middle of database\n");
		printf("9- reverse the list\n");
		printf("0- Exit program\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0:
			break;
		case 1:
			Add_student();
			break;
		case 2:
			Delete_student();
			break;
		case 3:
			View_All();
			break;
		case 4:
			DeleteALL();
			break;
		case 5:
			NthNode();
			break;
		case 6:
			NthNodeFromEnd();
			break;
		case 7:
			LenghtList();
			break;
		case 8:
			MiddleList();
			break;
		case 9:
			ReverseList();
			break;
		default:
			printf("Incorrect entry please try again\n");
			break;
		}
		printf("=============================================================\n");
	}
}