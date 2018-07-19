// MyStringHeader.c
#include <stdio.h>
#include <ctype.h>

#define ERR_NULL_POINTER -1;        // string is null
#define ERR_INVALID_LENGTH -2; // string length is zero or less
#define MAX_BUFFER_SIZE 256

extern int print_the_count(char * inputString, int strLen)
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
	int i = 0;
	printf("\n String after Reversing : ");
	for (i = strLen - 1; i >= 0; i--)
	{
		printf("%c", forwardString[i]);
	}
	return 0;

}