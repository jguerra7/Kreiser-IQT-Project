/*  Name:William Kreiser
    Date: 13 July 18
    Project: Lab5A
*/
// #define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main(void) 
{
    /* insert initialize variables here */
    double legA, legB;
    double hypotenuse;

    /* insert input values and assign to variables here */
    printf("Enter the size of the first leg: ");
    scanf("%5lf", &legA);
    if (legA <= 0)
    {
        legA = 0;
        printf("Please enter a positive number. \n");
        scanf("%5lf", &legA);
    }

    printf("Enter the size of the second leg: ");
    scanf("%5lf", &legB);
    if (legB <= 0)
    {
        legB = 0;
        printf("Please enter a positive number: ");
        scanf("%5lf", &legB);
    }
    /* insert arithmetic hypotenuse calculation here */
    hypotenuse = sqrt((legA * legA) + (legB * legB));
    /* insert -Print the hypotenuse here */
    printf("The hypotenuse is: %lf\n", hypotenuse);

    
    return 0;
}