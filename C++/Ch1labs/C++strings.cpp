/*
	Name: Will Kreiser
	Date: 7 Aug 18
	Project: All of the Practice
*/

#include <iostream>
#include <string>

int main()
{
	std::string greeting("Hello World");
	std::cout << greeting << std::endl;

	auto string_length = greeting.length();
	std::cout << "The length is: " << string_length << std::endl;

	auto space_pos = 0;
	auto halfString = greeting.substr(space_pos, 5);
	std::cout << halfString << std::endl;

	auto findMe = greeting.find("r");
	std::cout << "Position is: " << findMe << std::endl;

	auto newString = halfString.append(" Will Kreiser");
	std::cout << newString << std::endl;

	getchar(); getchar();
	return 0;
}