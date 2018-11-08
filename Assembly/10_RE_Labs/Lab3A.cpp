
#include <stdio.h>
#include <string.h>


int main(void)
{
    char string[] = "This is a test string.";
    char returnStr[26];
    int length = strlen(string);
    printf("String before: %s\n", string);
    for (int i = 0; i < length; i++)
    {
        if (string[i])
        {
            if (string[i] > 64 && string[i] <= 76)
            {
                returnStr[i] = string[i] + 13;
            }
            else
            {
                returnStr[i] = string[i] - 13;
            }
        }
        else if (string[i] >= 97 && string[i] <= 108)
        {
            returnStr[i] = string[i] + 13;
        }
        else if (string[i] >= 109 && string[i] <= 122)
        {
            returnStr[i] = string[i] - 13;
        }        
    }
    printf("String after: %s\n", string);    
    return 0;
}