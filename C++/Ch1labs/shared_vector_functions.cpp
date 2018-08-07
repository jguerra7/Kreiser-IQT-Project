#include "vector_header.h"

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
	char c;
	input.clear(); count = 0; temp = 0;
	std::cout << "\nHow many numbers would you like to enter? ";
	std::cin >> count;

	while (!count)
	{
		if (!(std::cin >> count) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cin.clear();
			std::cout << "Value must be an integer: " << std::endl;
			std::cin >> count;
		}
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> temp;
		while (!temp)
		{
			char c;
			if (!(temp) || (std::cin.get(c)) && !std::isspace(c))
			{
				std::cin.clear();
				std::cout << "The value must be an integer: " << std::endl;
				std::cin >> temp;
			}
			input.push_back(temp);
		}
	}
	return 0;
}

int printMenu() //This function prints the User interface 
{
	int GOOD_INPUT = 0;
	int choice;
	char c;
	std::cout << "\n1: Add numbers\n2: Subtract numbers\n3: Enter new numbers\n4: Delete last number\n5: "
		"Insert number\n6: Insert number at position(x)\n7: Delete specific number\n0: Exit the program" << std::endl;
	std::cin >> choice;
	while (!choice)
	{		
		if (!(std::cin >> choice) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cin.clear();
			std::cout << "Value must be an integer: " << std::endl;
			std::cin >> choice;
		}
	}
	return choice;
}

int insert_single(std::vector<int>& input)	//This allows user to insert a single number at the end of the vector
{
	int temp = 0;
	char c;
	std::cout << "Please enter a number: ";
	std::cin >> temp;
	while (!temp)
	{
		if (!(std::cin >> temp) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cin.clear();
			std::cout << "Value must be an integer: " << std::endl;
			std::cin >> temp;
		}
	}
	input.push_back(temp);

	return 0;
}

int insert_specific_single(std::vector<int>& input)	//This allows a number to be inserted into the vector at position #x
{
	int temp = 0;
	int index = 0;
	char c;
	std::cout << "Current number positions(#1, #2, #3, etc)." << std::endl;
	for (std::vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	
	std::cout << "Enter the number position where you want the new number to be placed: " << std::endl;
	std::cin >> index;
	while (!index)
	{
		if (!(std::cin >> index) || (index < 0 && index > input.size()) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cout << "The value must be an integer: " << std::endl;
			std::cin >> index;
		}
	}
	
	std::cout << "Please enter a number: " << std::endl;
	std::cin >> temp;
	while (!temp)
	{
		if (!(std::cin >> temp) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cout << "Enter the number position where you want the new number to be placed: " << std::endl;
			std::cin >> temp;
		}
	}
	input.insert(input.begin() + index, temp);
		
	return 0;
}