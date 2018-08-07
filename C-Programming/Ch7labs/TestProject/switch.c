/*	Name: William Kreiser
	Date: 17 July 18
	Project: Switches (Lab7.2d)
*/

#include <stdio.h>
#include <math.h>

int menu();

int main()
{
	int num1 = 0;
	int num2 = 0;
	int mathOp = 1;
	double pow1 = 0;
	double pow2 = 0;
	
	printf("Enter two number to perform a math operation on: ");
	scanf("%d %d", &num1, &num2);

	int sum = 0;
	int diff = 0;
	int prod = 0;
	int quot = 0;
	int mod = 0;
	double total = 0;

	do
	{
		menu();
		scanf("%d", &mathOp);
		switch (mathOp)
		{
		case 0:
			printf("Goodbye.\n");
			break;
		case 1:  //Addition
			sum = num1 + num2;
			printf("%d plus %d is %d.\n", num1, num2, sum);
			break;
		case 2:  //Subtraction
			diff = num1 - num2;
			printf("%d minus %d is %d.\n", num1, num2, diff);
			break;
		case 3:  //Multiplication
			prod = num1 * num2;
			printf("%d times %d is %d.\n", num1, num2, prod);
			break;
		case 4:  //Division
			quot = num1 / num2;
			if (num2 == 0)
			{
				printf("You cannot divide by 0.\n");
				printf("Choose a different operation.\n");
				menu();
				break;
			}
			else
			{
				printf("%d divided by %d is %d.\n", num1, num2, quot);
			}
			break;
		case 5:  //Modulus Division
			mod = num1 % num2;
			printf("The remainder of %d divided by %d is %d.\n", num1, num2, mod);
			break;
		case 6:  //Power
			pow1 = num1;
			pow2 = num2;
			total = pow(pow1, pow2);
			printf("%lf raised to %lf power is %.02lf.\n", pow1, pow2, total);
			break;
		default:
			break;
		}
	} while (mathOp != 0);
	
	return 0;
}

int menu()
{
	printf("What would you like to do with those numbers?\n");
	printf("1 - Add \n2 - Subtract \n3 - Multiply \n4 - Divide \n5 - Modulo Division \n6 - Power \n0 - Exit \n\n\n");

	return 0;
}