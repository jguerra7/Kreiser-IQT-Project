

// In this lab, you will declare and initialize variables of the following types:

// * int
// * float
// * double
// * char

// Then print the variables and their sizes.
#define NO_CRT_SECURE_WARNINGS 1
#include <stdio.h>

int main ()
{
    int num1 = 15;
    float num2 = 156.543;
    double num3 = 17584.22;
    char string1 = 0;

    printf("\nnum1 is %d, and its size is %d\n", num1, sizeof(num1));
    printf("num2 is %f, and its size is %d\n", num2, sizeof(num2));
    printf("num3 is %lf, and its size is %d\n", num3, sizeof(num3));
    printf("string1 is %d, and its size is %d\n\n", string1, sizeof(string1));

    return 0;

}