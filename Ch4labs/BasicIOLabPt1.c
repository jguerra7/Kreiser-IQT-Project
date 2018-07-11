#include <stdio.h>
#include <string.h>

int main(void)
{
    char inputChar;
    printf("Please enter a character: \n");
    inputChar = getchar();
    putchar(inputChar +1);
    printf("\n");
    
    return 0;
}