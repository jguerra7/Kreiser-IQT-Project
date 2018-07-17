#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MAX_BUFF_SIZE 256

int main(void)
{
	char someArray[MAX_BUFF_SIZE] = { 0 };

	printf("Please enter your favorite quote: ");
	scanf("%255[^\n]c", &someArray);

	if (someArray[0] >= 32 && someArray[0] < 126)
	{
		printf("%c", someArray);
	}

	return 0;
}
