#include "tower_header.h"

int main()
{
	int n, i;
	int total_moves = 0;
	std::cout << "Enter the number of rings to use: ";
	std::cin >> n;
	for (i = n; i >= 1; i--)
	{
		push1(i);
	}
	total_moves = tower_of_hanoi(n);
	std::cout << "Total moves -> " << total_moves << std::endl;

	getchar(); getchar();
	return 0;
}