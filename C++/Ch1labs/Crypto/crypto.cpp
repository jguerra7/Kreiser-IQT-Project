/*
	Name: Will Kreiser
	Date: 9 Aug 18
	Project: Crypto
*/

/* 
					BONUS LAB : CPP_CRYPTOGRAHAM CRACKER
objective : Design a CPP program that will encode user input.
requirements : print user input as both plain text and CODED.output to FILE!.alpha numeric only(a - z, A - Z, 0 - 9)
*/
#include "shared_functions.h"

int main()
{
	std::string message;
	int i, key;
	std::string encrypted_message;
	std::string decrypted_message;

	std::cout << "Enter a message to encrypt: ";
	std::getline(std::cin, message);
	std::cout << "Enter key: ";
	std::cin >> key;

	encrypted_message = encode_string(message, key);
	decode_string(encrypted_message, key);	

	getchar(); getchar();
	return 0;
}