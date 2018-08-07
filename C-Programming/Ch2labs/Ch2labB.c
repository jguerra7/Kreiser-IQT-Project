// # Lab 2B: Type Conversion

// ### Did someone say 2B???![](/assets/bug.png)

// Declare and initialize variables of data types:

// * int
// * float
// * double
// * char

// Type cast and print the following:

// * int -&gt; float
// * int -&gt; char
// * float -&gt; double
// * double -&gt; float
// * char -&gt; int
// * 33 -&gt; char

// **Note: Initialize int to a value between 32 and 126**

#include <stdio.h>

int main ()
{
    int someNum1 = 64;
    float someNum2 = 1.1;
    double someNum3 = 2.2;
    char someNum4 = 4;
    
    printf("\nint to float cast is: %f\n", (float)someNum1);
    printf("int to char cast is: %c\n", (char)someNum1);
    printf("float to double cast is: %lf\n", (double)someNum2);
    printf("double to float cast is: %f\n", (float)someNum3);
    printf("char to int cast is: %d\n", (int)someNum4);
    printf("33 to char cast is: %c\n\n", (char)33);

    return 0;
}