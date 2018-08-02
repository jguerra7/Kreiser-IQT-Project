/*
	Name: William Kreiser
	Date: 1 August 18
	Project: Linked List

*/

/*
1. Create a linked list, the struct members should contain the following:
	- Each students initals
	- Each students favoriate musical artist
	- Each students dream car
	- Required data for linked list completion
	-May be worth each student just posting their data into a slack channel so everyone can grab off of it

2. Create a menu allowing for the following:

	- Print out of all students and all of their data
	- Print out of all students and only one of their data members on request of user (ex. print out all students and their fav car)
	- Print out of only a specific student (This one can be challanging)

3. Bonus Objectives
	- Add additonal students to the end
	- Remove students at the end
	- Remove a specific student (This one is challanging)

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include "sharePoint.h"

int main()
{
	node * yoder = (node*)malloc(sizeof(node));  //head
	node * graham = (node*)malloc(sizeof(node));
	node * kreiser = (node*)malloc(sizeof(node));
	node * burright = (node*)malloc(sizeof(node));
	node * perez = (node*)malloc(sizeof(node));
	node * macary = (node*)malloc(sizeof(node));
	node * smith = (node*)malloc(sizeof(node));
	node * vering = (node*)malloc(sizeof(node));
	node * yost = (node*)malloc(sizeof(node));
	node * mane = (node*)malloc(sizeof(node));  //tail

	strcpy(yoder->initials, "KBY");
	yoder->student_number = 1;
	strcpy(yoder->dream_car, "Ford Raptor");
	strcpy(yoder->music_artist, "Guns and Roses");
	yoder->next_node = graham;

	//node2
	strcpy(graham->initials, "RMG");
	graham->student_number = 2;
	strcpy(graham->dream_car, "Honda Prelude");
	strcpy(graham->music_artist, "Rihanna");
	graham->next_node = kreiser;

	//Node 3
	strcpy(kreiser->initials, "WRK");
	kreiser->student_number = 3;
	strcpy(kreiser->dream_car, "Toyota Supra");
	strcpy(kreiser->music_artist, "Linkin Park");
	kreiser->next_node = burright;

	//Node 4
	strcpy(burright->initials, "THB");
	burright->student_number = 4;
	strcpy(burright->dream_car, "Hyaabusa");
	strcpy(burright->music_artist, "Killswitch Engage");
	burright->next_node = perez;

	//Node 5
	strcpy(perez->initials, "ETP");
	perez->student_number = 5;
	strcpy(perez->dream_car, "Mazda RX-7");
	strcpy(perez->music_artist, "Barney");
	perez->next_node = macary;

	//Node 6
	strcpy(macary->initials, "DAM");
	macary->student_number = 6;
	strcpy(macary->dream_car, "Subaru WRX");
	strcpy(macary->music_artist, "Anything Techno");
	macary->next_node = smith;

	//Node 7
	strcpy(smith->initials, "RES");
	smith->student_number = 7;
	strcpy(smith->dream_car, "RAM 1500");
	strcpy(smith->music_artist, "ACDC");
	smith->next_node = vering;

	//Node 8
	strcpy(vering->initials, "ZHV");
	vering->student_number = 8;
	strcpy(vering->dream_car, "Honda Civic Type-R");
	strcpy(vering->music_artist, "Metallica");
	vering->next_node = yost;

	//Node 9
	strcpy(yost->initials, "TOY");
	yost->student_number = 9;
	strcpy(yost->dream_car, "Chevy Silverado");
	strcpy(yost->music_artist, "Anything Blues");
	yost->next_node = mane;

	//tail
	strcpy(mane->initials, "RIM");
	mane->student_number = 10;
	strcpy(mane->dream_car, "Jeep Rubicon");
	strcpy(mane->music_artist, "Britney Spears");
	mane->next_node = NULL;

	int menuSelection = 1;  //Initialized with arbitrary value that will be changed
	int key = 0;
	do
	{
		printMenu();
		scanf("%d", &menuSelection);
		switch (menuSelection)
		{
			case 1:	//Print out all members and all data
			{
				spillList(yoder, menuSelection);
				break;
			}			
			case 2:	//Print out all member and their dream car
			{
				spillList(yoder, menuSelection);
				break;
			}
			
			case 3:	//Print out all members and their favorite music artist
			{
				spillList(yoder, menuSelection);
				break;
			}			
			case 4:	//Print out a specific student
			{
				find_specific_student(yoder);
				break;
			}
			case 5:	//Add additional students to the end
			{
				add_student(yoder);
				break;
			}
			case 6:	//Remove single student from the end
			{
				remove_last_student(yoder);
				break;
			}	
			case 7:	//Remove a specific student
			{
				remove_specific_student(yoder);
				break;
			}
			case 0:	//Exit the program
				printf("Exiting now...\n");
				break;
			default:	//default behavior
				break;
		}
	} while (menuSelection != 0);
	
	return 0;
}



