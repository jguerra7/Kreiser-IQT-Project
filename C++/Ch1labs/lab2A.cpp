/*
	Name: Will Kreiser
	Date: 8 Aug 18
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


//template <class KTy, class Ty>
/*void PrintMap(std::map<KTy, Ty> map)
{
	typedef std::map<KTy, Ty>::iterator iterator;
	for (iterator p = map.begin(); p != map.end(); p++)
		std::cout << p->first << ": " << p->second << std::endl;
}
*/

//Will be used to print the map later.
void PrintMap(std::map<std::string, unsigned int> map)
{
	typedef std::map<std::string, unsigned int>::iterator iterator;
	for (iterator p = map.begin(); p != map.end(); p++)
		std::cout << p->first << ": " << p->second << std::endl;
}

int main(void)
{
	std::map<std::string, unsigned int> wordsCount;
	// Begin reading from file:	
	std::ifstream fileStream("lyrics.txt");
	// Check if we've opened the file (as we should have).
	if (fileStream.is_open()) 
	{
		while (fileStream.good())
		{
			// Store the next word in the file in a local variable.
			std::string word;
			fileStream >> word;

			//Look if it's already there.
			if (wordsCount.find(word) == wordsCount.end()) // Then we've encountered the word for a first time.
			{
				wordsCount[word] = 1; // Initialize it to 1.
			}
			else // Then we've already seen it before.
			{
				wordsCount[word]++; // Just increment it.
			}					
		}
	}
	else  // We couldn't open the file. Report the error in the error stream.
	{
		std::cerr << "Couldn't open the file." << std::endl;
		return -1;
	}

	// Print the words map.
	PrintMap(wordsCount);
		

	getchar(); getchar();
	return 0;
}
