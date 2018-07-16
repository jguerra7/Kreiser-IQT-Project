/*  Name: William Kreiser
    Date: 16 July 18
    Project: Capstone 
*/
// 1: Flip a single bit using XOR
// NOTE: This capstone requires a lot of logic and almost all the previously used bitwise operators.
#include <stdio.h>
#include <inttypes.h>

int binary(uint32_t num);

int main (void)
{   //Initialize an unsigned int with an arbitrary value
    uint32_t initialValue = 13689; 
    uint32_t tempValue = 0;
    uint32_t newValue = 0;

    uint32_t inputMask = 0;
    uint32_t tempMask = 0;
    uint32_t binMask = 0;
    uint32_t bitMask = 0x01;
    
    //Ask the user input on which bit position to flip (0 through   ((sizeof(unsigned int)*8) -1))
    printf("Please select a number between 0-31: ");
    scanf("%u", &inputMask);

    //Converting the initial Value to binary
    printf("%u in binary is: ", initialValue);
    binary(initialValue);
    //Create a dynamic bit mask based on the user input "inputMask"
    tempMask |= bitMask << inputMask;    
    printf("The tempMask is: ");
    binary(tempMask);
    // XOR the original value with the inputMask and print the result
    newValue = initialValue ^ tempMask;
    printf("The XOR'd value is: %zu\n", newValue);
    printf("The XOR'd value in binary is: \n");
    binary(newValue);

    return 0;
}

int binary (uint32_t num)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2) 
       (num & i) ? printf("1") : printf("0");
    printf("\n");
}