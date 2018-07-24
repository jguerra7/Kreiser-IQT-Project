#ifndef MIDTERM_FUNCTIONS_
#define MIDTERM_FUNCTIONS_

#ifdef __cplusplus 
/*
*  This preprocessor directive is necessary to allow this C code to be tested with C++ code
*  e.g., the Google Test framework
*  Do not remove this preprocessor directive
*/
extern "C"
{
#endif


	/*
	* FUNCTION:   int is_it_alphabet(signed char inputChar);
	*
	* ARGUMENTS:  inputChar is a single signed character that represents a single character
	*                 that is tested as an alphabet letter.
	*
	* RETURNS:	  1 if inputChar is an alphabet character
	*             0 if inputChar is not an alphabet character
	*
	* NOTES:      This function should not care if inputChar is uppercase or lowercase
	*             The return value represents a boolean response without using a 'bool' data type
	*             The letters a through z and A through Z represent "alphabet letters" for
	*                 the purposes of this assignment.
	*/
	int is_it_alphabet(signed char inputChar);


	/*
	* FUNCTION:   int reverse_case(char * inputString, char * outputBuff, int inputPosition);
	*
	* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string
	*             outputBuff is expected to be a pointer to a char array which will store the new string
	*             inputPosition is the element of inputString
	*
	* RETURNS:	  Number of characters that were case reversed
	*             -1 if either inputString or outputBuff is NULL
	*             -2 if inputPosition is unrealistic
	*                 Examples:
	*                     inputPosition is negative
	*                     inputPosition is out of the array's scope
	*
	* NOTES:	This function's purpose is to take inputString, determine what are alphabetic characters, and reverse their case.
	*			So capital letters become lowercase. Lowercase becomes uppercase.
	*
	*/

	int reverse_case(char * inputString, char * outputBuff, int inputPosition);


	/*
	* FUNCTION:   int remove_char(char * sentenceString, char userInput);
	*
	* ARGUMENTS:  senteceString is expected to be a pointer to a null-terminated string
	*			  userInput is expected to be a char to be removed from sentenceString
	*
	* RETURNS:	  Number of characters that were removed
	*             -1 if sentenceString is NULL
				-2 if the character can't be found
				-3 if userInput is invalid:
					NULL
					Invalid Input
	*
	* NOTES:      The purpose of this function is to scan sentenceString for userInput (char)... and delete ALL instances of that char IN PLACE
	Then return the number of characters that were removed.
	*/

	int remove_char(char * sentenceString, char userInput);


	/*
	* FUNCTION:   int decode_string(char * inputString, unsigned char key);
	*
	* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string that needs decoded
	*			  key is a single-byte that must be xor'd with (read below)
	*
	* RETURNS:	  Number of characters that were decoded
	*             -1 if inputString is NULL
	*			  -2 if key is invalid
	*
	* NOTES:      This function will take input from inputString and decode it using the unsigned char key.
	*			  The string has been pseudo-encryped (poorly) with a single byte XOR, which you will be required to undo.
	*			  Key is the byte that the buffer was XOR'd against
	*
	*
	*/

	int decode_string(char * inputString, unsigned char key, int dataSize);


	/*
	* FUNCTION:   int clear_a_buffer(char * fullBuff, int buffSize);
	*
	* ARGUMENTS:  fullBuff is expected to be a pointer to a char array
	*             buffSize represents the dimension of fullBuff[]
	*
	* RETURNS:	  0 on success
	*             -1 if fullBuff is NULL
	*             -2 if buffSize is unrealistic
	*                 Examples:
	*                     buffSize is zero
	*                     buffSize is negative
	*
	* NOTES:      This function 'zeroizes' all of the elements of fullBuff[buffSize]
	*             fullBuff does not necessarily need to be a null-terminated string since the array's
	*                 dimension is passed in as an argument (for safety)
	*/
	int clear_a_buffer(char * fullBuff, int buffSize);


#ifdef __cplusplus
	/*
	*  This preprocessor directive is necessary to allow this C code to be tested with C++ code
	*  e.g., the Google Test framework
	*  Do not remove this preprocessor directive
	*/
}
#endif

#endif
