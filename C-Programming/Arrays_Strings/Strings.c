// Name: William Kreiser
// Date: 11 July 18
// Lab 3B: Strings

// Declare and zeroize a char array with a dimension of 256
// Assign your chosen pharse to the leading elements of that array
// Explicitly verify your string is nul-terminated
// Print your string
// QUIZ: What is your string length?

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256
int main ()
{
    char stringArray[256] = {0};
    stringArray[0] = 71;
    stringArray[1] = 111;
    stringArray[2] = 111;
    stringArray[3] = 100;
    stringArray[4] = 98;
    stringArray[5] = 121;
    stringArray[6] = 101;
    stringArray[256] = '\0';

    int length = strlen(stringArray);

    for (int i = 0; i < length; i++)
    {
        printf("%c", stringArray[i]);
    }
    printf("\n%d\n", length);

    return 0;
}