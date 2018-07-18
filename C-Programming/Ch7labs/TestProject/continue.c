/*	Name: William Kreiser
	Date: 18 July 18
	Project: Continue (Lab7.4a)
*/

#include <stdio.h>

int main()
{
	unsigned int x = 0;      // User inputted number

	printf("Enter a number between 1-999: ");
	scanf("%4d", &x);

	// Prevents user from enter a number over 999... exits
	if (x > 999)
	{
		printf("Senpai!! You can't enter numbers larger than 999.\n");
		printf("Enter a number between 1-999: ");
		scanf("%4d", &x);
	}
	
	for (int i = 1; i < 20; i++)
	{	// Add 1 to y until 20 numbers reached
		if (x == 0)
		{
			continue;
		}
		if ((x % i) > 0)
		{	
			printf("%d\n", i);			
		}
	}
	getchar();
	getchar();

	return 0;
}