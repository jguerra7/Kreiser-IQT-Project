/*
	Name: William Kreiser
	Date: 30 July 18
	Project: Lab12B
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_ptr = fopen("mySong.txt", "r"); // Opens a read-only file

	char tempBuff[256] = { 0 };
	char * tempReturnValue = tempBuff;

	if (myFile_ptr != NULL) 	// Verify fopen() succeeded
	{
		while (tempReturnValue) // Continue reading until the end of file
		{
			tempReturnValue = fgets(tempBuff, 256, myFile_ptr);// Read one line
			if (tempReturnValue)
			{
				puts(tempBuff); // Print that character string
			}	
		}
		fclose(myFile_ptr); // Always fclose anything you fopen
	}
	else 			// Otherwise, fopen() failed
	{
		puts("Error opening file!"); 	// Tell the user and...
		getchar(); getchar();
		return -1;			// Return an error value
	}

	getchar(); getchar();

	return 0;
}