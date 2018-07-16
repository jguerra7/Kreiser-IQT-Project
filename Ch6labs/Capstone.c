/*  Name: William Kreiser
    Date: 13 July 18
    Project: Capstone 
*/
// 1: Flip a single bit using XOR
// NOTE: This capstone requires a lot of logic and almost all the previously used bitwise operators.
#include <stdio.h>
#include <inttypes.h>

int binary(unsigned int num);

int main (void)
{   //Initialize an unsigned int with an arbitrary value
    unsigned int initialValue = 100, tempValue, newValue;
    unsigned int inputMask = 0, tempMask = 0, binMask;
    
    //Ask the user input on which bit position to flip (0 through ((sizeof(unsigned int)*8) -1))
    printf("Please select a number between 0-31: ");
    scanf("%2u", &inputMask);

    //Converting the initial Value to binary 
    tempValue = binary(initialValue);
    printf("Binary Equivalent of Decimal Integer %u\n", tempValue);
    //Create a dynamic bit mask based on the user input "inputMask"
    tempMask = 1U << inputMask;
    binMask = binary(tempMask);    
    printf("The tempMask is: %d\n", binMask);
    // XOR the original value with the inputMask and print the result
    newValue = initialValue ^ tempMask;
    printf("The XOR'd value is: %d\n", binary(newValue));

    return 0;
}

int binary(unsigned int num)
{
    int rem, a = 1;
    unsigned int bin_num = 0;

    while(num > 0)
    {
        rem = num%2;
        num = num / 2;
        bin_num = bin_num + (a * rem);
        a = a * 10;
    }

return bin_num;
}
