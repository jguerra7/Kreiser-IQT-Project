/*
	Name: William Kreiser
	Date: 8 Aug 18
	Project: Linked List
*/
/*
Using what you know from C/C++ so far, create a quick and simple print program that accomplishes the following:
	- Allows user to add characters to the list
	- Allows user to pop off a character
	- Print each of the characters on a new line
	- Do the same with a fordward_list
	- Attempt to use operator[] or at(), note the results.
*/
#include <iostream>
#include <list>
#include <string>
#include <forward_list>


int main()
{
	char input = 0;
	int count = 0;
	std::list<char> myList;
	std::forward_list<char> myForwardList;
	std::cout << "How many character would you like to enter(up to 32)? ";
	std::cin >> count;
	if (!count)
	{
		std::cin.clear();
		std::cout << "You must enter a number. " << std::endl;
		std::cin >> count;
	}
			
	for (int i = 1; i <= count; i++)
	{
		std::cout << "Please enter a character: ";
		std::cin >> input;
		myList.push_back(input);	//doubly linked list
		myForwardList.push_front(input + 1);	//forward list
	}

	std::cout << "Would you like to delete a character from the back of the list? (Y/N) " << std::endl;
	std::cin >> input;
	if (!input)
	{
		std::cin.clear();
		std::cout << "Please enter Y for yes or N for no. " << std::endl;
		std::cin >> input;
	}
	else if (input == 'Y' || input == 'y')
	{
		myList.pop_back();	//pop_back can only be used on doubly linked list
	}

	std::cin.clear();
	std::cout << "Would you like to delete a character from the front of the list? (Y/N) " << std::endl;
	std::cin >> input;
	if (!input)
	{
		std::cin.clear();
		std::cout << "Please enter Y for yes or N for no. " << std::endl;
		std::cin >> input;
	}
	else if (input == 'Y' || input == 'y')
	{
		myList.pop_front();	//Pop off front of doubly linked list
		myForwardList.pop_front();	//Pops the element off of the front of forward list
	}

	std::cout << '\n';	//Newline for viewing ease
	for (const auto& back : myList)	//Prints doubly linked list
	{

		std::cout << back << " ";
		std::cout << '\n' ;
	}
	
	std::cout << '\n';	std::cout << '\n';	//Newline for viewing ease
	for (const auto& front : myForwardList)	//Prints forward list
	{
		std::cout << front << " ";
		std::cout << '\n';
	}

	getchar(); getchar();
	return 0;
}