/*	Name: William Kreiser
	Date: 18 July 18
	Project: 
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include "myStringHeader.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	char someInput;

	printf("Enter something cool and I will save it bro: ");
	scanf("%c", &someInput);

	int inputLength = 0;
	inputLength = strlen(someInput);
	
	//reverse the string
	reverse_it(someInput, inputLength);
	//count the letters in the string
	print_the_count(someInput, inputLength);

	return 0;
}