// This project will be used to familiarize yourself with the many different functional components
// that the C programming language contains. It will be broken out into several source files to 
// practice different conceptual topics (String manipulation, Memory management, I/O, Sockets, Pointers, etc.
// This will be an ongoing project until the majority of C functionality has been broken out and 
// competency has been established.

#include <stdio.h>

#define MAX_BUFF_SIZE 256
//This struct will contain the different strings to be tested against
struct stringify {
	char string1[MAX_BUFF_SIZE];
	char string2[MAX_BUFF_SIZE];
	char string3[MAX_BUFF_SIZE];
};

/********************************************************************************
* This file, once complete, will allow the user to select how to reverse 
* one of the 3 strings passed in from the external struct above. This function 
* will test all 3 strings and each string needs to be reversed in a different way.
* 
* The 2 ways the string will be reversed are:
*	1. The entire string
*	2. Word by Word
*	3. 
*
********************************************************************************/
int stringReversal(struct stringify *string)
{
	
}

