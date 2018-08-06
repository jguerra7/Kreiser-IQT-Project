/*
	Name: Will Kreiser
	Date: 6 Aug 18
	Project: Performance Lab 15
*/

#include <assert.h>     

#include <stdlib.h>    
#include <stdio.h>      

int main(void)
{
	char myArray[256] = { 0 }; //zeroized char array

	//read a string
	printf("Enter whatever you want: ");
	fgets(myArray, 256, stdin);

	//assert that the string is nul terminated
	assert(myArray[255] == '\0');
	//print the string
	puts(myArray);

	//And now we break it

	char myBrokenArray[64] = { 0 }; //zeroized char array
	printf("Enter whatever you want: ");
	fgets(myBrokenArray, 512, stdin);

	//assert that the string is nul terminated
	assert(myBrokenArray[63] == '\0');
	//print the string
	puts(myBrokenArray);

	return 0;
}
