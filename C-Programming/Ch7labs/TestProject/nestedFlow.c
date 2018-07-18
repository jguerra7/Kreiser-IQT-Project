/*	Name: William Kreiser
	Date: 18 July 18
	Project: Nested Control Flow (Lab7.5a)
*/

#include <stdio.h>

int main()
{
	int number = 1;
	int myChoice = 0;

	printf("Please select 1 for even or 2 for odd: ");
	scanf("%d", &myChoice);

	while (number < 100)
	{	
		if((number % 2) == 0 && myChoice == 1)
		{	
			printf("%d\n", number);
		}
		else if ((number % 2) != 0 && myChoice == 2)
		{
			printf("%d\n", number);
		}
		number++;
	}
	while (1);
	return 0;
}