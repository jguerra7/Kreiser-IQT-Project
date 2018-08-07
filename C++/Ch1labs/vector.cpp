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
#include "vector_header.h"
std::vector<int> userInput;

int main()
{
	char c;
	int GOOD_INPUT = 0;
	auto count = 0;
	auto difference = 0;
	auto sum = 0;
	auto temp = 0;
	int choice = 99;;
	//Allow a user to input a series of numbers, which are stored into a vector
	std::cout << "Vector Calculator" << std::endl;
	std::cout << "-----------------" << std::endl;

	while (GOOD_INPUT < 1)
	{
		std::cout << "How many numbers would you like to enter? ";
		std::cin >> count;
		if (!(count) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cout << "The value must be an integer: " << std::endl;
			std::cin.clear();
			GOOD_INPUT = 0;
		}
		else
		{
			GOOD_INPUT = 1;
		}
	}	
	for (int i = 0; i < count; i++)
	{
		std::cout << "Please enter a number: ";
		std::cin >> temp;
		if (!(temp) || (std::cin.get(c)) && !std::isspace(c))
		{
			std::cin.clear();
			std::cout << "The value must be an integer: " << std::endl;
			std::cin >> temp;
		}
		else
		{
			userInput.push_back(temp);			
		}		
	}
		
	do  //do while loop to handle the user menu until 0 is passed.
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
				insert_single(userInput);
				break;
			}
			case 6:	//Allow a user to insert, at a specific element, an additonal number
			{
				insert_specific_single(userInput);
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

	getchar(); getchar();
	return 0;
}

