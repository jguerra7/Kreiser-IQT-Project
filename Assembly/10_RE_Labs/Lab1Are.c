// Lab1a.c
#include <stdio.h>

int main()
{
    //1st function
    //allocate space on the stack
    //00351215 sub esp, 8
    //call some function    (Kernel get tick count)

    //second function uses srand
    //mem loc 76864880 uses printf
    //possible exception handler
    printf("Hello World");
    
    //mem loc 768257b0 looking for mainargs
    
    int var1 = 0;
    int var2 = 2;

    printf("The sum %d and %d is %d.\n", var1, var2, (var1+var2));
    return 0;
}