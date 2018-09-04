/*  Name: William Kreiser
    Date: 11 July 18
    Lab4C: String I/O
*/

#include <stdio.h>
#include <string.h>

int main (void)
{
    char inputArray[10] = {0};
    printf("Please enter a quote: ");
    fgets(inputArray, 10, stdin); printf("\n");

    fputs(inputArray, stdout); printf("\n");

    return 0;
}