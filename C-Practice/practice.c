///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// MIDTERM 2018-2 ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The requirement for this lab is to define all of the MidtermFunctions.h functions as declared.
// The comment blocks for each function should clearly indicate what the requirements are for the function.
// There are a variety of appropriate solutions for many of these functions.
// MidtermTestCodev1.c has been written to test all of the functions both individually and as a whole.
// This header definition file includes the instructor solution for the header functions.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*	Name: William Kreiser
	Date: 20 July 18
	Project: C-Midterm
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//===================================================================
//							Function 1
//===================================================================

/*
* FUNCTION:   int is_it_alphabet(signed char inputChar);
*
* ARGUMENTS:  inputChar is a single signed character that represents a single character
*                 that is tested as an alphabet letter.
*
* RETURNS:	  1 if inputChar is an alphabet character
*             0 if inputChar is not an alphabet character
*
* NOTES:      This function should not care if inputChar is uppercase or lowercase
*             The return value represents a boolean response without using a 'bool' data type
*             The letters a through z and A through Z represent "alphabet letters" for
*                 the purposes of this assignment.
*/
int is_it_alphabet(signed char inputChar)
{	
	if (inputChar >= 65 && inputChar <= 90 || inputChar >= 97 && inputChar <= 122)	//Checks for ASCII value of letters
	{
		return 1;	//Return 1 if character is alphabet 
	}
	else
	{
		return 0;	//Return 0 if not alphabet char
	}
}

//===================================================================
//							Function 2
//===================================================================

/*
* FUNCTION:   int reverse_case(char * inputString, char * outputBuff, int inputPosition);
*
* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string
*             outputBuff is expected to be a pointer to a char array which will store the new string
*             inputPosition is the element of inputString
*
* RETURNS:	  Number of characters that were case reversed
*             -1 either inputString is NULL
*             -2 if inputPosition is unrealistic
*                 Examples:
*                     inputPosition is negative
*                     inputPosition is out of the array's scope
*
* NOTES:	This function's purpose is to take inputString, determine what are alphabetic characters, and reverse their case.
*			So capital letters become lowercase. Lowercase becomes uppercase.
*
*/

int reverse_case(char * inputString, char * outputBuff, int inputPosition)
{
	clear_a_buffer(outputBuff, 512);
	int reverse_count = 0;

	if (!inputString || !outputBuff)
	{
		return -1;
	}
	else if (inputPosition >= strlen(inputString) || inputPosition < 0)
	{
		return -2;
	}
	else
	{
		
		int j = 0;
		size_t length = strlen(inputString);
		for (int i = inputPosition; i < length; i++)
		{
			if (!is_it_alphabet(inputString[i]))
			{
				outputBuff[j] = inputString[i];
				j++;
			}
			else if (inputString[i] >= 65 && inputString[i] <= 90)
			{
				outputBuff[j] = inputString[i] + 32;
				reverse_count++;
				j++;
			}
			else if (inputString[i] >= 97 && inputString[i] <= 122)
			{
				outputBuff[j] = inputString[i] - 32;
				reverse_count++;
				j++;
			}
		}
	}
	return reverse_count;       
}

//===================================================================
//							Function 3
//===================================================================

/*
* FUNCTION:   int remove_char(char * sentenceString, char userInput);
*
* ARGUMENTS:  senteceString is expected to be a pointer to a null-terminated string
*			  userInput is expected to be a char to be removed from sentenceString
*
* RETURNS:	  Number of characters that were removed
*             -1 if sentenceString is NULL
-2 if the character can't be found
-3 if userInput is invalid:
NULL
Invalid Input
*
* NOTES:      The purpose of this function is to scan sentenceString for userInput (char)... and delete ALL instances of that char IN PLACE (meaning do not correct spacing)
Then return the number of characters that were removed.
*/

int remove_char(char * sentenceString, char userInput)
{
	int remove_count = 0;
	if (!sentenceString)
	{
		return -1;
	}
	else if (!userInput)
	{
		return -3;
	}
	else
	{
		size_t length = strlen(sentenceString);
		int i = 0;
		while (i < length)
		{
			if (sentenceString[i] == userInput)
			{
				memmove(&sentenceString[i], &sentenceString[i + 1], length);
				remove_count++;

			}
			else
			{
				i++;
			}
		}
		if (remove_count == 0)
		{
			remove_count = -2;
		}
	}
	return remove_count;
}

//===================================================================
//							Function 4
//===================================================================

/*
* FUNCTION:   int decode_string(char * inputString, unsigned char key);
*
* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string that needs decoded
*			  key is a single-byte that must be xor'd with (read below)
*
* RETURNS:	  Number of characters that were decoded
*             -1 if inputString is NULL
*			  -2 if key is invalid
*
* NOTES:      This function will take input from inputString and decode it using the unsigned char key.
*			  The string has been pseudo-encryped (poorly) with a single byte XOR, which you will be required to undo.
*			  Key is the byte that the buffer was XOR'd against
*
*
*/

int decode_string(char * inputString, unsigned char key, int dataSize)
{
	int decode_count = 0;
	if (!inputString)
	{
		return -1;
	}
	else if (!key)
	{
		return -2;
	}
	else if (!dataSize)
	{
		return -3;
	}
	else
	{
		
		for (int i = 0; i < dataSize; i++)
		{
			inputString[i] = inputString[i] ^ key;
			decode_count++;
		}
	}
	return decode_count;
}

//===================================================================
//							Function 5
//===================================================================

/*
* FUNCTION:   int clear_a_buffer(char * fullBuff, int buffSize);
*
* ARGUMENTS:  fullBuff is expected to be a pointer to a char array
*             buffSize represents the dimension of fullBuff[]
*
* RETURNS:	  0 on success
*             -1 if fullBuff is NULL
*             -2 if buffSize is unrealistic
*                 Examples:
*                     buffSize is zero
*                     buffSize is negative
*
* NOTES:      This function 'zeroizes' all of the elements of fullBuff[buffSize]
*             fullBuff does not necessarily need to be a null-terminated string since the array's
*                 dimension is passed in as an argument (for safety)
*/

int clear_a_buffer(char * fullBuff, int buffSize)
{
	if (!fullBuff)
	{
		return -1;
	}
	else if (!buffSize || buffSize < 0)
	{
		return -2;
	}
	else
	{	
		for (int i = 0; i < buffSize; i++)
		{
			fullBuff[i] = 0;
		}
		return 0;
	}	
}
