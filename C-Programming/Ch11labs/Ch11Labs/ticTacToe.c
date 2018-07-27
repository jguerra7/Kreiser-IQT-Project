////////////////////////////////////////////Kreiser, Burright, Vering, Perez/////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 6 /////////////////////////////////////////////
////////////////////////////////////////////// MULTI-DIMENSIONAL ARRAYS /////////////////////////////////////////////
//////////////////////////////////////////////////// "Tic Tac Toe" //////////////////////////////////////////////////
////////////////////////////////////////////////////// Stub Code ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Replicate a tic tac toe grid using a two-dimensional char array of global scope (for ease of use)
// Define the following prototype functions in main(void) according to their specifications:
//     int printTheGrid(void);
//     int any_plays_left(void);
//     char did_someone_win(void);
//     int what_is_your_play(char currentPlayer, int gridLocation);
// Loop through those functions, in the order listed above and below, taking input until:
//     Someone wins *or*
//     There are no more selections (stalemate)
// Check for bad input (e.g., Selection 99) and reported errors (e.g., what_is_your_play() should return -1 on
//     an invalid selection)
// Direct reference to array elements (e.g., myArray[0][1]) is authorized.  In other words, pointer arithmetic
//     is not mandatory.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLUMNS 3

/*
* FUNCTION:   int print_the_grid(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, 1
*             On failure, 0
*
* NOTES:      This function should first print out a tic tac toe legend:
*              1 | 2 | 3
*             -----------
*              4 | 5 | 6
*             -----------
*              7 | 8 | 9
*
*             Then, this function should print out the current state of the 2D char array in a similar format:
*                |   | X
*             -----------
*              X | O |
*             -----------
*                |   |
*/
int print_the_grid(void);

/*
* FUNCTION:   int any_plays_left(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the number of available choices
*             On failure, 0
*
* NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
*/
int any_plays_left(void);

/*
* FUNCTION:   char did_someone_win(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
*             On failure, 0
*
* NOTES:      There are 8 possible win conditions:
*                 Top row, middle row, bottom row
*                 Left column, middle column, right column
*                 Backslash, "Frontslash" (TM pending)
*/
char did_someone_win(void);

/*
* FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
*
* ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
*             int gridLocation should indicate the position on the grid to place "currentPlayer" as
*                 defined by whomever defined print_the_grid().
*
* RETURNS:	   On a successful choice, 1
*             If the user chooses a location that has already been taken, 0
*             On failure, -1
*
* NOTES:      Verify that gridLocation has not already been chosed before accepting the play
*             If the play is valid, record the selection within the 2D tic tac toe array
*/
int what_is_your_play(char currentPlayer, int gridLocation);

void clear_stream(FILE *in);

/* TIC TAC TOE char array */
char ticTacToeGrid[3][3];
int check_new = 1;
char * selection = 0;

int main(void)
{ //fancy title
	printf("==================================================================================\n\n");

	printf("   |''||''|  ||          ' |''||''|                 ' |''||''|\n");
	printf("      ||    ...    ....       ||     ....     ....       ||      ...     ....\n");
	printf("      ||     ||  .|   ''      ||    '' .||  .|   ''      ||    .|  '|. .|...||\n");
	printf("      ||     ||  ||           ||    .|' ||  ||           ||    ||   || ||\n");
	printf("     .||.   .||.  '|...'     .||.   '|..'|'  '|...'     .||.    '|..|'  '|...'\n\n");

	printf("==================================================================================\n\n");
	//declare variables
	char winner;
	int playsLeft;
	char selectionAttempt = 0;
	char currentPlayer = 'O';

	do
	{
		switch (currentPlayer) //determine which player's turn it is
		{
		case 'O':
		{
			print_the_grid();//print grid
			printf("\nPlayer %c make your selection: ", currentPlayer);//tell player to input a grid location
			_flushall();

			while (scanf(" %d", &selection) != 1)// user input
			{
				printf("Invalid integer. Please try again: "); //have user try again if they are incapable of understanding the rules of tic-tac-toe
				clear_stream(stdin);
				_flushall();
			}
			selectionAttempt = what_is_your_play(currentPlayer, selection);
			while (selectionAttempt == 0)	// Already taken
			{
				print_the_grid();
				printf("\nPlayer %c make your selection.\n", currentPlayer);//tell player to input a grid location
				_flushall();
				while (scanf(" %d", &selection) != 1)
				{
					printf("Invalid integer. Please try again: ");//have user try again if they are incapable of understanding the rules of tic-tac-toe
					clear_stream(stdin);
					_flushall();
				}
				selectionAttempt = what_is_your_play(currentPlayer, selection);
			}
			currentPlayer = 'X';
			break;
		}
		case 'X':
		{
			print_the_grid();//print grid
			printf("\nPlayer %c make your selection: ", currentPlayer);//tell player to input a grid location
			_flushall();

			while (scanf(" %d", &selection) != 1)
			{
				printf("Invalid integer. Please try again: ");//have user try again if they are incapable of understanding the rules of tic-tac-toe
				clear_stream(stdin);
				_flushall();
			}
			selectionAttempt = what_is_your_play(currentPlayer, selection);
			while (selectionAttempt == 0)	// Already taken
			{
				print_the_grid();
				printf("\nPlayer %c make your selection: ", currentPlayer);//tell player to input a grid location
				_flushall();
				while (scanf(" %d", &selection) != 1)
				{
					printf("Invalid integer. Please try again: ");//have user try again if they are incapable of understanding the rules of tic-tac-toe
					clear_stream(stdin);
					_flushall();
				}
				selectionAttempt = what_is_your_play(currentPlayer, selection);
			}
			currentPlayer = 'O';
			break;
		}
		default:
			break;
		}
		// DID SOMEONE WIN?  INFORM THE PLAYERS AND END THE GAME 

		winner = did_someone_win();
		if (winner != 0)//check if someone won
		{
			printf("\n\n");
			printf("VICTORY!!!\n\n");//declare and print victory
			printf(" %c | %c | %c\n", ticTacToeGrid[0][0], ticTacToeGrid[0][1], ticTacToeGrid[0][2]);
			printf("-----------\n");
			printf(" %c | %c | %c\n", ticTacToeGrid[1][0], ticTacToeGrid[1][1], ticTacToeGrid[1][2]);
			printf("-----------\n");
			printf(" %c | %c | %c\n", ticTacToeGrid[2][0], ticTacToeGrid[2][1], ticTacToeGrid[2][2]);
			printf("\n");
			printf("%c WINS!\n", winner);
		}
		else
		{
			playsLeft = any_plays_left();//print plays left
		}
	} while (winner == 0 || playsLeft == 0);


	printf("GAME OVER!!!");//declare game over if no one won
						   // NOTE:  Don't forget error checking and input validation along the way.
	getchar();
	getchar();
	return 0;
}

/*
* FUNCTION:   int printTheGrid(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, 1
*             On failure, 0
*
* NOTES:      This function should first print out a tic tac toe legend:
*              1 | 2 | 3
*             -----------
*              4 | 5 | 6
*             -----------
*              7 | 8 | 9
*
*             Then, this function should print out the current state of the 2D char array in a similar format:
*                |   | X
*             -----------
*              X | O |
*             -----------
*                |   |
*/
int print_the_grid(void)
{
	char ticTacToeLegend[3][3] = //print out the tic-tac-toe legend
	{
		{ '1', '2', '3' },
	{ '4', '5', '6' },
	{ '7', '8', '9' }
	};
	printf("\nLegend\n\n");
	printf(" %c | %c | %c\n", ticTacToeLegend[0][0], ticTacToeLegend[0][1], ticTacToeLegend[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", ticTacToeLegend[1][0], ticTacToeLegend[1][1], ticTacToeLegend[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", ticTacToeLegend[2][0], ticTacToeLegend[2][1], ticTacToeLegend[2][2]);

	if (check_new == 1) //see if the blank board has already been printed
	{
		char ticTacToeGrid[3][3] = //print blank board
		{
			{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
		};
		printf("\n\nHere is your playing board. Player One is Os and Player Two is Xs\n");
		printf("Entering a number 1-9 (then pushing enter) as shown below will use\nthe current Player's turn in that location.\n");
	}
	else
	{
		printf("\nCurrent Board\n"); //print current board
	}
	printf("\n");
	printf(" %c | %c | %c\n", ticTacToeGrid[0][0], ticTacToeGrid[0][1], ticTacToeGrid[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", ticTacToeGrid[1][0], ticTacToeGrid[1][1], ticTacToeGrid[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", ticTacToeGrid[2][0], ticTacToeGrid[2][1], ticTacToeGrid[2][2]);

	return 1;
}

/*
* FUNCTION:   int any_plays_left(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the number of available choices
*             On failure, 0
*
* NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
*/

int any_plays_left(void)
{
	int plays_left = 0; //set plays left counter
	for (int i = 0; i < ROWS; i++) //start loop for rows
	{
		for (int x = 0; x < COLUMNS; x++) //start loop for columns
		{
			if (ticTacToeGrid[i][x] != 'X' && ticTacToeGrid[i][x] != 'O') //check for blank grid slot
			{
				plays_left++; //increase plays left counter
			}
		}
	}
	if (plays_left > 0)
	{
		printf("\nThere are %d plays left.\n", plays_left); // print the number of plays left
		return plays_left;
	}
	else
	{
		return 0;
	}

}


/*
* FUNCTION:   char did_someone_win(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
*             On failure, 0
*
* NOTES:      There are 8 possible win conditions:
*                 Top row, middle row, bottom row
*                 Left column, middle column, right column
*                 Backslash, "Frontslash" (TM pending)
*/

char did_someone_win(void)
{
	char test = '?'; //set variable to test wins
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			test = 'X';
		}
		else
		{
			test = 'O';
		}
		// Horizontal Wins 
		if (ticTacToeGrid[0][0] == test && ticTacToeGrid[0][1] == test && ticTacToeGrid[0][2] == test)
			return test;
		if (ticTacToeGrid[1][0] == test && ticTacToeGrid[1][1] == test && ticTacToeGrid[1][2] == test)
			return test;
		if (ticTacToeGrid[2][0] == test && ticTacToeGrid[2][1] == test && ticTacToeGrid[2][2] == test)
			return test;

		//Vertical Wins
		if (ticTacToeGrid[0][0] == test && ticTacToeGrid[1][0] == test && ticTacToeGrid[2][0] == test)
			return test;
		if (ticTacToeGrid[0][1] == test && ticTacToeGrid[1][1] == test && ticTacToeGrid[2][1] == test)
			return test;
		if (ticTacToeGrid[0][2] == test && ticTacToeGrid[1][2] == test && ticTacToeGrid[2][2] == test)
			return test;

		//Across Wins
		if (ticTacToeGrid[0][0] == test && ticTacToeGrid[1][1] == test && ticTacToeGrid[2][2] == test)
			return test;
		if (ticTacToeGrid[2][0] == test && ticTacToeGrid[1][1] == test && ticTacToeGrid[0][2] == test)
			return test;

	}
	// No winner
	if (!test)
		printf("Stalemate!\n");
	return 0;
}

/*
* FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
*
* ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
*             int gridLocation should indicate the position on the grid to place "currentPlayer" as
*                 defined by whomever defined print_the_grid().
*
* RETURNS:	   On a successful choice, 1
*             If the user chooses a location that has already been taken, 0
*             On failure, -1
*
* NOTES:      Verify that gridLocation has not already been chosed before accepting the play
*             If the play is valid, record the selection within the 2D tic tac toe array
*/
int what_is_your_play(char currentPlayer, int gridLocation)
{
	if (!gridLocation) //check if a grid location was input
	{
		return -1;
	}
	else
	{
		int counter = 1; //set counter

		if (gridLocation > 0 && gridLocation <= 9) //check if the input value is between
		{
			for (int i = 0; i < ROWS; i++) //cycle through rows
			{
				for (int j = 0; j < COLUMNS; j++) //cycle through columns
				{
					if (counter == gridLocation) //check if the counter equals the grid location
					{
						if (ticTacToeGrid[i][j] == 'X' || ticTacToeGrid[i][j] == 'O') //check if the grid location is either X or O
						{
							return 0;
						}
						else
						{
							ticTacToeGrid[i][j] = currentPlayer; //set grid location to the current player
							return 1;
						}
					}
					counter++; //increase counter
				}
			}
		}
		else
		{
			return 0;
		}
	}
}

void clear_stream(char *in)
{
	int chars;
	do
		chars = getc(in);
	while (chars != '\n' && chars != EOF);
}