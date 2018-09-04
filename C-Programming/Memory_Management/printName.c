/*
Name: William Kreiser
Date: 31 July 18
Project: PerfLab 13A

*/

/*
Haystack Needle Lab
Purpose:
Remove the needle from the haystack
AKA: Move the substring from the string using memory operators and functions
*/
// TODO: Include any needed headers
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	//TODO: Create a string containing your first name
	char string[] = "Will";
	//TODO: Get the size of this string
	int length = strlen(string);
	//TODO: Declare a char pointer *str
	//TODO: Allocate a section of memory of type char
	//TODO: Set the size of this allocated space to 40 bytes
	//TODO: Assign the address of this allocated space to the pointer value
	char *str = malloc(sizeof(char) + 1);
	*str = 40;
	
	//TODO: Copy your name into the allocated space using strcpy()
	strcpy(str, string);
	//TODO: Print out your name that is stored in the allocated memory space
	printf("My name is %s.\n", str);
	//TODO: Reallocate the memory space using the size of the string rather than 40 bytes
	*str = realloc(str, (sizeof(string) + 1));
	//TODO: Print out the string again
	printf("My name is %s.", str);

	free(str);
	getchar(); getchar();
	return 0;
}










