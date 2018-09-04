#include <stdio.h>
#include <string.h>

int main (void)
{
    int myIntArray[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 0};
    float myFloatArray[5] = {1, 2, 3, 4, 5};
    char myCharArray[256] = { 0 };

    printf("\nThe 3rd element is: %d\n", myIntArray[2]);
    printf("%f\n", myFloatArray[2]);
    printf("%s\n", myCharArray[2]);
    
    int x, y;
    for (int i = 0; i < sizeof(myIntArray); i++)
    {
        y = i;
        x = (y + 1) * 10;
        myIntArray[i] = x;
    }   
    
    for(int j = 0; j < sizeof(myFloatArray); j++)
    {   
        y = myFloatArray[j];
        x = y * 1.1;
        myFloatArray[j] = x;
    }

    myCharArray[0] = 75;
    myCharArray[1] = 114;
    myCharArray[2] = 101;
    myCharArray[3] = 105;
    myCharArray[4] = 115;
    myCharArray[5] = 101;
    myCharArray[6] = 114;
    myCharArray[256] = 0;

    printf("%i\n", myIntArray[2]);
    printf("The 3rd element is: %f\n", myFloatArray[2]);
    printf("%c\n\n", myCharArray[2]);

    return 0;
}