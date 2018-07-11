/*  Name:William Kreiser
    Date: 11 July 18
    Project: Lab5A
*/
// #define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main(void) 
{
    /* insert initialize variables here */
    int legA, legB;
    double hypotenuse;

    /* insert input values and assign to variables here */
    printf("Enter the size of the first leg: ");
    scanf("%5d", &legA);

    printf("Enter the size of the second leg: ");
    scanf("%5d", &legB);

    if (legA <= 0)
    {
        legA = 0;
        printf("Please enter a non-negative size. \n");
        scanf("%5d", &legA);
    }
    if (legB <= 0)
    {
        legB = 0;
        printf("Please enter a non-negative size: ");
        scanf("%5d", &legB);
    }
    /* insert arithmetic hypotenuse calculation here */
    hypotenuse = sqrt((legA * legA) + (legB * legB));
    /* insert -Print the hypotenuse here */
    printf("The hypotenuse is: %lf\n", hypotenuse);

    
    return 0;
}