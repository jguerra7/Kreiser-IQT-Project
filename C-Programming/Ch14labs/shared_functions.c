#include "sharePoint.h"

int printMenu()	//This will print the menu that the user can do once in the program
{
	printf("Welcome to the Student Tracker. \n\n");
	printf("1 - List current students\n2 - List students with dream car \n3 - List student with favorite music artist \
		\n4 - Print a specific student\n5 - Add a student\n6 - Remove last student\n7 - Remove a specific student\n0 - Exit student tracker\n\n");
	printf("Please select from the options above: ");
	return 0;
}

void spillList(node *n, int choice)	// This function will print out all of the data contained within the student data struct.
{
	if (choice == 1)	//Prints entire list of students and their dream car/favorite music artist
	{
		printf("\n");
		while (n != NULL)
		{
			printf("%s likes to listen to %s, while driving in their %s. \n", n->initials, n->music_artist, n->dream_car);
			n = n->next_node;
		}
		printf("\n");
	}
	else if (choice == 2)	//Prints the entire list of students and their dream car
	{
		printf("\n");
		while (n != NULL)
		{
			printf("%s would love to own a %s one day. \n", n->initials, n->dream_car);
			n = n->next_node;
		}
		printf("\n");
	}
	else if (choice == 3)
	{
		printf("\n");
		while (n != NULL)
		{
			printf("%s cleans the house listening to %s. \n", n->initials, n->music_artist);
			n = n->next_node;
		}
		printf("\n");
	}	
}

void find_specific_student(node *n)	//This function will allow the user to select a specific student
{	
	int studentPrinted = 0;	
	printf("Enter the student ID of the student you wish to look up.\n");

	while (studentPrinted == 0)
	{
		int inputCheck = 0;
		char searchForStudent[5] = { 0 };
		int specificStudent = 0;	

		fgets(searchForStudent, sizeof(searchForStudent), stdin);
		specificStudent = atoi(searchForStudent);			
		node * tempHead = n;

		while (inputCheck == 0)
		{						
			if (!strchr(searchForStudent, '\n')) {
				printf("Bad Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else if (specificStudent < 0 || specificStudent > 50) {
				printf("You must enter a number 1-50");
			}
			else {
				inputCheck = 1;
			}						
		}
		if (specificStudent > 0)
		{
			while (tempHead != NULL)
			{
				if (tempHead->student_number == specificStudent)
				{
					printf("\nStudent %d\nStudent initials: %s\nDream Car: %s\nFavorite Music Artist: %s\n\n"
						, tempHead->student_number, tempHead->initials, tempHead->dream_car, tempHead->music_artist);
					studentPrinted = 1;
					tempHead = NULL;
				}
				else
				{
					tempHead = tempHead->next_node;
				}
			}
			if (studentPrinted == 0)
			{
				printf("No student with that ID was found.\n");
			}
			else
			{
				studentPrinted = 1;
			}
		}		
	}	
}

node * add_student(node * head)
{
	node * tempHead = head;
	int newStudent = 0;
	int inputCheck = 0;
	int makeNew = 0;
	//ask if the user would like to add a new student
	while (inputCheck == 0)
	{
		printf("Would you like to add a new student? Enter 1 for yes, 0 for No ");
		char inputStr[5] = { 0 };

		fgets(inputStr, sizeof(inputStr), stdin);
		makeNew = atoi(inputStr);

		if (!strchr(inputStr, '\n'))
		{
			printf("Invalid Input!\n");
			while (fgetc(stdin) != '\n');
		}
		else if (makeNew < 0 || makeNew > 1)
		{
			printf("You must enter a number 1-100\n");
		}
		else
		{
			inputCheck = 1;
		}
	}
	//if they dont want to add a new student go back to main menu
	if (makeNew == 0)
	{
		return head;
	}
	else
	{
		node * lastName = (node*)malloc(sizeof(node));
		inputCheck = 0;
		//get the user's name
		while (inputCheck == 0)
		{
			char lastName[MAX_BUFFER] = { 0 };
			printf("Enter the student's last name: ");
			fgets(lastName, MAX_BUFFER, stdin);			
			if (!strchr(lastName, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				inputCheck = 1;
			}
		}
		inputCheck = 0;
		//get the user's initials
		while (inputCheck == 0)
		{
			printf("Enter the student's initials: ");
			char initials[MAX_BUFFER] = { 0 };
			fgets(initials, MAX_BUFFER, stdin);
			if (!strchr(initials, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				inputCheck = 1;
			}
			strcpy(lastName->initials, initials);
		}
		inputCheck = 0;
		//get the user's favorite artist
		while (newStudent == 0)
		{
			printf("Enter the student's favorite artist: ");
			char artist[MAX_BUFFER] = { 0 };
			fgets(artist, MAX_BUFFER, stdin);
			if (!strchr(artist, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				inputCheck = 1;
			}
			strcpy(lastName->music_artist, artist);
		}
		inputCheck = 0;
		//get the user's dream car
		while (newStudent == 0)
		{
			printf("Enter the student's Dream Car: ");
			char dreamCar[MAX_BUFFER] = { 0 };
			fgets(dreamCar, MAX_BUFFER, stdin);
			if (!strchr(dreamCar, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				inputCheck = 1;
			}
			strcpy(lastName->dream_car, dreamCar);
		}
		lastName->student_number = tempHead->student_number + 1;		//make sure the student's ID is the next ID number 
		lastName->next_node = tempHead;					//make the next student = to the current head
		head = newStudent;										//make the new student the current head
		return head;
	}
}

node * remove_specific_student(node * head)
{
	while (1)
	{
		node * tempHead = head;
		int goodInput = 0;
		int studentToRemove = 0; //stores the number of the student ID the user wants to remove
		int studentRemoved = 0; //value for whether or not a student was removed - if 0 then there wasnt if !0 then he was
								//ask if the user would like to add a new student
		while (goodInput == 0)
		{
			printf("Enter the Student ID of the student you would like to print, if you do not know their ID enter 0 to look up by name or exit ");
			char inputStr[5] = { 0 };

			fgets(inputStr, sizeof(inputStr), stdin);
			studentToRemove = atoi(inputStr);

			if (!strchr(inputStr, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else if (studentToRemove < 0 || studentToRemove > 100)
			{
				printf("You must enter a number 1-100\n");
			}
			else
			{
				goodInput = 1;
			}
		}
		//if they dont want remove a specific student go back to main menu
		if (studentToRemove == 0)
		{
			return head;
		}
		//otherwise find the student they want to remove and remove him
		else
		{
			//if the student they want to remove is the current head then use the remove last student function
			if (head->student_number == studentToRemove)
			{
				head = remove_last_student(head);
				return head;
			}
			//otherwise find the student the want to remove and remove him
			else
			{
				while (tempHead != NULL)
				{
					//if we find the student we want to remove
					if (tempHead->student_number == studentToRemove)
					{
						node * removeThisStudent = tempHead;	//set a new struct variable to the next student which is the one we want to remove
						tempHead = head; //reset our linked list back to the beginning
						printf("Removing student %s", removeThisStudent->initials);
						//loop through the list again until the next student is equal to the student we want to remove
						while (tempHead->next_node != removeThisStudent)
						{
							tempHead = tempHead->next_node;
						}
						//set the current student's next student = the student we want to removes next student
						tempHead->next_node = removeThisStudent->next_node;
						//NULLIFY everything in the student we want to remove
						removeThisStudent->student_number = NULL;
						strcpy(removeThisStudent->initials, "\0");
						strcpy(removeThisStudent->music_artist, "\0");
						strcpy(removeThisStudent->dream_car, "\0");
						removeThisStudent->next_node = NULL;
						studentRemoved = 1;
						return head;
					}
					else
					{
						tempHead = tempHead->next_node;
					}

				}
				if (studentRemoved == 0)
				{
					printf("There was no student with this ID in the list\n");
				}
			}
		}
	}

}

//This function will allow the last student to be removed from the program
node * remove_last_student(node * head)
{
	node * tempHead = head;

	int inputCheck = 0;
	int inputValue = 0;
	char removeStudent[5] = { 0 };	
	//ask if the user would like to add a new student
	
	while (inputCheck == 0)
	{	
		printf("Would you like to remove the last student?(Enter 1 for yes, 0 for no) \n");
		fgets(removeStudent, sizeof(removeStudent), stdin);
		inputValue = atoi(removeStudent);

		if (!strchr(removeStudent, '\n'))
		{
			printf("Invalid Input!\n");
			while (fgetc(stdin) != '\n');
		}
		else if (inputValue < 0 || inputValue > 1)
		{
			printf("You must select 1 for yes, 0 for no.\n");
		}	
		else
		{
			inputCheck = 1;
		}
	}
	//if they dont want to remove the last student go back to main menu
	if (inputValue == 0)
	{
		return head;
	}
	//otherwise -> remove the head and set the next student to be the head
	else
	{
		//if the current head is null then there is nothing left to remove and print an error!
		if (head->student_number == NULL)
		{
			printf("These users are base users and cannot be deleted\n");
			return head;
		}
		else
		{
			head = head->next_node;	//set the head to the next element
									//nullify all the data in the current head
			tempHead->student_number = NULL;
			strcpy(tempHead->initials, "\0");
			strcpy(tempHead->music_artist, "\0");
			strcpy(tempHead->dream_car, "\0");
			tempHead->next_node = NULL;
			//free(tempHead);	//free the tempHead
			return head;	//return the head (because its pointing to the next student now

		}
	}		
}
		
