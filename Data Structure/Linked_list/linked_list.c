// Linked List for Student Data Base
#include "linked_list.h"
struct S_Student * g_P_FirstStudent = NULL ;
void Add_student()
{
	struct S_Student * P_NewStudent;
	struct S_Student * P_LastStudent;
	char temp_text [40];
	//Create a new record
	P_NewStudent = (struct S_Student *) malloc(sizeof(struct S_Student));

	if(g_P_FirstStudent == NULL)				//List is empty
	{
		//Assign it to the global pointer
		g_P_FirstStudent = P_NewStudent;
	}
	else										//List contain records
	{
		//Navigate to the last record
		P_LastStudent = g_P_FirstStudent;
		while (P_LastStudent->P_nextStudent)
        {
			P_LastStudent = P_LastStudent->P_nextStudent;
		}
		P_LastStudent->P_nextStudent = P_NewStudent;
	}
		//Fill student new data
		printf("Enter the student ID:\n");
		P_NewStudent->Student.ID = atoi(temp_text);

		printf("Enter the student Name:\n");
		gets(temp_text);
		strcpy(P_NewStudent->Student.name , temp_text);

		printf("Enter the student height:\n");
		gets(temp_text);
		P_NewStudent->Student.height = atof(temp_text);

		//Setting the pointer of the new record to null
		P_NewStudent->P_nextStudent = NULL;
}

int Delete_student()
{

	//Get the required id
	char temp_text [40];
	unsigned int selected_id ;
	printf("Enter the student ID to be deleted:\n");
	gets(temp_text);
	selected_id = atoi(temp_text);

	struct S_Student * P_SelectedStudent = g_P_FirstStudent;
	struct S_Student * P_PrevStudent   = NULL;


	if( g_P_FirstStudent )		//if list have recrods (it is not empty)
	{
		// loop through all elements
		while(P_SelectedStudent)
		{
			// Compare the recorded ID with the selected ID
			if(P_SelectedStudent->Student.ID == selected_id)			
			{
				if(P_PrevStudent)										
				{
					P_PrevStudent->P_nextStudent = P_SelectedStudent->P_nextStudent;
				}
				else													
				{
					g_P_FirstStudent = P_SelectedStudent->P_nextStudent;
				}
				free(P_SelectedStudent);
				printf("Student Deleted Successfully.\n");
				return 1; // find it :)
			}
			else													
			{
				//Continue searching
				P_PrevStudent = P_SelectedStudent;
				P_SelectedStudent = P_SelectedStudent->P_nextStudent;
			}
		}
		printf("Cannot Find the entered ID.\n");
		return 0;
	}
    else
    {
        printf("List is empty.\n");
	    return 0;
    }

}

void NthNode()
{
	char temp_text [40];
	unsigned int node_number ;
	unsigned int node_counter = 0 ;
	printf("Enter reference number to be viewed:\n");
	gets(temp_text);
	node_number = atoi(temp_text);
	node_number --;

	struct S_Student * P_SelectedStudent = g_P_FirstStudent;


	if( g_P_FirstStudent )		//if list is not empty
	{
		// loop through all elements
		while(P_SelectedStudent)
			{
			// Compare each node with the entered id
			if(node_counter == node_number)			//there is a match
			{
				printf("Record number %d \n",node_counter+1);
				printf("ID: %d\n", P_SelectedStudent->Student.ID);
				printf("Name: %s\n", P_SelectedStudent->Student.name);
				printf("Height: %lf\n", P_SelectedStudent->Student.height);
				printf("=======================================\n");
				break;
			}
			else														//there is no match
			{
				//Continue searching through the list
				P_SelectedStudent = P_SelectedStudent->P_nextStudent;
				node_counter ++;
			}
		}
	}
	else{
	printf("List is empty.\n");
	}
}

void NthNodeFromEnd()
{
	char temp_text [40];
	unsigned int node_number ;
	unsigned int list_size ;
	unsigned int node_counter = 0 ;
	printf("Enter reference number from end to be viewed:\n");
	gets(temp_text);
	node_number = atoi(temp_text);
	node_number ++;

	list_size = Lenght();
	node_number = list_size - node_number;

	struct S_Student * P_SelectedStudent = g_P_FirstStudent;


	if( g_P_FirstStudent )		//if list is not empty
	{
		// loop through all elements
		while(P_SelectedStudent)
			{
			// Compare each node with the entered id
			if(node_counter == node_number)			//there is a match
			{
				printf("Record number %d \n",node_counter+1);
				printf("ID: %d\n", P_SelectedStudent->Student.ID);
				printf("Name: %s\n", P_SelectedStudent->Student.name);
				printf("Height: %lf\n", P_SelectedStudent->Student.height);
				printf("=======================================\n");
				break;
			}
			else														//there is no match
			{
				//Continue searching through the list
				P_SelectedStudent = P_SelectedStudent->P_nextStudent;
				node_counter ++;
			}
		}
	}
	else{
	printf("List is empty.\n");
	}


}

void MiddleList()
{
	unsigned int node_number ;
	unsigned int node_counter = 0 ;

	node_number = Lenght() / 2;

	struct S_Student * P_SelectedStudent = g_P_FirstStudent;


	if( g_P_FirstStudent )		//if list is not empty
	{
		// loop through all elements
		while(P_SelectedStudent)
			{
			// Compare each node with the entered id
			if(node_counter == node_number)			//there is a match
			{
				printf("Student in the middle of the database is:\n");
				printf("=======================================\n");
				printf("Record number %d \n",node_counter);
				printf("ID: %d\n", P_SelectedStudent->Student.ID);
				printf("Name: %s\n", P_SelectedStudent->Student.name);
				printf("Height: %lf\n", P_SelectedStudent->Student.height);
				printf("=======================================\n");
				break;
			}
			else														//there is no match
			{
				//Continue searching through the list
				P_SelectedStudent = P_SelectedStudent->P_nextStudent;
				node_counter ++;
			}
		}
	}
	else{
	printf("List is empty.\n");
	}
}


void LenghtList()
{
	unsigned int node_counter = 0 ;

	struct S_Student * P_SelectedStudent = g_P_FirstStudent;

	if( g_P_FirstStudent )		//if list is not empty
	{
		// loop through all elements
		while(P_SelectedStudent)
			{
				//Continue searching through the list
				P_SelectedStudent = P_SelectedStudent->P_nextStudent;
				node_counter ++;
			}
	}
	printf("Database has %d student in it \n" ,node_counter );

}
int Lenght()
{
	unsigned int node_counter = 0 ;

	struct S_Student * P_SelectedStudent = g_P_FirstStudent;

	if( g_P_FirstStudent )		//if list is not empty
	{
		// loop through all elements
		while(P_SelectedStudent)
			{
				//Continue searching through the list
				P_SelectedStudent = P_SelectedStudent->P_nextStudent;
				node_counter ++;
			}
	}
	return node_counter;

}
void View_All()
{
	struct S_Student * P_CurrentStudent = g_P_FirstStudent ;
	int count = 0 ;
	if (g_P_FirstStudent == NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		while( P_CurrentStudent )
		{
			printf("Record number %d \n",count+1);
			printf("ID: %d\n", P_CurrentStudent->Student.ID);
			printf("Name: %s\n", P_CurrentStudent->Student.name);
			printf("Height: %lf\n", P_CurrentStudent->Student.height);
			printf("=======================================\n");
			count ++;
			P_CurrentStudent = P_CurrentStudent->P_nextStudent;
		}
	}
}

void DeleteALL()
{
	struct S_Student * P_CurrentStudent = g_P_FirstStudent ;
	if (g_P_FirstStudent == NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		while( P_CurrentStudent )
		{
			struct S_Student * P_TempStudent = P_CurrentStudent ;
			P_CurrentStudent = P_CurrentStudent->P_nextStudent;
			free(P_TempStudent);
		}
		g_P_FirstStudent = NULL;
		printf("Deletion is completed.\n");
	}
}

void ReverseList()
{

	//Check list is not empty
	if(g_P_FirstStudent){

		struct S_Student* pPrevStudent = g_P_FirstStudent;
		struct S_Student* pCurrentStudent = g_P_FirstStudent;
		struct S_Student* pNextStudent = NULL;

		pCurrentStudent = pCurrentStudent->P_nextStudent;
		pPrevStudent->P_nextStudent = NULL;

		while(pCurrentStudent){
			pNextStudent = pCurrentStudent->P_nextStudent;
			pCurrentStudent->P_nextStudent = pPrevStudent;
			pPrevStudent = pCurrentStudent;
			pCurrentStudent = pNextStudent;
		}

		g_P_FirstStudent = pPrevStudent;
		printf("\nList is Reversed Successfully");
		return;
	}
	else{
		printf("\nList is empty");
		return;
	}
}