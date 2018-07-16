#include <stdio.h>

int main(void)
{
	for (int x = 100; x > 0; x--)
	{
		if (x % 3 == 0)
		{
			printf("Fizz");
		}
		else if (x % 5 == 0)
		{
			printf("Buzz");
		}
		else {
			printf("FizzBuzz");
		}
	}

	return 0;
}