#include <iostream>
#include <map>
#include <string>
#include <cctype>

int main()
{
	std::map<std::string, std::string> person;
	bool found_person = false;
	char fullName;
	auto count = 0;
	int choice = 9;

	do  //do while loop to handle the user menu until 0 is passed.
	{
		choice = printMenu();
		switch (choice)
		{
			case 1:	//enter a person
			{
				std::cout << "Please enter the person's name: ";
				fgets(&fullName, 32, stdin);

				break;
			}
			case 2:	//find a person
			{
				break;
			}
			case 3: //delete a person
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

int printMenu() //This function prints the User interface 
{
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