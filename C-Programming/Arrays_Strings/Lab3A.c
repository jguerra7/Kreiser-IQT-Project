#include <stdio.h>
#include <string.h>

int main (void)
{
    int numberStudents[] = {0, 28, 32, 33, 25, 29, 22, 27, 27, 25, 26, 30, 22, 26,};
    
    for (int i = 0; i < 14; i++)
    {
        printf("Age of student %d: %d\n", i, numberStudents[i]);

    }

    char quoteArray[256] = "Some\nknowledge\nof\neverything\nleads\nto\nnever\ncompletely\nbeing\nknowledgeable.\n";
    
    for (int j = 0; j < 100; j++) 
    {
        printf("%c", quoteArray[j]);
    }
    
    return 0;
}