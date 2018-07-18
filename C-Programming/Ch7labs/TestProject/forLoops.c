/*	Name: William Kreiser
	Date: 17 July 18
	Project: For Loops (Lab7.3a)
*/
#include <stdio.h>

int main()
{
	int number_that_grows = 0;
	printf("Before the loop the number is %d.\n", number_that_grows);
	for (int i = 100; i > 0; i--)
	{
		number_that_grows++;
	}
	printf("After the loop the number is %d.\n", number_that_grows);

	getchar();
	getchar();
	return 0;
}