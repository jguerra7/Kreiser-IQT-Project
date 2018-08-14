#include <iostream>
#include <string>
#include <sstream>

/*Function to get string input from the user and checks to make sure all characters are letters
This function requires the following headers:
	- #include <iostream>
	- #include <string>
	- #include <sstream>
*/

std::string get_string_input()
{
	std::string input;
	bool goodString;
	//continue looping until all characters are alphanumeric.. if they arent then get input again
	while (true)
	{
		//gets the string from the input line
		std::getline(std::cin, input);
		//loops through every character
		for (int i = 0; i<input.length(); i++)
		{
			//checks if the character is alphanumeric - if not print an error 
			if (isalpha(input[i]) == false)
			{
				std::cout << "input contains invalid chatacters!" << std::endl;
				goodString = false;
				break;
			}
			else
			{
				goodString = true;
			}
		}
		if (goodString == true)
		{
			break;
		}
	}
	return input;
}

/* Function to get user integer input and error checking to make sure it is a valid integer. 
This function requires the following headers :
	-#include <iostream>
	- #include <string>
	- #include <sstream>
*/
int get_int_input()
{
	int number = 0;
	std::string input = "";
	while (true)
	{
		std::cout << ": ";
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> number)
			break;
		std::cout << "Invalid number, please try again" << std::endl;
	}
	return number;
}