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
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct _student_data
{
	int student_number;
	char initials[4];
	char music_artist[64];
	char dream_car[64];
	struct _student_data * next_node;
}node;

// This function will print out all of the data contained within the student data struct.
void spillList(node *n, int choice);

//This function will allow the user to select a specific student
void specific_student(node *n);

//This function will allow the last student to be removed from the program
void popList(node ** tail);

//This function will clear the input stream
void clear();

//This function will allow a new student to be added to the end of the list
void add_new_student(node *n, node *student_number);

//This will print the menu that will allow students to be added to the program
int printMenu();
/*
1.	Print out all members and all data
2.	Print out all members and their dream car
3.	Print out all members and their favorite music artist
4.	Print out only a specific student
5.	Add additional students to the end
6.	Remove single student from the end
7.	Remove a specific student
0.	Exit the program.
*/


