/*	Name: William Kreiser
	Date: 18 July 18
	Project: Lab 8B
*/
#define ERR_NULL_POINTER -1;        // string is null
#define ERR_INVALID_LENGTH -2; // string length is zero or less
#define _CRT_SECURE_NO_WARNINGS 1 

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "myStringHeader.h"
#define MAX_BUFFER_SIZE 256

int main()
{	
	char phrase[MAX_BUFFER_SIZE];
	
	printf("Please enter a phrase: ");
	scanf("%s", &phrase);

	char * reverse[] = { phrase };
	int phraseLength = 0;
	phraseLength = strlen(phrase);	

	//Function to reverse the phrase
	reverse_it(phrase, phraseLength);
	
	//Function to count the number of alphabetical characters
	print_the_count(phrase, phraseLength);
	
	while (1);

	return 0;
}

int print_the_count(char * inputString, int strLen)
{
	char tempChar = 0;      // Current char being acted on
	int table[26] = { 0 };    // Alpha
	int count = 0;

	if (!inputString)
	{
		return ERR_NULL_POINTER;
	}
	else if (!strLen)
	{
		return ERR_INVALID_LENGTH;
	}

	for (int i = 0; i < strLen; i++)
	{
		if (inputString[i] >= 65 && inputString[i] <= 122)
		{
			tempChar = inputString[i];
			tempChar = toupper(tempChar);
			table[tempChar - 65] += 1;
			count++;
		}
	}

	// Print the table
	for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		printf("%c: %d\n", i + 65, table[i]);
	}
	return count;
}

int reverse_it(char * forwardString, int strLen)
{
	char reverseString;

	if (!forwardString)
	{
		return ERR_NULL_POINTER;
	}
	else if (!strLen)
	{
		return ERR_INVALID_LENGTH;
	}
	else {
		for (int i = 0; i < (int)strLen / 2; i++)
		{
			reverseString = forwardString[i];
			forwardString[i] = forwardString[strLen - i - 1];
			forwardString[strLen - i - 1] = reverseString;
		}
		printf("\n String after Reversing = %s", reverseString);
	}
	
	return 0;

}
