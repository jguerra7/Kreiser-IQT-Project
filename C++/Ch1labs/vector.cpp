/*
	Name: Will Kreiser
	Date: 7 Aug 18
	Project: Vector Practice
*/

/*
	Using what you know from C / C++ so far, create a quick program that accomplishes the following :
	Create a UI to accomplish all functionality
	
	Create functions to add and subtract all numbers within the vector... from lowest index to highest
	Ensure value type is signed(for negative numbers)
	Allow a user to delete the last element
	Allow a user to clear the entire vector
	BONUS
	
	
	
	etc
*/
#include <iostream>
#include <vector>

int subtract(std::vector<int>& input, int count, int difference);
int add(std::vector<int>& input, int count, int sum);
int new_numbers(std::vector<int>& input, int count, int temp);
int printMenu();

int main()
{
	std::vector<int> userInput;
	auto count = 0;
	auto difference = 0;
	auto sum = 0;
	auto temp = 0;
	char answer;
	int choice = 99;
	//Allow a user to input a series of numbers, which are stored into a vector
	std::cout << "Vector Calculator" << std::endl;
	std::cout << "-----------------" << std::endl;

	std::cout << "How many numbers would you like to enter? ";
	std::cin >> count;

	for (int i = 0; i < count; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> temp;
		userInput.push_back(temp);
	}
	do
	{
		int choice = printMenu();
		switch (choice)
		{
			case 1:	//adds all of the numbers the user entered
			{
				add(userInput, count, difference);
				break;
			}
			case 2:	//subtracts all of the numbers that the user entered
			{
				subtract(userInput, count, difference);
				break;
			}
			case 3: //Allows user to enter new numbers
			{
				new_numbers(userInput, count, temp);
				break;
			}
			case 4:	//Delete the last element
			{
				userInput.pop_back();
				break;
			}
			case 5:	//Allow a user to insert a new element at the back of vector
			{
				break;
			}
			case 6:	//Allow a user to insert, at a specific element, an additonal number
			{
				break;
			}
			case 7:	//Allow a user to delete a specific element
			{
				break;
			}
			case 0:
			{
				std::cout << "Exiting now..." << std::endl;
				break;
			}
			default:
			{
				break;
			}
		}

	} while (choice != 0);

	std::cout << "How many numbers would you like to enter? " << std::endl;
	std::cin >> count;
	for (int i = 1; i <= count; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> temp;
		userInput.push_back(temp);
	}

	getchar(); getchar();
	return 0;
}

int subtract(std::vector<int>& input, int count, int difference)
{
	difference = input[0];
	for (int i = 1; i < input.size(); i++)
	{
		difference -= input[i];
	}
	std::cout << "\nThe difference of numbers is: " << difference << "\n\n";	

	return 0;
}

int add(std::vector<int>& input, int count, int sum)
{
	sum = input[0];
	for (int i = 1; i < input.size(); i++)
	{
		sum += input[i];
	}
	std::cout << "\nThe sum of numbers is: " << sum << "\n\n";
	return 0;
}

int new_numbers(std::vector<int>& input, int count, int temp)
{
	input.clear(); count = 0; temp = 0;
	std::cout << "\nHow many numbers would you like to enter? ";
	std::cin >> count;

	for (int i = 0; i < count; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> temp;
		input.push_back(temp);
	}
	return 0;
}

int printMenu()
{
	int choice = 99;
	std::cout << "\n1: Add numbers\n2: Subtract numbers\n3: Enter new numbers\n4: Delete last number\n5: "
				 "Insert number\n6: Insert number at position(x)\n7: Delete specific number\n0: Exit the program" << std::endl;
	std::cin >> choice;

	return choice;
}