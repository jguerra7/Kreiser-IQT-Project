/*	Name: William Kreiser
	Date: 17 July 18
	Project: While loops (Lab 7.3b)
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char someCharArray[100] = "Why are you sleeping?\n\0I thought it was nap time.\n\0It is lunch time.\n\0";
	//puts(someCharArray);	
	int i = 0;
	while (someCharArray[i] != '\0')
	{
		printf("%c", someCharArray[i]);
		i++;
	}
	
	getchar();
	getchar();
	return 0;
}