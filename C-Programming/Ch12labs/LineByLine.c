/*	
	Name: William Kreiser
	Date: 30 July 18
	Project: Lab12D
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
		FILE * myNewFile_ptr = fopen("newSong.txt", "w"); //putting the fopen here creates it after it verifies myFile_ptr is not NULL
		while (tempReturnValue) // Continue reading until the end of file
		{
			tempReturnValue = fgets(tempBuff, 256, myFile_ptr);// Read one line from the old string
			if (tempReturnValue)
			{
				fputs(tempReturnValue, myNewFile_ptr); // Print that character string from old file into new file
			}
		}
		fclose(myFile_ptr); // Always fclose anything you fopen
		fclose(myNewFile_ptr); // Always fclose anything you fopen
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