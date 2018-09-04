/*	Name: William Kreiser
	Date: 17 July 18
	Project: Do While loop (Lab7.3c)
*/

#include <stdio.h>

int main()
{
	int intArray[26] = { 0 };
	char someChar = 0;
	int i = 0;

	printf("Please enter a character: ");
	someChar = getchar();

	if (someChar < 32 || someChar > 122)
	{
		printf("Please enter a valid character: ");
		someChar = getchar();
	}
	do
	{	
		for (i = 0; i < 26; i++)
		{

		}
	} while (i < 26);

	return 0;
}