/*	Name: William Kreiser
	Date: 24 July 18
	Project: Conditional Compilation (Lab10.7)

		CONDITONAL COMPILATION
1.	Redefine EOF as 66 (without compiler warnings)

2.	Use preprocessor directive(s) to:
		Only compile in "release" and only compile if _INC_STDIO is defined
		Prints the name of a MACRO and also print the integer value of that MACRO
		Use a #else 'fall through' for ease of use and safety
3.	Use your preprocessor directives on FOPEN_MAX, FILENAME_MAX, and EOF
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define INT(x) #x
#define PRINT_PREPROCESSOR(x) printf("%s = %s\n", #x, INT(x))

#ifdef EOF
#undef EOF
#define EOF 66
#endif

#define _INC_STDIO
#ifndef _INC_STDIO
int main()
{
	printf("STDIO is undefined!!!\n");
	return -1;
}
#else
int main()
{
	PRINT_PREPROCESSOR(EOF);
	PRINT_PREPROCESSOR(FILENAME_MAX);
	PRINT_PREPROCESSOR(FOPEN_MAX);

	return 0;
}
#endif