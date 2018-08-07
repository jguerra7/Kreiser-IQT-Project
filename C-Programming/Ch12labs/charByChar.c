/*	
	Name: William Kreiser
	Date: 30 July 18
	Project: Lab12C
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_ptr = fopen("mySong.txt", "r"); // Opens a read-only file
	char readFromFile = 0; // Store char-by-char input from myFile_ptr
	if (myFile_ptr != NULL) 	// Verify fopen() succeeded
	{	
		FILE * myNewFile_ptr = fopen("xByX.txt", "w"); // Opens a writable file
		while (readFromFile != EOF) // Continue reading until the end of file
		{
			readFromFile = getc(myFile_ptr); 	// Read one character from original file
			putc(readFromFile, myNewFile_ptr); 		// Print that character into the new file
		}
		fclose(myNewFile_ptr);
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