/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// MQT (I.5.A) PERFORMANCE LAB 1 ////////////////////////////////////////////
///////////////////////////////////////////////// MEMORY OPERATORS //////////////////////////////////////////////////
////////////////////////////////////////////// "Reference Not Found" ////////////////////////////////////////////////
/////////////////////////////////////////////// Instructor Solution /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declare userInput, tempValue, and input_ptr as the same data type (and input_ptr should be a pointer variable)
// Read user input into variable userInput
// Ensure tempValue contains the same value as userInput utilizing one or more memory operators
//     tempValue = userInput;  // NOT PERMITTED... use a memory operator
// Print the value *and* the pointer for each of the three variables in a human-readable format
// Locate those addresses in the "memory window"
// Summon your instructor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define HUMAN_READABLE_CHAR(printChar) \
				printf(#printChar " has a value of %c(%d) at pointer %p.\n", printChar, (int)printChar, &printChar)
#define HUMAN_READABLE_POINTER(printPointer) \
				printf(#printPointer " has a value of %p which is stored at pointer %p.\n", printPointer, &printPointer)
#define HUMAN_READABLE_POINTER_INTEGER (printPointer) \
				printf(#printPointer " has a value of %d which is stored at pointer %p.\n", *printPointer, &printPointer)

int main(void)
{
	/* Declare userInput, tempValue, and input_ptr as the same data type (and input_ptr should be a pointer variable) */
	char userInput, tempValue;
	char *input_ptr;

	/* Read user input into variable userInput */
	printf("Please enter a number: \n");
	scanf("%c", &userInput);

	/* Ensure tempValue contains the same value as userInput utilizing one or more memory operators */
	input_ptr = &userInput;
	tempValue = *input_ptr;
	
	/* Print the value *and* the pointer for each of the three variables in a human-readable format */
	HUMAN_READABLE_CHAR(userInput);
	HUMAN_READABLE_CHAR(tempValue);
	HUMAN_READABLE_POINTER(input_ptr);
	HUMAN_READABLE_POINTER_INTEGER(input_ptr);

	getchar();
	getchar();

	return 0;
}