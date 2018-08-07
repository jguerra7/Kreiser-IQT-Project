/*	Name: William Kreiser
	Date: 30 July 18
	Project: Lab12E

*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE * myFile_ptr = fopen("classRoster.txt", "a"); // Opens a file to append to

	char firstName[20] = { 0 };
	char middleName[20] = { 0 };
	char lastName[20] = { 0 };
	char userName[256] = { 0 };
	int numberOfStudents = 0;

	while (numberOfStudents <= 0)
	{
		puts("How many students in your class? ");
		_flushall();
		scanf("%255d", &numberOfStudents);
		
	}
	for (int i = 0; i < numberOfStudents; i++)
	{
		printf("\nPlease enter first name: ");	
		scanf("%20s", &firstName);

		printf("\nPlease enter middle name: ");
		scanf("%20s", &middleName);

		printf("\nPlease enter last name:");
		scanf("%20s", &lastName);

		//checks to make sure to remove new lines
		for (int j = 0; j <= strlen(firstName); j++)
		{
			if (firstName[j] != '\n')
			{
				firstName[j] = firstName[j];
			}
			else
			{
				firstName[j] = '\0';
			}
		}
		for (int k = 0; k <= strlen(middleName); k++)
		{
			if (middleName[k] == '\n')
			{
				middleName[k] = '\0';
			}
			else
			{
				middleName[k] = middleName[k];
			}
		}
		for (int l = 0; l <= strlen(lastName); l++)
		{
			if (lastName[l] == '\n')
			{
				lastName[l] = '\0';
			}
			else
			{
				lastName[l] = lastName[l];
			}
		}
		//creates the username using the first leter of first name and middle name with the last name
		int userNameLength = (strlen(lastName) + 2);
		int counter = 0;
		for (int h = 0; h <= userNameLength; h++)
		{
			if (h == 0)
			{
				userName[0] = firstName[0];
			}
			else if (h == 1)
			{
				userName[h] = middleName[0];
			}
			else if (h>1 && h <= (userNameLength - 1))
			{
				counter = h - 2;
				userName[h] = lastName[counter];
			}
			else
			{
				userName[h] = '\0';
			}
		}
		//print to screen to check output then append it to the file
		printf("%s %s %s has a user name of %s", firstName, middleName, lastName, userName);
		fputs("\n", myFile_ptr);
		fputs(firstName, myFile_ptr);
		fputs(" ", myFile_ptr);
		fputs(middleName, myFile_ptr);
		fputs(" ", myFile_ptr);
		fputs(lastName, myFile_ptr);
		fputs("has a username of", myFile_ptr);
		fputs(userName, myFile_ptr);
		fputs("\n", myFile_ptr);
	}


	fclose(myFile_ptr);
	getchar(); getchar();
	return 0;
}