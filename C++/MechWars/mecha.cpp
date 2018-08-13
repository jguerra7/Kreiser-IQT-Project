#include "mecha.h"
#include "mecha_subs.h"

int main() {

	int weaponChoice = 0;
	// These are the available weapon classes to choose from
	Weapon flameThrower();
	Weapon rocketLauncher;
	Weapon laserCannon;
	Weapon hammerFist;
	Weapon katana;
	
	//Temp variables used to capture user input
	std::string weaponName;
	std::string weaponType;
	int damage;					// How much damage this weapon does
	int cost;					// Cost to use weapon on turn

	std::cout << "__       __  ________   ______   __    __   ______         __       __   ______   _______    ______";
	std::cout << "/  \     /  |/        | /      \ /  |  /  | /      \       /  |  _  /  | /      \ /       \  /      \\"; 
	std::cout << "$$  \   /$$ |$$$$$$$$/ /$$$$$$  |$$ |  $$ |/$$$$$$  |      $$ | / \ $$ |/$$$$$$  |$$$$$$$  |/$$$$$$  |";
	std::cout << "$$$  \ /$$$ |$$ |__    $$ |  $$/ $$ |__$$ |$$ |__$$ |      $$ |/$  \$$ |$$ |__$$ |$$ |__$$ |$$ \__$$/";
	std::cout << "$$$$  /$$$$ |$$    |   $$ |      $$    $$ |$$    $$ |      $$ /$$$  $$ |$$    $$ |$$    $$< $$      \\"; 
	std::cout << "$$ $$ $$/$$ |$$$$$/    $$ |   __ $$$$$$$$ |$$$$$$$$ |      $$ $$/$$ $$ |$$$$$$$$ |$$$$$$$  | $$$$$$  |";
	std::cout << "$$ |$$$/ $$ |$$ |_____ $$ \__/  |$$ |  $$ |$$ |  $$ |      $$$$/  $$$$ |$$ |  $$ |$$ |  $$ |/  \__$$ |";
	std::cout << "$$ | $/  $$ |$$       |$$    $$/ $$ |  $$ |$$ |  $$ |      $$$/    $$$ |$$ |  $$ |$$ |  $$ |$$    $$/";
	std::cout << "$$/      $$/ $$$$$$$$/  $$$$$$/  $$/   $$/ $$/   $$/       $$/      $$/ $$/   $$/ $$/   $$/  $$$$$$/";
      
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