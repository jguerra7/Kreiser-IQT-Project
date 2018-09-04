/*	Name: William Kreiser
	Date: 25 July 18
	Project: Little Integer
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int * find_smallest_natural_number(int * intArray_ptr, int arraySize);

#define BUFF_SIZE 30
int main()
{
	int integerArray[BUFF_SIZE] = { 15, 9, 5, 7, 11 };
	int * smallest_ptr = NULL;
	
	smallest_ptr = find_smallest_natural_number(integerArray, (int)BUFF_SIZE);

	if (smallest_ptr)
	{
		printf("The smallest number in the array is %d.\n", *smallest_ptr);
	}
	else
	{
		puts("Uh Oh!!!");
	}
	

	getchar();
	getchar();
	return 0;
}

int * find_smallest_natural_number(int * intArray_ptr, int arraySize)
{	
	int * returnValue_ptr = NULL;
	int * current_ptr = NULL;

	if (!intArray_ptr)
	{
		returnValue_ptr = NULL;
	}
	else if (arraySize < 1)  //Returns NULL if arraysize less than 1
	{
		returnValue_ptr = NULL;
	}
	else
	{
		current_ptr = intArray_ptr;  // Mirrors the start of the referenced int array using current_ptr

		for (int i = 0; i < arraySize; i++)
		{
			if ((*(intArray_ptr + i) < *(current_ptr)) && *(intArray_ptr +i) > 0)
			{	
				current_ptr = (intArray_ptr + i);
			}			
		}	
		returnValue_ptr = current_ptr;
	}
	return returnValue_ptr;
}