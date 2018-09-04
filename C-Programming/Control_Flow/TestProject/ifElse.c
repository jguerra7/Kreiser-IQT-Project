/*	Name: William Kreiser
	Date: 17 July 18
	Project: Performance Lab 7.2b
*/


#include <stdio.h>
int binary(int num);

int main(void)
{
	int someNum = 0;
	printf("Pick a number, any number: \n");
	scanf("%d", &someNum);

	if (someNum < 0)
	{
		printf("Your number is negative.\n");
	}
	else 
	{
		printf("Your number is: %d\n", someNum);
		printf("The binary is: ");
		binary(someNum);
		
		someNum = ~someNum + 1;
		printf("\nYour new number is: %d", someNum);
		printf("\nThe binary is: ");
		binary(someNum);

	}
	getchar();
	getchar();

	return 0;
}

int binary(int num)
{
	unsigned i;
	int length = sizeof(num);
	for (i = 1 << length; i > 0; i = i / 2)
		(num & i) ? printf("1") : printf("0");
	printf("\n");
}