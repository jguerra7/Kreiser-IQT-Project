#include "tower_header.h"

struct tower1		//struct for Tower 1
{
	int data1;
	tower1 *next1;	
}*top1 = NULL, *p1 = NULL, *np1 = NULL;

struct tower2
{
	int data2;
tower2 *next2;
}*top2 = NULL, *p2 = NULL, *np2 = NULL;

struct tower3
{
	int data3;
	tower3 *next3;
}*top3 = NULL, *p3 = NULL, *np3 = NULL;

//This is the first function related to displaying and manipulating the first tower.
void display1()	//Displays the first tower
{
	std::cout << std::endl;
	tower1 *p1;
	p1 = top1;
	std::cout << "Tower1-> ";
	while (p1 != NULL)
	{
		std::cout << "O " ;
		p1 = p1->next1;
	}
	std::cout << std::endl;
}
void push1(int data)
{
	np1 = new tower1;	//new allocates memory equal to (sizeof(tower1) and then constructs an (clone of Tower1) and set it equal to np1
	np1->data1 = data;	//np1 is a pointer to Tower1 struct declared in header
	np1->next1 = NULL;	//next1 is a pointer to the next node
	if (top1 == NULL)
	{
		top1 = np1;
	}
	else
	{
		np1->next1 = top1;
		top1 = np1;
	}
}
int pop1()
{
	int b = 999;
	if (top1 == NULL)
	{
		return b;
	}
	else
	{
		p1 = top1;
		top1 = top1->next1;
		return p1->data1;	
		delete(p1);
	}
}

//This is the first function related to displaying and manipulating the second tower.
void display2()	//Displays the second tower
{
	tower2 *p2;
	p2 = top2;
	std::cout << "Tower2-> ";
	while (p2 != NULL)
	{
		std::cout << "O ";
		p2 = p2->next2;
	}
	std::cout << std::endl;
}
void push2(int data)
{
	np2 = new tower2;	//new allocates memory equal to (sizeof(tower2) and then constructs an (clone of Tower2) and set it equal to np2
	np2->data2 = data;	//np2 is a pointer to Tower2 struct declared in header
	np2->next2 = NULL;
	if (top2 == NULL)
	{
		top2 = np2;
	}
	else
	{
		np2->next2 = top2;
		top2 = np2;
	}
}
int pop2()
{
	int b = 999;
	if (top2 == NULL)
	{
		return b;
	}
	else
	{
		p2 = top2;
		top2 = top2->next2;
		return(p2->data2);
		delete(p2);
	}
}

//This is the first function related to displaying and manipulating third tower.
void display3()	//Displays the third tower
{
	tower3 *p3;
	p3 = top3;
	std::cout << "Tower3-> " ;
	while (p3 != NULL)
	{
		std::cout << "O ";
		p3 = p3->next3;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
void push3(int data)
{
	np3 = new tower3;	//new allocates memory equal to (sizeof(tower3) and then constructs an (clone of Tower3) and set it equal to np3
	np3->data3 = data;	//np3 is a pointer to Tower3 struct declared in header
	np3->next3 = NULL;
	if (top3 == NULL)
	{
		top3 = np3;
	}
	else
	{
		np3->next3 = top3;
		top3 = np3;
	}
}
int pop3()
{
	int b = 999;
	if (top3 == NULL)
	{
		return b;
	}
	else
	{
		p3 = top3;
		top3 = top3->next3;
		return(p3->data3);
		delete(p3);
	}
}

int top_of_stack()
{
	int num_moves = 0;
	if (top1 != NULL && top1->data1 == 1)
	{
		return 1;
	}
	else if (top2 != NULL && top2->data2 == 1)
	{
		return 2;
	}
	else if (top3 != NULL && top3->data3 == 1)
	{
		return 3;
	}
}

int tower_of_hanoi(int n)	//Tower of Hanoi Functionality
{
	int i, x, a, b;
	int num_moves = 0;
	for (i = 0; i < (pow(2, n)); i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		display1();
		display2();
		display3();

		x = top_of_stack();
		if (i % 2 == 0)
		{
			if (x == 1)
			{
				num_moves++;
				push3(pop1());
			}
			else if (x == 2)
			{
				num_moves++;
				push1(pop2());
			}
			else if (x == 3)
			{
				num_moves++;
				push2(pop3());
			}
		}
		else
		{
			if (x == 1)
			{
				a = pop2();
				b = pop3();
				if (a < b && b != 999)
				{
					num_moves++;
					push3(b);
					push3(a);
				}
				else if (a > b && a != 999)
				{
					num_moves++;
					push2(a);
					push2(b);
				}
				else if (b == 999)
				{
					num_moves++;
					push3(a);
				}
				else if (a == 999)
				{
					num_moves++;
					push2(b);
				}
			}
			else if (x == 2)
			{
				a = pop1();
				b = pop3();
				if (a < b && b != 999)
				{
					num_moves++;
					push3(b);
					push3(a);
				}
				else if (a > b && a != 999)
				{
					num_moves++;
					push1(a);
					push1(b);
				}
				else if (b == 999)
				{
					num_moves++;
					push3(a);
				}
				else if (a == 999)
				{
					num_moves++;
					push1(b);
				}
			}
			else if (x == 3)
			{
				a = pop1();
				b = pop2();
				if (a < b && b != 999)
				{
					num_moves++;
					push2(b);
					push2(a);
				}
				else if (a > b && a != 999)
				{
					num_moves++;
					push1(a);
					push1(b);
				}
				else if (b == 999)
				{
					num_moves++;
					push2(a);
				}
				else if (a == 999)
				{
					num_moves++;
					push1(b);
				}
			}
		}
	}
	return num_moves;
}