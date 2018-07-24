/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// C-Midterm-2018-2 ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// CODE TESTER /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#include "MidtermFunctions.h"

/*
* This pre-processing directive determines whether the program will
*     run tests and/or prompt the user for input depending on
*     what #define statements are uncommented.
*/
#define AUTO_ALPHABET_CHECK // Runs tests on is_it_alphabet()
#define AUTO_REVERSE_CASE // Runs tests on reverse_case()
#define AUTO_REMOVE_CHAR // Runs tests on reverse_string()
#define AUTO_CLEAR_BUFFER // Runs tests on clear_a_buffer()
#define AUTO_DECODE_STRING // Runs test on decode_string()
//#define AUTO_FULL_PROGRAM // Runs tests on the entire program as a whole, incorporating all functions
//#define MANUAL_FULL_PROGRAM // Allows the programmer to manually provide input to test the response of the program as a whole
/*
* Uncomment multiple #defines to multiple tests in a single run
*/

#define BUFF_SIZE 512

char sourceString[BUFF_SIZE] = { 0 };
char destinationBuff[BUFF_SIZE] = { 0 };

int main(void)
{
	/* Variables used by multiple testing sections */
	int i = 0;						// Iterating variable

	int totalUnitTestsPassed = 0;	// Counts the number of tests that have passed
	int totalUnitTestsRun = 0;		// Counts the number of tests that have been run, pass or fail
	int tempReturnValue = 0;		// Temporary holder for function return values
	int tempCount = 0;				// Temproary counter

// =========================================================
//						ALPHA CHECK
// =========================================================

#ifdef AUTO_ALPHABET_CHECK

									/*
									*  This array represents the expected return value from is_it_alphabet()
									*  This unit test will pass all available signed char values
									*  The elements of of expectedAutoAlphabetCheckReturnValues[] correspond to the 255 available values in signed chars
									*  The elements are shifted 127 so that the first element represents char value -127
									*  The values of each element represents the expected return value for that input
									*  expectedAutoAlphabetCheckReturnValues[i] == is_it_alphabet(i)
									*/
	int expectedAutoAlphabetCheckReturnValues[127 + 128] = { 0 }; // Zeroize an array with enough indices to represent the range of values for a signed char
	for (i = (127 + 65); i <= (127 + 90); i++) // Char values representing A - Z...
	{
		expectedAutoAlphabetCheckReturnValues[i] = 1; // ...should return TRUE from is_it_alphabet()
	}
	for (i = (127 + 97); i <= (127 + 122); i++) // Char values representing a - z...
	{
		expectedAutoAlphabetCheckReturnValues[i] = 1; // ...should return TRUE from is_it_alphabet()
	}

	int autoAlphabetCheckTestsPassed = 0; // Stores the number of tests is_it_alphabet() has passed
	int autoAlphabetCheckTestsRun = 0; // Stores the number of tests is_it_alphabet() has run through

	printf("\n************************\n");
	printf("TESTING is_it_alphabet()\n");
	printf("************************\n");

	for (i = -127; i <= 127; i++) // Loops through all available values of a signed char
	{
		autoAlphabetCheckTestsRun++; // Keeps track of how many is_it_alphabet() tests have been run
		totalUnitTestsRun++; // Keeps track of how many total tests have been run

		if (is_it_alphabet((signed char)i) == expectedAutoAlphabetCheckReturnValues[i + 127]) // If the is_it_alphabet() return value matches the expected return value...
		{
			autoAlphabetCheckTestsPassed++; // ...record the fact that a is_it_alphabet() test has passed and...
			totalUnitTestsPassed++; // ...record the fact that one of the overall tests has been passed.
		}
	}

	printf("%d tests were run on is_it_alphabet() \n%d tests were passed.\n", autoAlphabetCheckTestsRun, autoAlphabetCheckTestsPassed);
#endif


// =========================================================
//						REVERSE CASE
// =========================================================


#ifdef AUTO_REVERSE_CASE

	/* SAMPLE INPUT */
	char autoRemoveCharString1[BUFF_SIZE] = { "ALL CAPS BABY" };					// All caps
	char autoRemoveCharString2[BUFF_SIZE] = { "Normal spaces" };					// Two words
	char autoRemoveCharString3[BUFF_SIZE] = { "This is a normal sentence." };		// A sentence
	char autoRemoveCharString4[BUFF_SIZE] = { "!@#$%^&*()_+" };						// All non-letters
	char autoRemoveCharString5[BUFF_SIZE] = { "=-+                    +-=" };		// Mostly spaces
	char autoRemoveCharString6[BUFF_SIZE] = { "Password: P@$$w0rd!" };				// Everything combined
	char * autoRemoveCharString7 = NULL;												// NULL pointer
	char autoRemoveCharString8[BUFF_SIZE] = { "HIDDEN string? This is hidden!" };	// String hidden behind a manual nul terminator
	autoRemoveCharString8[14] = 0;													// Manual nul terminator
	int reversePos[8] = { 0, 0, 0, 0, 0, 0, 0, 7};

	char * autoReverseCharStrings[] = { autoRemoveCharString1, autoRemoveCharString2, autoRemoveCharString3, autoRemoveCharString4, autoRemoveCharString5, autoRemoveCharString6, autoRemoveCharString7, autoRemoveCharString8 };


	/* EXPECTED RESULTS */
	char autoRemoveCharStringResult1[BUFF_SIZE] = { "all caps baby" };						// All caps
	char autoRemoveCharStringResult2[BUFF_SIZE] = { "nORMAL SPACES" };						// Two words
	char autoRemoveCharStringResult3[BUFF_SIZE] = { "tHIS IS A NORMAL SENTENCE." };			// A sentence
	char autoRemoveCharStringResult4[BUFF_SIZE] = { "!@#$%^&*()_+" };						// All non-letters
	char autoRemoveCharStringResult5[BUFF_SIZE] = { "=-+                    +-=" };			// Mostly spaces
	char autoRemoveCharStringResult6[BUFF_SIZE] = { "pASSWORD: p@$$W0RD!" };				// Everything combined
	char * autoRemoveCharStringResult7 = NULL;												// NULL pointer
	char autoRemoveCharStringResult8[BUFF_SIZE] = { "STRING?" };						// String hidden behind a manual nul terminator

	char * autoRemoveCharStringResults[] = { autoRemoveCharStringResult1, autoRemoveCharStringResult2, autoRemoveCharStringResult3, autoRemoveCharStringResult4, autoRemoveCharStringResult5, autoRemoveCharStringResult6, autoRemoveCharStringResult7, autoRemoveCharStringResult8 };


	/* EXPECTED RETURN VALUES */
	tempReturnValue = 0;
	int autoReverseCaseReturnValues[] = { 11, 12, 21, 0, 0, 12, -1, 6 };					// Parallel array of expected return values

	int autoReverseCaseTestsPassed = 0;
	int autoReverseCaseTestsRun = 0;

	printf("\n****************************\n");
	printf("TESTING reverse_case()\n");
	printf("****************************\n");

	for (i = 0; i < (sizeof(autoReverseCharStrings) / sizeof(autoReverseCharStrings[0])); i++)
	{
		printf("TEST #%d:\n", i + 1);
		printf("\tInput String:\t");
		if (autoReverseCharStrings[i])
		{
			puts(autoReverseCharStrings[i]);
		}
		else
		{
			printf("NULL\n");
		}

		// Run function 
		tempReturnValue = reverse_case(autoReverseCharStrings[i], destinationBuff, reversePos[i]);

		printf("\tReturn Value:\t");
		autoReverseCaseTestsRun++;
		totalUnitTestsRun++;
		if (tempReturnValue == autoReverseCaseReturnValues[i])
		{
			printf("PASS\n");
			autoReverseCaseTestsPassed++;
			totalUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}

		printf("\tOutput String:\t");
		autoReverseCaseTestsRun++;
		totalUnitTestsRun++;
		if (autoReverseCharStrings[i])
		{
			puts(destinationBuff);
		}
		else
		{
			printf("NULL\n");
		}
		printf("\tString Test:\t");
		if (autoReverseCharStrings[i])
		{
			if (strcmp(autoRemoveCharStringResults[i], destinationBuff) == 0)
			{
				printf("PASS\n");
				autoReverseCaseTestsPassed++;
				totalUnitTestsPassed++;
			}
			else
			{
				printf("FAIL\n");
			}
		}
		else
		{
			printf("SKIP: NULL\n");
			autoReverseCaseTestsPassed++;
			totalUnitTestsPassed++;
		}
	}

	printf("%d tests were run on reverse_case() \n%d tests were passed.\n", autoReverseCaseTestsRun, autoReverseCaseTestsPassed);

#endif



	// =========================================================
	//						REMOVE_CHAR
	// =========================================================

#ifdef AUTO_REMOVE_CHAR

	/* SAMPLE INPUT */
	const char autoReverseStringTest1[BUFF_SIZE] = { "This is a test string." };
	const char autoReverseStringTest2[BUFF_SIZE] = { "Test." };
	const char autoReverseStringTest3[BUFF_SIZE] = { "1" };
	const char autoReverseStringTest4[BUFF_SIZE] = { "!@#$%^&*()_+-=" };
	const char autoReverseStringTest5[BUFF_SIZE] = { "Hello wwwwwwwwwWorld" };
	const char autoReverseStringTest6[BUFF_SIZE] = { "I.3. I declare a thumb war!" };
	const char * autoReverseStringTest7 = NULL;
	char autoReverseStringTest8[BUFF_SIZE] = { "Real string? Hidden string!" };
	autoReverseStringTest8[12] = 0;
	const char autoReverseStringTest9[BUFF_SIZE] = { "Nothing" };
	const char autoReverseStringTest10[BUFF_SIZE] = { "a" };

	const char * autoCharDeleteTestArray[] = { autoReverseStringTest1, autoReverseStringTest2, autoReverseStringTest3, autoReverseStringTest4, autoReverseStringTest5, autoReverseStringTest6, autoReverseStringTest7, autoReverseStringTest8, autoReverseStringTest9, autoReverseStringTest10 };

	/* ARRAY ELEMENT INPUT */
	const char autoCharDeleteChars[] = { 'a', 'b', 'c', 'd', 'w', 'I', '!', 's', 'o', 'a' };

	/* EXPECTED RETURN VALUES */
	const int autoCharDeleteReturnValues[] = { 1, -2, -2, -2, 9, 2, -1, 1, 1, 1 };

	/* EXPECTED OUTPUT */
	const char autoReverseStringResult1[BUFF_SIZE] = { "This is  test string." };
	const char autoReverseStringResult2[BUFF_SIZE] = { "Test." };
	const char autoReverseStringResult3[BUFF_SIZE] = { "1" };
	const char autoReverseStringResult4[BUFF_SIZE] = { "!@#$%^&*()_+-=" };
	const char autoReverseStringResult5[BUFF_SIZE] = { "Hello World" };
	const char autoReverseStringResult6[BUFF_SIZE] = { ".3.  declare a thumb war!" };
	const char * autoReverseStringResult7 = NULL;
	char autoReverseStringResult8[BUFF_SIZE] = { "Real tring?" };
	const char autoReverseStringResult9[BUFF_SIZE] = { "Nthing" };
	const char autoReverseStringResult10[BUFF_SIZE] = { 0 };

	const char * autoCharDeleteResultArray[] = { autoReverseStringResult1, autoReverseStringResult2, autoReverseStringResult3, autoReverseStringResult4, autoReverseStringResult5, autoReverseStringResult6, autoReverseStringResult7, autoReverseStringResult8, autoReverseStringResult9, autoReverseStringResult10 };

	int autoCharDeleteTestsPassed = 0;
	int autoCharDeleteTestsRun = 0;
	tempReturnValue = 0;


	printf("\n***********************\n");
	printf("TESTING CHAR REMOVAL\n");
	printf("***********************\n");

	for (i = 0; i < (sizeof(autoCharDeleteTestArray) / sizeof(autoCharDeleteTestArray[0])); i++)
	{
		printf("TEST #%d\n", i + 1);

		// check we are not null on our test
		if (autoCharDeleteTestArray)
		{
			printf("Input String:               %s\n", autoCharDeleteTestArray[i]);
			printf("Character to remove:        %c\n", autoCharDeleteChars[i]);

			// run the function
			tempReturnValue = remove_char(autoCharDeleteTestArray[i], autoCharDeleteChars[i]);

			// check return
			if (tempReturnValue == autoCharDeleteReturnValues[i])
			{
				autoCharDeleteTestsPassed++;
				autoCharDeleteTestsRun++;
				printf("Return Value:               PASS\n");
			}
			else
			{
				autoCharDeleteTestsRun++;
				printf("Return Value:               FAIL\n");
			}

			// check output
			if (autoCharDeleteResultArray[i])
			{
				if (strcmp(autoCharDeleteTestArray[i], autoCharDeleteResultArray[i]) == 0)
				{
					printf("Output String:              %s\n", autoCharDeleteTestArray[i]);
					printf("String Test:                PASS\n");
					autoCharDeleteTestsPassed++;
					autoCharDeleteTestsRun++;
				}
				else
				{
					printf("Output String:              %s\n", autoCharDeleteTestArray[i]);
					printf("String Test:                FAIL\n");
					autoCharDeleteTestsRun++;
				}
			}
			else
			{
				printf("Output String:              NULL\n");
				printf("String Test:                N/A NULL\n");
				autoCharDeleteTestsPassed++;
				autoCharDeleteTestsRun++;
			}
		}

	}

	printf("%d tests were run on char_removal() \n%d tests were passed.\n", autoCharDeleteTestsRun, autoCharDeleteTestsPassed);

	totalUnitTestsRun += autoCharDeleteTestsRun;
	totalUnitTestsPassed += autoCharDeleteTestsPassed;


#endif

#ifdef AUTO_CLEAR_BUFFER

#define DIFF_BUFF_SIZE 1337

	char differentSizedBuffer[DIFF_BUFF_SIZE] = { 0 };
	int autoClearBufferTestsPassed = 0;
	int autoClearBufferTestsRun = 0;
	char tempChar = ~0;

	for (i = 0; i < DIFF_BUFF_SIZE; i++)
	{
		differentSizedBuffer[i] = '!'; // Fill the end of the destinationBuff with gunk
	}

	printf("\n************************\n");
	printf("TESTING clear_a_buffer()\n");
	printf("************************\n");

	printf("TEST #1 (Larger Buffer):\n");
	printf("\tReturn Value:\t");
	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	tempReturnValue = clear_a_buffer(differentSizedBuffer, DIFF_BUFF_SIZE);

	if (tempReturnValue)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}

	printf("\tBuffer Status:\t");
	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	/*
	*  <disclaimer> The following code *should* be extracted into a function with prototype...
	*  int check_a_buffer(char * targetBuff, int buffSize); // Returns the number of non-null chars found
	*  This code was *not* extracted in an attempt to avoid performing the students work for them
	*/
	tempCount = 0;
	for (i = 0; i < DIFF_BUFF_SIZE; i++)
	{
		if (differentSizedBuffer[i] & tempChar)
		{
			tempCount++;
		}
	}
	/* </disclaimer> */

	if (tempCount)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}

	printf("TEST #2 (Normal Buffer):\n");
	printf("\tReturn Value:\t");

	/* Fill destinationBuff[] according to its size */
	if (BUFF_SIZE >= 8)
	{
		for (i = 0; i < (BUFF_SIZE - 8); i += 7)
		{
			destinationBuff[i] = '9';
			destinationBuff[i + 1] = '0';
			destinationBuff[i + 2] = ' ';
			destinationBuff[i + 3] = 'I';
			destinationBuff[i + 4] = 'O';
			destinationBuff[i + 5] = 'S';
			destinationBuff[i + 6] = ' ';
			destinationBuff[i + 7] = 0;
		}
		destinationBuff[BUFF_SIZE - 1] = 0; // Manual null terminator (for safety)
	}
	else if (BUFF_SIZE >= 2)
	{
		destinationBuff[0] = '?';
		destinationBuff[1] = 0;
	}
	else
	{
		destinationBuff[0] = 0; // The destinationBuff must only have one element so it's set to 0 (for safety)
	}

	/* Clear destinationBuff[] */
	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	tempReturnValue = clear_a_buffer(destinationBuff, BUFF_SIZE);

	/* Check clear_a_buffer()'s return value */
	if (tempReturnValue)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}

	printf("\tBuffer Status:\t");
	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	/*
	*  <disclaimer> The following code *should* be extracted into a function with prototype...
	*  int check_a_buffer(char * targetBuff, int buffSize); // Returns the number of non-null chars found
	*  This code was *not* extracted in an attempt to avoid performing the students work for them
	*/
	tempCount = 0;
	for (i = 0; i < BUFF_SIZE; i++)
	{
		if (destinationBuff[i] & tempChar)
		{
			tempCount++;
		}
	}
	/* </disclaimer> */

	/* Test the status of destinationBuff[] */
	if (tempCount)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}
	tempReturnValue = clear_a_buffer(destinationBuff, BUFF_SIZE);


	/*
	*  <disclaimer> The following code *should* be extracted into a function with prototype...
	*  int check_a_buffer(char * targetBuff, int buffSize); // Returns the number of non-null chars found
	*  This code was *not* extracted in an attempt to avoid performing the students work for them
	*/
	tempCount = 0;
	for (i = 0; i < BUFF_SIZE; i++)
	{
		if (destinationBuff[i] & tempChar)
		{
			tempCount++;
		}
	}
	/* </disclaimer> */

	printf("TEST #3 (Abnormal Buffer Size of 0):\n");
	printf("\tReturn Value:\t");

	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	tempReturnValue = clear_a_buffer(destinationBuff, 0);

	if (-2 == tempReturnValue)
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}
	else
	{
		printf("FAIL (expected -2 but received %d)\n", tempReturnValue);
	}
	tempReturnValue = 0;

	printf("\tBuffer Status:\tSKIPPED\n");


	printf("TEST #4 (Very Abnormal Buffer Size of -999):\n");
	printf("\tReturn Value:\t");

	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	tempReturnValue = clear_a_buffer(destinationBuff, -999);

	if (-2 == tempReturnValue)
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}
	else
	{
		printf("FAIL (expected -2 but received %d)\n", tempReturnValue);
	}
	tempReturnValue = 0;

	printf("\tBuffer Status:\tSKIPPED\n");

	printf("TEST #5 (NULL Pointer):\n");
	printf("\tReturn Value:\t");

	autoClearBufferTestsRun++;
	totalUnitTestsRun++;
	tempReturnValue = clear_a_buffer(NULL, BUFF_SIZE);

	if (-1 == tempReturnValue)
	{
		printf("PASS\n");
		autoClearBufferTestsPassed++;
		totalUnitTestsPassed++;
	}
	else
	{
		printf("FAIL (expected -1 but received %d)\n", tempReturnValue);
	}
	tempReturnValue = 0;

	printf("\tBuffer Status:\tSKIPPED\n");

	printf("%d tests were run on clear_a_buffer(). \n%d tests were passed.\n", autoClearBufferTestsRun, autoClearBufferTestsPassed);

#endif


// ===============================================
// ===============================================

#ifdef AUTO_DECODE_STRING

	char preDecodeStr1[BUFF_SIZE] = "Hello World";
	char preDecodeStr2[BUFF_SIZE] = "This is a test!";
	char preDecodeStr3[BUFF_SIZE] = "BAKA";
	char preDecodeStr4[BUFF_SIZE] = "FLCL";
	char preDecodeStr5[BUFF_SIZE] = "GOODBYE!!!!";
	char * preDecodeStr6 = NULL;
	int key = 0;

	// data sizes
	int data1 = 0;
	int data2 = 0;
	int data3 = 0;
	int data4 = 0;
	int data5 = 0;
	int data6 = 0;

	// tracking
	int autoDecodeTestsPassed = 0;
	int autoDecodeTestsRun = 0;
	


	data1 = strlen(preDecodeStr1);
	// Set 1
	key = 69;
	for (int i = 0; i < data1; i++)
	{
		preDecodeStr1[i] = preDecodeStr1[i] ^ key;
	}
	data2 = strlen(preDecodeStr2);

	for (int i = 0; i < data2; i++)
	{
		preDecodeStr2[i] = preDecodeStr2[i] ^ key;
	}

	data3 = strlen(preDecodeStr3);
	for (int i = 0; i < data3; i++)
	{
		preDecodeStr3[i] = preDecodeStr3[i] ^ key;
	}

	data4 = strlen(preDecodeStr4);
	for (int i = 0; i < data4; i++)
	{
		preDecodeStr4[i] = preDecodeStr4[i] ^ key;
	}

	data5 = strlen(preDecodeStr5);
	for (int i = 0; i < data5; i++)
	{
		preDecodeStr5[i] = preDecodeStr5[i] ^ key;
	}

	char * preDecoderTestArray[] = { preDecodeStr1, preDecodeStr2, preDecodeStr3, preDecodeStr4, preDecodeStr5, preDecodeStr6 };
	int * dataArray[] = { data1, data2, data3, data4, data5, data6 };


	const char autoDecodeString1[BUFF_SIZE] = { "Hello World" };
	const char autoDecodeString2[BUFF_SIZE] = { "This is a test!" };
	const char autoDecodeString3[BUFF_SIZE] = { "BAKA" };
	const char autoDecodeString4[BUFF_SIZE] = { "FLCL" };
	const char autoDecodeString5[BUFF_SIZE] = { "GOODBYE!!!!" };
	const char * autoDecodeString6 = NULL;

	const char * autoDecodeRunTest[] = { autoDecodeString1, autoDecodeString2, autoDecodeString3, autoDecodeString4, autoDecodeString5, autoDecodeString6 };


	/* EXPECTED RETURN VALUES */
	const int autoDecodeReturnValues[] = { 11, 15, 4, 4, 11, -1 };

	printf("\n***********************\n");
	printf("TESTING DECODER\n");
	printf("***********************\n");

	int tempReturn = 0;

	for (i = 0; i < (sizeof(preDecoderTestArray) / sizeof(preDecoderTestArray[0])); i++)
	{
		printf("TEST #%d\n\n", i + 1);

		printf("Input String:        %s\n", preDecoderTestArray[i]);
			
		// run function
		tempReturn = decode_string(preDecoderTestArray[i], key, dataArray[i]);

		// check return
		if (tempReturn == autoDecodeReturnValues[i])
		{
			printf("Return Value:        PASS\n");
			autoDecodeTestsPassed++;
			autoDecodeTestsRun++;
		}
		else
		{
			printf("Return Value:        FAIL\n");
			printf("Return Value:        %d\n", tempReturn);
			autoDecodeTestsRun++;
		}

		if (preDecoderTestArray[i])
		{
			// output string
			printf("Output String:       %s\n", preDecoderTestArray[i]);

			if (strcmp(autoDecodeRunTest[i], preDecoderTestArray[i]) == 0)
			{
				printf("String Test:         PASS\n");
				autoDecodeTestsPassed++;
				autoDecodeTestsRun++;
			}
			else
			{
				printf("String Test:         FAIL\n");
				autoDecodeTestsRun++;
			}
		}
		else
		{
			printf("Output String:       N/A NULL\n");
			printf("String Test:         N/A NULL\n");
			autoDecodeTestsPassed++;
			autoDecodeTestsRun++;
		}
		printf("\n");
		


	}



	printf("%d tests were run on decode_string() \n%d tests were passed.\n", autoDecodeTestsRun, autoDecodeTestsPassed);

	totalUnitTestsRun += autoDecodeTestsRun;
	totalUnitTestsPassed += autoDecodeTestsPassed;


#endif

#ifdef AUTO_FULL_PROGRAM

	const char autoFullProgramTest1[BUFF_SIZE] = { "This is a test string." };
	const char autoFullProgramTest2[BUFF_SIZE] = { "Test." };
	const char autoFullProgramTest3[BUFF_SIZE] = { "1" };
	const char autoFullProgramTest4[BUFF_SIZE] = { "!@#$%^&*()_+-=" };
	const char autoFullProgramTest5[BUFF_SIZE] = { "0" };
	const char autoFullProgramTest6[BUFF_SIZE] = { "I.3. I declare a thumb war!" };
	const char * autoFullProgramTest7 = NULL;
	char autoFullProgramTest8[BUFF_SIZE] = { "Real string? Hidden string!" };
	autoFullProgramTest8[12] = 0;

	const char * autoFullProgramTestArray[] = { autoFullProgramTest1, autoFullProgramTest2, autoFullProgramTest3, autoFullProgramTest4, autoFullProgramTest5, autoFullProgramTest6, autoFullProgramTest7, autoFullProgramTest8 };

	const int autoFullProgramRemoveNonLetterReturnValues[] = { 5, 1, 1, 14, 1, 10, -1, 2 };
	const int autoFullProgramClearBufferReturnValues[] = { 0, 0, 0, 0, 0, 0, -1, 0 };

	const char autoFullProgramResult1[BUFF_SIZE] = { "gnirtstsetasisihT" };
	const char autoFullProgramResult2[BUFF_SIZE] = { "tseT" };
	const char autoFullProgramResult3[BUFF_SIZE] = { 0 };
	const char autoFullProgramResult4[BUFF_SIZE] = { 0 };
	const char autoFullProgramResult5[BUFF_SIZE] = { 0 };
	const char autoFullProgramResult6[BUFF_SIZE] = { "rawbmuhtaeralcedII" };
	const char * autoFullProgramResult7 = NULL;
	char autoFullProgramResult8[BUFF_SIZE] = { "gnirtslaeR" };

	const char * autoFullProgramResultArray[] = { autoFullProgramResult1, autoFullProgramResult2, autoFullProgramResult3, autoFullProgramResult4, autoFullProgramResult5, autoFullProgramResult6, autoFullProgramResult7, autoFullProgramResult8 };

	int autoFullProgramTestsPassed = 0;
	int autoFullProgramTestsRun = 0;
	//	int tempReturnValue = 0;

	printf("\n*************************\n");
	printf("TESTING ALL FUNCTIONALITY\n");
	printf("*************************\n");

	for (i = 0; i < (sizeof(autoFullProgramTestArray) / sizeof(autoFullProgramTestArray[0])); i++)
	{
		printf("TEST #%d\n", i + 1);

		/* Testing remove_non_letters() return value */

		printf("\tInput String:\t\t\t\t");

		autoFullProgramTestsRun++;
		totalUnitTestsRun++;

		if (autoFullProgramTestArray[i])
		{
			puts(autoFullProgramTestArray[i]);
			strcpy(sourceString, autoFullProgramTestArray[i]);
			tempReturnValue = reverse_case(autoReverseCharStrings[i], destinationBuff, reversePos[i]);
		}
		else
		{
			printf("NULL\n");
			*sourceString = NULL;
			tempReturnValue = reverse_case(NULL, NULL, NULL);
		}

		printf("\tRemove Non-Letters Return Value:\t");
		if (tempReturnValue == autoFullProgramRemoveNonLetterReturnValues[i])
		{
			printf("PASS\n");
			autoFullProgramTestsPassed++;
			totalUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}

		/* Testing clear_a_buffer() return values */
		/* NOTE:  Not yet testing the -2 return value */
		printf("\tClear A Buffer Return Value:\t\t");
		autoFullProgramTestsRun++;
		totalUnitTestsRun++;
		if (autoFullProgramTestArray[i])
		{
			tempReturnValue = clear_a_buffer(destinationBuff, BUFF_SIZE);
		}
		else
		{
			tempReturnValue = clear_a_buffer(NULL, BUFF_SIZE);
		}

		if (tempReturnValue == autoFullProgramClearBufferReturnValues[i])
		{
			printf("PASS\n");
			autoFullProgramTestsPassed++;
			totalUnitTestsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}

		/* Testing reverse_string return value */
		tempReturnValue = reverse_string(sourceString, destinationBuff, 0);
		printf("\tOutput String:\t\t\t\t");
		puts(destinationBuff);
	}




	printf("%d tests were run on the entire header. \n%d tests were passed.\n", autoFullProgramTestsRun, autoFullProgramTestsPassed);

#endif

#ifdef MANUAL_FULL_PROGRAM


	int originalStringLength = 0;
	int numCharsRemoved = 0;
	int buffClearReturnValue = 0;
	int numCharsReversed = 0;
	int sourceStringLen = 0;
	int testStringPosition = 0;
	char testBuff[BUFF_SIZE] = { 0 };
	int compareResultToExpectedOutput = 0;

	printf("\n\nEnter a string.  Any newline characters will be removed. \nThis program will attempt to invoke the EnglishFunction header functions to: \n");
	printf("\t1. Remove any non-alphabet characters (in place) \n\t2. Clear the destination buffer (for safety) \n");
	printf("\t3. Reverse the alphabet characters into the destination buffer. \n\n");

	fgets(sourceString, BUFF_SIZE, stdin);
	for (i = 0; i < BUFF_SIZE; i++)
	{
		if (10 == sourceString[i])
		{
			sourceString[i] = 0;
			break;
		}
	}

	printf("\n**********************************\n");
	printf("MANUALLY TESTING ALL FUNCTIONALITY\n");
	printf("**********************************\n");

	printf("Original string: \t\t\t%s\n", sourceString);
	numCharsRemoved = reverse_case(autoReverseCharStrings[i], destinationBuff, reversePos[i]);
	printf("Number of characters removed: \t\t%d\n", numCharsRemoved);
	buffClearReturnValue = clear_a_buffer(destinationBuff, BUFF_SIZE);
	tempCount = 0;
	for (i = 0; i < BUFF_SIZE; i++)
	{
		if (destinationBuff[i] != 0)
		{
			tempCount++;
		}
	}
	printf("Destination buffer cleared? \n\tReturn Value:\t%d \n\tReality:\t", tempReturnValue);
	if (0 == buffClearReturnValue && 0 == tempCount)
	{
		printf("Yes\n");
	}
	else
	{
		printf("NO\n");
	}

	numCharsReversed = reverse_string(sourceString, destinationBuff, 0);

	printf("Number of characters reversed: \n\tReturn Value:\t%d \n\tReality:\t%d\n", numCharsReversed, strlen(destinationBuff));

	printf("Modified string:\t\t\t%s\n", destinationBuff);

	sourceStringLen = strlen(sourceString);
	testStringPosition = sourceStringLen - 1;

	for (i = 0; i < sourceStringLen; i++)
	{
		testBuff[testStringPosition] = sourceString[i];
		testStringPosition--;
	}
	compareResultToExpectedOutput = strcmp(destinationBuff, testBuff);

	printf("String properly reversed?\t\t");
	if (compareResultToExpectedOutput)
	{
		printf("NO\n");
	}
	else
	{
		printf("Yes\n");
	}

#endif

	if (totalUnitTestsRun > 0)
	{
		printf("\n\nA total of %d automatic tests were run:  \n%d tests passed.\n", totalUnitTestsRun, totalUnitTestsPassed);
	}
	else
	{
#ifndef MANUAL_FULL_PROGRAM
		printf("\nDid you forget to uncomment at least one of the #define'd tests?\n");
#endif
	}

	getchar();
	getchar();

	return 0;
}
