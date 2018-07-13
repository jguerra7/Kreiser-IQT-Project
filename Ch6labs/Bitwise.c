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
#include <inttypes.h>
#include <string.h>

int binary_conversion(uint32_t num);
int bitWiseLeft(uint32_t shiftLeft);

int main()
{
   uint32_t userInput;
   uint32_t bitChecker = 0x01;
   
   printf("Enter a number: ");
   fscanf(stdin, "%d", &userInput);

   binary_conversion(userInput);

   fprintf(stdout, "%d\n", binary_conversion(bitChecker)));
   bitChecker |= 1 << ((sizeof(bitChecker)*8)-1);

    
    
    return 0; 
}
 
int binary_conversion(uint32_t num)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2) 
       (num & i)? printf("1"): printf("0");
    
}

int bitWiseLeft(uint32_t shiftLeft)
{
    shiftLeft |= 1 << ((sizeof(shiftLeft)*8)-1);   
}   