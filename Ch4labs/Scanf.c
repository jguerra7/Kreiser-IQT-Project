/*  Name: William Kreiser
    Date: 11 July 18
    Lab4A: Basic I/O Pt1
*/

/*Part 1
Formatted Input (strings)
Read a first, middle and last name as input into separate char arrays
Specify a field-width to protect against buffer overflow
Ensure the field-width leaves room for a nul-terminator
Specify a ("\t") as a delimitating character
Print the full name, separating each string with a tab and newline ("\t\n")

Part 2
Formatted Input (numbers)
Read two integers from one line
Format the input so that the integers are separated by an asterisk (*) x*y (e.g., 2*3, 11*14)
Reprint the two integers and result as if the answer were being read by a human

////////////// EXAMPLE #1 ///////////////
OUTPUT:  Enter two integers, separated by a *, to be multiplied…
INPUT:   2*3
OUTPUT:  The result of 2 multiplied by 3 is 6.  
////////////// EXAMPLE #2 ///////////////
OUTPUT:  Enter two integers, separated by a *, to be multiplied…
INPUT:   11*14
OUTPUT:  The result of 11 multiplied by 14 is 154.
*/

#include <stdio.h>
#include <string.h>

//Maximum size of array
#define MAX_BUFFER_SIZE 32

//functions to reduce size of main
char fullName();
int twoNumbers();

int main (void)
{
    fullName();
    twoNumbers();
   
    return 0;
}

char fullName()
{
    char firstName[MAX_BUFFER_SIZE] = {0};
    char middleName[MAX_BUFFER_SIZE] = {0};
    char lastName[MAX_BUFFER_SIZE] = {0};
    
    printf("Please enter your first name: ");
    scanf("%31s", &firstName);
    printf("Please enter your middle name: ");
    scanf("%31s", &middleName);
    printf("Please enter your last name: ");
    scanf("%31s", &lastName);

    printf("%s\t\n%s\t\n%s\t\n", firstName, middleName, lastName);

    return 0;
}

int twoNumbers()
{
    int num1, num2;
    printf("\nPlease enter two numbers separated by an asterisk(*): ");
    scanf("%d*%d", &num1, &num2);
    printf("The result of %d multiplied by %d is: %d\n", num1, num2, (num1 * num2));

    return 0;

}