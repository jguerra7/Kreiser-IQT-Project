#define _CRT_SECURE_NO_WARNINGS 1
#define BUFF_SIZE ((int)1024)

#include <stdio.h>

int count_this_letter(char * string_ptr, char countThis, int * howMany_ptr);

int main()
{
	char newString[BUFF_SIZE] = { 0 };
	char findMe = 0x0;
	int foundMeTimes = 0;
	int retVal = 0;

	printf("Enter a string: \n");
	_flushall();
	fgets(newString, BUFF_SIZE, stdin);
	printf("Enter a character to search for: \n");
	_flushall();
	findMe = getc(stdin);

	retVal = count_this_letter(newString, findMe, &foundMeTimes);
	if (!newString)
	{
		printf("User input was NULL.");
	}
	else if (!foundMeTimes)
	{
		printf("The search character was zero.");
	}
	else
	{
		printf("The search character %c was found %d times.\n", findMe, foundMeTimes);
		printf("That data was found at memory address %p\n", &foundMeTimes);
	}

	getchar();
	getchar();

	return 0;
}

int count_this_letter(char * string_ptr, char countThis, int * howMany_ptr)
{
	int returnValue = 0;
	if (!string_ptr)
	{
		returnValue = -1;
	}
	else if (!howMany_ptr)
	{
		returnValue = -2;
	}
	else if (!countThis)
	{
		returnValue = -3;
	}
	else
	{
		int i = 0;

		while (*(string_ptr + i))
		{
			if (*(string_ptr + i) == countThis)
			{
				*howMany_ptr = *howMany_ptr + 1;
			}
			i++;
		}
	}
	return returnValue;
}