#include <iostream> // Needed for IO
#include <fstream>  // Needed for file

int main()
{
	std::ofstream file("streetfighter.txt");
	if (file.is_open())
	{
		file << "Ryu charges before the release...";
		file << "Hadoken! Hadoken!";
		std::cout << "File written" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Unable to open file…";
	}
	getchar(); getchar();
	return 0;
}