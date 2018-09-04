/*	Name: William Kreiser
	Date: 17 July 18
	Project: Performance Lab 7.2c
*/

#include <stdio.h>

int main()
{
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	unsigned int num3 = 0;

	printf("Enter two numbers: ");
	scanf("%u %u", &num1, &num2);

	if (num1 == num2)
	{
		printf("You entered the same number twice.\n");
	}
	else if (num1 != num2)
	{
		if (num1 > num2)
		{
			num3 = num1;
		}
		else
		{
			num3 = num2;
		}
	}
	if ((num1 + num2) > 2)
	{
		printf("\nNum1 is: %u, Num2 is %u, and Num3 is %u.\n", num1, num2, num3);
	}
	
	while (1);

	return 0;
}