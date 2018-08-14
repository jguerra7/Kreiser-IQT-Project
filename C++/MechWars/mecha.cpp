#include "mecha.h"
#include "mecha_subs.h"
#include <sstream>
#include <thread>	// std::this_thread::sleep_for
#include <chrono>	// std::chrono::seconds

std::string get_string_input();
int get_int_input();

int main() {

	int primaryWeapon = 99;
	int secondaryWeapon = 0;
	std::string weaponName, weaponType;
	int damage, cost;

	Weapon flameThrower;
	Weapon rocketLauncher;
	Weapon laserCannon;
	Weapon hammerFist;
	Weapon katanaShield; 

	// These are the available weapon classes to choose from
	std::cout << "Welcome to Mecha Wars." << std::endl;
	std::cout << "Please select from the following primary weapons." << std::endl;
	std::cout << "1 - Flamethrower\n2 - Rocket Launcher\n3 - Laser Cannon\n4 - Hammer Fists\n5 - Sword and Shield\n6 - Change Weapon\n7 - Continue" << std::endl;
	primaryWeapon = get_int_input();
	//TODO: The selection needs to present the weapon stats prior to moving to secondary weapons.
	do
	{
		switch (primaryWeapon)
		{
		case 1:	
			//TODO: Flamethrower can be dual wielded with Rocket Launcher or another Flamethrower

			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		case 2:
			//TODO: Rocket Launcher can be dual wielded with Flamethrower or another Rocket Launcher

			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		case 3:
			//TODO: Laser Cannon requires both hands for use and cannot be dual wielded

			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		case 4:
			//TODO: Hammer Fists will be installed on both hands and replace both left and right weapons

			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		case 5:
			//TODO: Sword and shield will be wielded in separate hands and replace left and right weapons.

			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		case 6:
			//TODO: This case will allow the user to change their weapon selection
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		case 7:
			std::cout << "Entering secondary weapon selection phase..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		default:
			break;

		}
	} while (primaryWeapon == 99);// once a different primary weapon is selected the do-while loop will break
		
	// TODO: Create your sub mechs here
	// Ensure you also pass your weapons to your mechs... you can do this via on sub mech creation or through a setter method
	// Don't overthink this one either... reference course and example if needed. 


	// Now we can do our main logic
	// This is where our game gets programmed
	// Have fun here 
	// Don't get stuck on requirments... just do it!

	getchar();
	getchar();

	return 0;
}

int get_int_input()
{
	int number = 0;
	std::string input = "";
	while (true)
	{
		std::cout << ": ";
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> number)
			break;
		std::cout << "Invalid number, please try again" << std::endl;
	}
	return number;
}