/*  Name: William Kreiser
    Date: 11 July 18
    Project: Lab6A Bitwise Shift Right
*/

/* Lab 6A: Bitwise Shift Right

Input a uint32_t userInput from stdin utilizing fscanf()
Initialize another uint32_t bitChecker to 0x01
Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
Print the binary representation of userInput to stdout using only the following:
fprintf()
Bitwise Shift Right >>
Bitwise AND &
Relational Operator (e.g., >)

*/
#define _CRT_NO_SECURE_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    __uint32_t userInput = 0;
    __uint32_t bitChecker = 0x01;
    printf("Please enter a number: ");
    fscanf(stdin, &userInput);

    int length = strlen(userInput);

    if (userInput)
    {
        userInput << length;
    }
    return 0;
}