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
typedef __uint32_t uint32_t;

int binary_conversion(int num);
int bitWiseLeft(int shiftLeft);

int main()
{
   int num, bin;
   uint32_t bitChecker = 0x01;
   
   printf("Enter a decimal number: ");
   fscanf(stdin, "%i", &num);
   bin = binary_conversion(num);
   printf("\nThe binary equivalent of %d is %i\n", num, bin);

   binary_conversion(bitChecker);
   bitWiseLeft((int)bitChecker);
   fprintf(stdout, "%i\n", bitChecker);

}
 
int binary_conversion(int num)
{
    unsigned i;
    unsigned newBin;
    for (i = 1 << 31; i > 0; i = i / 2) 
       newBin += (num & i)? printf("1"): printf("0");
    printf("%32i", newBin);
}

int bitWiseLeft(int shiftLeft)
{   int movement;
    movement |= 1 << ((sizeof(shiftLeft)*8)-1);
    return movement;
}   