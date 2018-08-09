#include "shared_functions.h"


int encode_string(std::string message, int key)
{
	char change_point;
	
	for (int i = 0; message[i] != '\0'; ++i) {
		change_point = message[i];

		if (change_point >= 'a' && change_point <= 'z') {
			change_point = change_point + key;

			if (change_point > 'z') {
				change_point = change_point - 'z' + 'a' - 1;
			}

			message[i] = change_point;
		}
		else if (change_point >= 'A' && change_point <= 'Z') {
			change_point = change_point + key;

			if (change_point > 'Z') {
				change_point = change_point - 'Z' + 'A' - 1;
			}

			message[i] = change_point;
		}
		else if (change_point >= 0 || change_point <= 9)
		{
			change_point = change_point + key;

				if (change_point > 9) {
					change_point = change_point - 10;
				}

				message[i] = change_point;
		}			
	}

	std::cout << "Encrypted message: " << message << std::endl;
	return message;
}
