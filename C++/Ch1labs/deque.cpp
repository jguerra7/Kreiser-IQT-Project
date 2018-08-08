/*
Name: Will Kreiser
Date: 8 Aug 18
Project: Deque Practice
*/

#include <iostream>
#include <string>
#include <sstream>
#include <deque>

int printIt(std::deque<int> mydeque, int option);
int stillActive();

int main()
{
	int active = 1;  // used for entire app while loop
	int menuChoice;  // int for handling menu selections
	signed int newNumber;  // handles add/subtract
	signed int newPosition;
	std::deque<int> myDeque{ 3, 6, 7, 9, 11, 17, 22 };  // define our deque
	auto total = 0; // handles add/subtract
	std::string input_str;

	while (active == 1)
	{
		printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time

							  // Display a fancy menu
		std::cout << "Menu" << std::endl;
		std::cout << "1.) Input numbers" << std::endl;
		std::cout << "2.) Add numbers" << std::endl;
		std::cout << "3.) Subtract numbers" << std::endl;
		std::cout << "4.) Delete first element" << std::endl;
		std::cout << "5.) Delete last element" << std::endl;
		std::cout << "6.) Delete entire deque " << std::endl;
		std::cout << "7.) BONUS!!\n" << std::endl;

		std::cout << "Please select an option from above: ";

		std::cin >> menuChoice;  // Take user input

		switch (menuChoice)
		{
		case 1:
		{
			std::cin.clear();
			std::cout << "Please enter a list of numbers seperated by spaces to add to the deque: ";
			std::string input;  // initialize string for std::cin
			std::getline(std::cin, input);  // get line from std::cin into input
			std::stringstream stream(input);  // make string stream

			while (1)
			{
				int n;
				stream >> n;
				if (!stream)
					break;
				myDeque.emplace_back(n);  // Add number to end of deque
			}

			std::cout << std::endl;  // because new line.
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
			active = stillActive();  // check if they want to continue
			break;
		}
		case 2:
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			std::cout << "Adding all numbers." << std::endl;
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time

			for (int i = 0; i < myDeque.size(); ++i) // loop through entire deque
			{
				total += myDeque.at(i);  // add each thing
			}

			std::cout << "Total is: " << total << std::endl;
			std::cout << std::endl;

			total = 0;
			active = stillActive();  // check if they want to continue
			break;


		case 3:  // Subtract all numbers
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			std::cout << "Subtracting all numbers." << std::endl;
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time

			for (int i = 0; i < myDeque.size(); ++i) // loop through entire deque
			{
				total -= myDeque.at(i);  // subtract each thing
			}

			std::cout << "Total is: " << total << std::endl;
			total = 0;
			active = stillActive();  // check if they want to continue
			break;

		case 4:  // Remove first element
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
			std::cout << "Removing first element.\n" << std::endl;
			std::cout << "New deque: \n";
			myDeque.pop_front();
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time

			active = stillActive();  // check if they want to continue
			break;

		case 5:  // Remove last element
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
			std::cout << "Removing last element.\n" << std::endl;
			std::cout << "New deque: \n";
			myDeque.pop_back();
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time

			active = stillActive();  // check if they want to continue
			break;

		case 6:  // Clear entire deque
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
			std::cout << "CLEARING ENTIRE deque.\n" << std::endl;
			std::cout << "New deque: \n";
			myDeque.clear();
			printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time

			active = stillActive();  // check if they want to continue
			break;

		case 7:  // BONUS
				 // Display a fancy menu
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			std::cout << "BONUS Menu" << std::endl;
			std::cout << "1.) Insert a new element at the back of deque" << std::endl;
			std::cout << "2.) Insert, at a specific element, an additonal number" << std::endl;
			std::cout << "3.) Delete a specific element\n" << std::endl;

			std::cout << "Please select an option from above: ";

			std::cin >> menuChoice;  // Take user input

			switch (menuChoice)
			{
			case 1:  // Insert a new element at the back of deque
				std::cin.clear();
				system("cls");  // Clear screen to make it purdy
				std::cout << "Please enter a number to add to the back of the deque: ";
				std::cin >> newNumber;  // accept user input
				myDeque.push_back(newNumber);  // Add number to end of deque

				std::cout << std::endl;  // because new line.
				printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
				active = stillActive();  // check if they want to continue
				break;

			case 2:  // Insert, at a specific element, an additonal number
				std::cin.clear();
				system("cls");  // Clear screen to make it purdy
				printIt(myDeque, 1);
				std::cout << "Please select a position: ";
				std::cin >> newPosition;  // accept user input

				std::cout << "Please enter the number to place in the position: ";
				std::cin >> newNumber;  // accept user input

				myDeque.insert(myDeque.begin() + newPosition, newNumber);  // Insert new number in position

				std::cout << std::endl;  // because new line.
				printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
				active = stillActive();  // check if they want to continue
				break;

			case 3:  // Delete a specific element
				std::cin.clear();
				system("cls");  // Clear screen to make it purdy
				printIt(myDeque, 1);
				std::cout << "Please select a position: ";
				std::cin >> newPosition;  // accept user input

				myDeque.erase(myDeque.begin() + newPosition);  // erase number as position

				std::cout << std::endl;  // because new line.
				printIt(myDeque, 0);  // call print function to display deque instead of writing loop each time
				active = stillActive();  // check if they want to continue
				break;

			default:
				std::cin.clear();
				system("cls");  // Clear screen to make it purdy
				std::cout << "FAIL.\n" << std::endl;
				break;

			}

		default:
			std::cin.clear();
			system("cls");  // Clear screen to make it purdy
			std::cout << "FAIL.\n" << std::endl;
			break;
		}
	}

	return 0;
}

int printIt(std::deque<int> myDeque, int option)
{
	// Print deque loop function to save on writing code
	std::cout << "My favorite numbers: ";

	if (option == 1)
	{
		for (int i = 0; i < myDeque.size(); ++i)
			std::cout << "[" << i << "]:" << myDeque.at(i) << " ";
	}
	else
	{
		for (int i = 0; i < myDeque.size(); ++i)
			std::cout << myDeque.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
	return 0;
}

int stillActive()
{
	int menuChoice;
	std::cout << "Would you like to continue?" << std::endl;
	std::cout << "1.) Yes" << std::endl;
	std::cout << "2.) No\n" << std::endl;

	std::cout << "Please select an option from above: ";
	std::cin >> menuChoice;

	system("cls");  // Clear screen to make it purdy
	if (menuChoice == 1)  // They want to continue
		return 1;
	else  // Fin.
		return 0;
}