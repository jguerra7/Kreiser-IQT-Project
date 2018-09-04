/*
Name: Will Kreiser
Date: 6 Aug 18
Project: PL 15C
*/

#ifndef _DEBUG
#define NDEBUG
#endif
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


//#define STEP1

#define BUFF_SIZE 16
void error_reporting(int currErrno);

int main(void)
{
	int currentErrno = 0;
	char sampleArray[BUFF_SIZE] = { 0 };


	char * inputString = (char *)calloc(BUFF_SIZE, sizeof(sampleArray));	//This is automatically null-terminated because of calloc()

	if (!sampleArray) {	//using ERRNO to check for NULL
		currentErrno = errno;
		error_reporting(currentErrno);
	}
	else {	//using assert() to check for NULL
		assert(sampleArray);
	}		
	if (sampleArray){
		fgets(sampleArray, BUFF_SIZE, stdin);
		assert(sampleArray[BUFF_SIZE - 1] == '\0');
		puts(sampleArray);
	}
	free(inputString);

	getchar(); getchar();
	return 0;
}

void error_reporting(int currErrno)
{
	if (currErrno){
		perror("Error");
	}
	return;
}