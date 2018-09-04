/*
	Name: Will Kreiser
	Date: 6 Aug 18
	Project: Performance Lab ERRNO
*/

#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <errno.h>
#include <stdio.h>

void error_reporting(int currErrno);
/*
#ifndef NO_FILE
#define NO_FILE
int main(void)
{
	int currentErrno = 0;
	char currentChar = 0;

	// Open an existing file 
	FILE * noFile = fopen("C:\\Temp\\TR-Test-Input-File.txt", "r");

	// Store the errno
	currentErrno = errno;

	if (!noFile)
	{
		// Print an error message utilizing the string associated with the errno
		error_reporting(currentErrno);

		// Immediately utilize errno as the return value
		return currentErrno;
	}
	else
	{
		// Utilize feof() to read a file char by char until the end
		while (!feof(noFile))
		{
			currentChar = getc(noFile);	// Read a char and...
			putchar(currentChar);			// ...print a char
		}
	}
	return 0;
}
#endif
*/


#ifndef LOCKED_FILE
#define LOCKED_FILE
int main(void)
{
	int currentErrno = 0;
	char currentChar = 0;

	// Open an existing file 
	FILE * lockedFile = fopen("lockedFile.txt", "w");

	// Store the errno
	currentErrno = errno;

	if (!lockedFile)
	{
		// Print an error message utilizing the string associated with the errno
		error_reporting(currentErrno);

		// Immediately utilize errno as the return value
		return currentErrno;
	}
	else
	{
		// Utilize feof() to read a file char by char until the end
		while (!feof(lockedFile))
		{
			currentChar = getc(lockedFile);	// Read a char and...
			putchar(currentChar);			// ...print a char
		}
	}
	getchar(); getchar();
	return 0;
}
#endif



void error_reporting(int currErrno)
{
	if (currErrno){	
		perror("Error");	
	}
	getchar(); getchar();
	return;
}