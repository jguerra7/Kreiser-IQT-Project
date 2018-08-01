#include "sharePoint.h"

int printMenu()
{
	printf("Welcome to the Student Tracker. \n\n");
	printf("1 - List current students\n2 - List students with dream car \n3 - List student with favorite music artist \
		\n4 - Print a specific student\n5 - Add a student\n6 - Remove last student\n7 - Remove a specific student\n0 - Exit student tracker\n\n");
	printf("Please select from the options above: ");


	return 0;
}

void spillList(node *n, int choice)
{
	if (choice == 1)
	{
		printf("\n");
		while (n != NULL)
		{
			printf("%s likes to listen to %s, while driving in their %s. \n", n->initials, n->music_artist, n->dream_car);
			n = n->next_node;
		}
		printf("\n");
	}
	else if (choice == 2)
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
	return 0;
}

void popList(node ** tail)
{
	node * next_node = NULL;

	next_node = (*tail)->next_node;
	free(*tail);
	*tail = next_node;
}

void specific_student(node *n)
{
	int specificStudent = 0;
	
	printf("There are 10 students in this class.\n");
	printf("Please select a number from 1-10: ");
	scanf(" %d", &specificStudent);
	while (n != NULL)
	{
		if (n->student_number == specificStudent)
		{
			printf("\nStudent %d\nStudent initials: %s\nDream Car: %s\nFavorite Music Artist: %s\n\n", n->student_number, n->initials, n->dream_car, n->music_artist);
			break;
		}
		else
		{
			n = n->next_node;
		}
	}	
	return 0;
}

void clear()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	return 0;
}

void add_new_student(node *n, node *student_number)
{	
	node * lastStudent = n;

	char lastStudentNumber = student_number;
	char lastName[32] = { 0 };
	char dreamCar[64] = { 0 };
	char musicArtist[63] = { 0 };
	char initials[4] = { 0 };
	int number_of_students = 0;
		
	printf("\nWhat is the students last name? ");	//New student's last name
	scanf("%31s", &lastName);
	clear();

	printf("\nWhat are the students initials? ");	//New student's initials
	scanf("%3s", &initials);
	clear();

	printf("\nWhat is the student's dream car? ");	//New student's dream car
	fgets(dreamCar, 63, stdin);

	printf("\nWhat is the student's favorite music artist?");	//New student's fav music artist;
	scanf("%s", &musicArtist);	
	clear();
	printf("\n");
	
	if (lastName && initials && dreamCar && musicArtist)
	{
		node * (lastName) = (node*)malloc(sizeof(node));
		strcpy(lastName->initials, toupper((int)initials));
		lastName->student_number = lastStudentNumber + 1;
		strcpy(lastName->dream_car, dreamCar);
		strcpy(lastName->music_artist, musicArtist);
		lastStudent->next_node = lastName;
		lastName->next_node = NULL;
	}
	
	return 0;
}
