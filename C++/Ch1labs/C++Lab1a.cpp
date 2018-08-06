/*
	Name: Will Kreiser
	Date: 6 Aug 18
	Project: Lab1A
*/

/*
CPP: Lab 1
- This is a very casual lab designed to introduce you to C++. Mess around with some of it's features we kind of
hinted at.
- Ensure to set this up as a C++ project in Visual Studio or compile using G++ if using another editor or Linux
Instructions:
- A number is considered to be relatively prime to another if the greatest common denominator of both is 1.
- Euler's Totient Function – phi(n) – tallies up all the numbers that are relatively prime to a number n
- I have provided a program that implements Euler’s Totient Function to find a count of all numbers {1, 2, 3, …, n} that are relatively prime to a number n.
- Two functions to solve this problem have been provided but need to be completed, as well as a main().
-- int phi(unsigned int n) – this function should iterate through the number set to tally all numbers relative prime to n.
-- int gcd(const int, const int b) – this function should return the greatest common denominator of two numbers.
- Try using some of the new C++ features we covered. Experiment with auto, decltype, const, and references.
*/

#include <iostream>
int gcd(const int a, const int b);
int phi(unsigned int n);

int main()
{
	auto n = 0;
	for (n = 1; n <= 10; n++)
	{
		printf("phi(%d) = %d\n", n, phi(n));
	}

	auto a = 35;
	auto b = 60;

	gcd(a, b);

	getchar(); getchar();
	return 0;
}

//Function: gcd()
//Arguments: const int a, const int b - two int arguments to determine the gcd of 
//Return value: the greatest common denominator of two numbers 
int gcd(const int a, const int b)
{
	int gcd;
	for (int i = 1; i <= a && i <= b; i++) 
	{
		if (a%i == 0 && b%i == 0) 
		{
			gcd = i;
			printf("GCD is %d.\n", gcd);
		}		
	}
	return 0;
}

//Function: phi()
//Arguments: unsigned int n - a number that we want to find all numbers relative prime to 
//Return: the count of all numbers relative prime to n 
int phi(unsigned int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n != 2) 
	{
		if (n < 2 || n % 2 == 0) 
		{
			return false;
		}
		for (int i = 3; (i*i) <= n; i += 2) 
		{
			if (n % i == 0) 
			{
				return false;
			}
		}
	}
	return true;
}
