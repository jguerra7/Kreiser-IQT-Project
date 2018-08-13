#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

int Setup(std::stack<int>& tower, int n);
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>&, int n);
void display(std::stack<int> tower);
static int numMoves = 0;
int get_number_discs();
/*
You are given a _struct disc, with an int variable.
You are also given three stack<disc> towers, source, temp dest._
Read in an int n from the user, and create n number of discs, with each one's int variable numbered [0 - n]. 
Load these in descending order to source.
Your goal is to move the discs from source to dest, noting that you cannot stack a larger number disc on top of a smaller number disc and you can only move the top disc of a tower.
I provided you the function Hanoi().Try and think of an implementation of this function, and use the STL stack functions.
When you are done, print the number of steps to solve to stdout.
Try your solution out with different values of n.Then try and determine the max number of discs.
*/

int main()
{
	std::stack<int> TowerA;
	std::stack<int> TowerB;
	std::stack<int> TowerC;

	int n = 15;      //Number of discs

	n = Setup(TowerA, n);
	Hanoi(TowerA, TowerC, TowerB, n);
	std::cout << "Displaying contents of tower A: " << std::endl;
	display(TowerA);
	std::cout << "Displaying contents of tower B: " << std::endl;
	display(TowerB);
	std::cout << "Displaying contents of tower C: " << std::endl;
	display(TowerC);
	std::cout << "Number of discs to move: " << n << std::endl;
	std::cout << "Actual number of steps taken: " << numMoves << std::endl;

	getchar(); getchar();
	return 0;

}
//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 
//           int n - a number that represents the number of discs to load on to the tower stack
//Return     the number of discs that were loaded on to the tower 
//Functionality: Load a number of discs in ascending order on to the stack 
int Setup(std::stack<int>& tower, int n)
{
	for (int i = n; i > 0; i--)
	{
		tower.push(i);
	}
	return n;
}
//Arguments: std::stack<int>& source - the tower that discs will be moved from
//           std::stack<int>& dest - the twoer that discs will be moved to 
//           std::stack<int>& temp - a tower that can hold discs 
//           int n - the number of discs on the source tower
//Return     none
//Functionality: Move a tower from source to another tower. 
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n)
{
	if (n == 1)
	{
		dest.push(source.top());
		numMoves++;
		source.pop();
	}
	else
	{
		//move from the source to the temp the the disk on top
		Hanoi(source, temp, dest, n - 1);
		//puts the current disk on the destination
		dest.push(source.top());
		numMoves++;
		source.pop();
		//move the disk on temp to the destinatin to make room for something bigger
		Hanoi(temp, dest, source, n - 1);
	}
}
//Arguments: std::stack<int>& tower - a tower that has discs to dispay
//Return     none
//Functionality: Display the contents of a tower
void display(std::stack<int> tower)
{
	while (!tower.empty())
	{
		std::cout << tower.top() << std::endl;
		tower.pop();
	}
}
