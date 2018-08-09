/*
	Name: Will Kreiser
	Date: 9 Aug 18
	Project: Lab2A
*/

/*
Provided a text file, use the STL to read from it and count each occurrence of each word.
Once complete, output to **stdout **each word, and the number of times it occurred.
Sort the output by words that occured the most to words that occured the least.

The instructional goal of this lab is to give you practice using the STL.
Use STL containers, algorithms, and iterators where they would be helpful.

STL	3
C++	2
Python	1
x86	3
Java	0
*/


#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

//Will be used to print the map later.
void printMap(std::string data);

int main(void)
{
	std::map<std::string, unsigned int> wordsCount;
	
	// Begin reading from file:	
	std::ifstream file("lyrics.txt");
	std::string word;
	std::string fileStream;
	// Check if we've opened the file (as we should have).
	if (file.is_open()) 
	{
		while (std::getline(file, word))
		{
			// Store the next word in the file in a local variable.			
			fileStream.append(word);
			fileStream.append(" ");	
		}
		file.close();
	}
	else  // We couldn't open the file. Report the error in the error stream.
	{
		std::cerr << "Couldn't open the file." << std::endl;
		return -1;
	}

	// Print the words map.
	printMap(fileStream);		

	getchar(); getchar();
	return 0;
}

void printMap(std::string data)
{
	// each word it mapped to it's frequency
	std::map<std::string, int> map;  
	std::stringstream ss(data); // Used for breaking words
	std::string Word; // To store individual words

	while (ss >> Word)
		map[Word]++;  //iterates

	std::map<std::string, int>::iterator m; //names m as the map iterator

	std::cout << "\n\n\n*******\t Not Sorted \t  *******\n\n";

	for (m = map.begin(); m != map.end(); m++)  //FOR loop to iterate between the begining of the map FW and the end (m is the word)
		std::cout << m->first << " -> "  //prints the word
		<< m->second << "\n";  //prints the iterator count


	std::cout << "\n\n******* \t Sorted \t *******\n\n";


	//sort the results: the first loop determines the most frequent map entry
	std::vector<std::pair<int, std::string> > sortMe;
	for (auto it = map.cbegin(); it != map.end(); it++)
	{
		sortMe.emplace_back(make_pair(it->second, it->first));  //pairs the two entries together so sorting by numbers, the word stays with its number
	}
	std::sort(sortMe.rbegin(), sortMe.rend()); //runs sort algorithm

	for (auto it = sortMe.cbegin(); it != sortMe.cend(); it++)
	{
		std::cout << it->second << " -> " << it->first << std::endl;  //prints word and iterator count
	}
}