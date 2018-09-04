#include <Windows.h>
#include <stdio.h>
#include "TestCode.h"

/*
	Name: William Kreiser
	Date: 30 Aug 2018
	Project: C Final
*/

/////////////////////////////////////////////////////////////
// Test 1: For this task, you will receive two pointers to NULL terminated strings: 
//		   a 'sentence', and a 'word'. The objective will be to delete (in place) the first 
//		   occurrence of 'word' in the sentence. 
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
//		- the provided 'word' is not part of 'sentence': should return ERROR_NOT_FOUND (1168)
/////////////////////////////////////////////////////////////

int deleteWord(char* sentence, char* word)
{
	int sentenceLength = 0;	//holds the length of sentence pointer
	int wordLength = 0;	//Holds the length of word pointer
	int i = 0, j = 0;	//iterators for use in finding the word
	int found = 0;
	char * retVal;
	if (!sentence || !word)
	{
		return ERROR_INVALID_PARAMETER;	//Bad parameter return
	}
	else
	{
		sentenceLength = strlen(sentence);	//stored length of sentence into sentenceLength
		wordLength = strlen(word);			//stored length of word in to wordLength
		if (wordLength > sentenceLength)
		{
			//If wordLength is longer than sentenceLength, word will not be found
			return ERROR_NOT_FOUND;
		}
		else
		{
			for (i = 0; i <= (sentenceLength - wordLength); i++)	//for loop to iterate through sentence
			{
				if (*(sentence + i) == *(word))	//Checking if first sentence char equals first word char
				{
					if (wordLength == 1)	//If they are equal and wordLength is found, delete the word and return success
					{
						sentence[i] = sentence[i + 1];	//This deletes the word in place
						return ERROR_SUCCESS;
					}
					else     //wordLength is greater than 1
					{
						for (j = 0; j <= wordLength; j++)	//Second for loop to continue past single character
						{

							if (*(sentence + i + j) != *(word + j)) //checks the second letter
							{
								break; //We cannot find the word My lord.
							}
							else
							{
								memcpy(&sentence[i], &sentence[wordLength], sentenceLength);	//To remove the word from its place 
								found = 1;	//variable to return success
							}
						}
						if (found == 1)
						{
							return ERROR_SUCCESS;	//Word found and remove
						}						
					}
				}
				else
				{
					return ERROR_NOT_FOUND; //Word not found 
				}
			}
		}
	}
}
/////////////////////////////////////////////////////////////
// Test 3 (part one): This task will involve allocating a buffer
//				of (sizeOfData) bytes, and reading up to that amount
//				into it from the file specified in 'filename'. Additionally,
//				the data in the file has been pseudo-encryped (poorly) with a single-
//				byte XOR, which you will be required to undo (the byte that the buffer
//				was XOR'd against will be provided in 'key'). Finally, assuming the task
//				was successful, (and all pointers are valid) the pointer to the resulting 
//				buffer should be stored in the area referenced by buffPtr.
//
// Expected Return Values:
//			- task was completed successfully: ERROR_SUCCESS (0)
//			- bad input was provided: ERROR_INVALID_PARAMETER (87)
//			- you were unable to allocate enough memory: ERROR_OUTOFMEMORY (14)
//			- you were unable to open the file: ERROR_OPEN_FAILED (110)
/////////////////////////////////////////////////////////////
int decodeFromFile(char* filename, unsigned int sizeOfData, unsigned char key, void** buffPtr)
{	
	if (!filename || !sizeOfData || !key || !buffPtr)	//checking for valid parameters
	{
		return ERROR_INVALID_PARAMETER;		//Bad Parameters have been passed
	}
	else
	{
		FILE* myfile = fopen(filename, "r");	//Opening the filestream
		if (!myfile)
		{
			return ERROR_OPEN_FAILED;	//File didn't open
		}
	
		char* fileBuffer = (char*)malloc(sizeOfData);	//allocate a buffer equal to sizeOfData
		if (!fileBuffer)
		{
			fclose(myfile);	//Close the file because fileBuffer didn't malloc
			return ERROR_OUTOFMEMORY; //Buffer didn't malloc and we have no memory
		}
		char tempChar;	//temp variable to hold single character from getc()
		for (int i = 0; i < sizeOfData; i++)
		{
			tempChar = fgetc(myfile);	//gets one character from myfile
			fileBuffer[i] = tempChar ^ key;	//storing the XOR'd value in filebuffer
		}
		fclose(myfile);	//Closing the filestream

		*buffPtr = fileBuffer;	//passes the fileBuffer into buffPtr
	return ERROR_SUCCESS;	//SUCCESS!!!
	}
}

/////////////////////////////////////////////////////////////
// Test 3 (part two): The second part of the task; this simply requires you
//				  to appropriately free the buffer allocated in the last task
//				  (if possible).
//
// Expected Return Values:
//			- the task completed successfully: TRUE
//			- the task failed/bad input: FALSE
/////////////////////////////////////////////////////////////
BOOL freeDecodedBuffer(void* buffer)
{
	BOOL out = FALSE;	//variable to hold TRUE/FALSE statement
	char* tempBuff = buffer;	//declaring a char* equal to buffer for iteration
	int buffSize = 0;			//variable for hold the size of buffer

	if (buffer == NULL)
	{
		return out;	//return FALSE if buffer is NULL
	}
	else
	{
		buffSize = strlen(tempBuff);	//capturing the size of buffer

		for (int i = 0; i <= buffSize; i++)
		{
			tempBuff[i] = 0;	//sets every char in buffer to 0
			
		}
		out = TRUE;	//change out variable to true
		return out;	//return our bool variable
	}
}
