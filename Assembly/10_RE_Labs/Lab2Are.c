//Reverse Engineering Lab2A
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibo(int a)
{   
    if (a == 0)
    {
        a = 0;
        return a;
    }
    else if (a == 1)
    {
        a = 1;
        return a;
    }
    else
    {
        return (fibo(a-1) + fibo(a-2));
    }
}
int main(void)
{
    //1 parameter
    srand(time(0)); //Create the time seed
    int arg_0 = 0;

    printf("Fibonacci...\nEnter a number:");
    scanf("%d", &arg_0);

    printf("The number at Fibonacci sequence %d is %d.\n", arg_0, fibo(arg_0));
    
    return 0;
}