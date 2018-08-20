#include <string>
#include <iostream>
#include <sstream>

/*
This is a function that provides error checking for string input.
	It requires the following headers:
	- #include<sstream>
	- #include<string>
	- #include<iostream>
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
				std::cout << "input contains invalid characters!" << std::endl;
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
/*
	This is a function that provides error checking for integer input. 
	It requires the following headers:
	- #include<sstream>
	- #include<string>
	- #include<iostream>
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