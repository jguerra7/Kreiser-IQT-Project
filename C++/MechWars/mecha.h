#pragma once
#include <chrono>	// std::chrono::seconds
#include <iostream>
#include <sstream>
#include <string>
#include <thread>	// std::this_thread::sleep_for
#include <vector>

#include "weapon.h"

//This function will display all of the mecha sub class stats before the user selects
int mecha_stats_display();
// TODO: You will need to inherit your mecha from the class Mecha first... be sure to override the functions needed.

// Base Classes
class Mecha {
protected:
	// Strings
	std::vector<Weapon> weaponSet;
	std::string mechaName;
	std::string type;
	// Ints
	int hitPoints;// indicates total health remaining
	int power; // indicates power per turn... this value should never be modified after it's set.
	//The following variables allow for differing levels of attack capabilities

	int doubleHit;	//For use with Boxer mech, allows for chance of double hit to combat low health and lower damage of weapons on boxer
	int afterburn; //For use with Firebat mech, allows for double damage due to serious burn.
	int critical;	//30% chance to do bonus damage
public:
	Mecha() {}
	// You will want to either override this function to add weapon and specific stats... or just utilize it as is and create a new method inside your sub mecha
	virtual void display_main_stats() {
		std::cout << "Model: " << mechaName << std::endl;
		std::cout << "Hit Points: " << hitPoints << std::endl;
		std::cout << "Power: " << power << std::endl;
	}
	//Loads the various weapons into weaponset
	virtual void setWeapons() {}
	//Return list of weapons of the mech'
	//Return list of weapons of the mech'
	virtual std::vector<Weapon> getWeapons()
	{
		return weaponSet;
	}
	//Basic method to inflict damage on the mech from the opponent
	//Will return false upon a successful hit (mech got hit, but wasn't destroyed)
	//Will return 1 to indicate a dead mech
	virtual bool computeDamageReceived(int damagePts) {

		if ((hitPoints - damagePts) < 0)
		{
			return true;
		}
		else
		{
			hitPoints = (hitPoints - damagePts);
			return false;
		}
	}
	//Might remove this
	virtual int getHP() {
		return hitPoints;
	}
	//Displays basic stats, but also the loadout for the mech
	virtual void display_stats() {
		std::cout << "Displaying Stats" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====" << std::endl;
		int slot = 1;
		for (auto& item : weaponSet)
		{
			if (item.getName() == "Close Range Flamethrower")
			{
				flamethrower stats;
				std::cout << "(" << slot << ")" << std::endl;
				stats.display_weapon_stats();
			}
			else if (item.getName() == "Rocket Launcher")
			{
				rocketLauncher stats;
				std::cout << "(" << slot << ")" << std::endl;
				stats.display_weapon_stats();
			}
			else if (item.getName() == "Laser Cannon")
			{
				laserCannon stats;
				std::cout << "(" << slot << ")" << std::endl;
				stats.display_weapon_stats();
			}
			else if (item.getName() == "Hammer Fist")
			{
				hammerFist stats;
				std::cout << "(" << slot << ")" << std::endl;
				stats.display_weapon_stats();
			}
			else if (item.getName() == "Master Sword")
			{
				sword stats;
				std::cout << "(" << slot << ")" << std::endl;
				stats.display_weapon_stats();
			}
			else if (item.getName() == "Muramasa")
			{
				katana stats;
				std::cout << "(" << slot << ")" << std::endl;
				stats.display_weapon_stats();
			}
			else
			{
				std::cout << "(" << slot << ")" << std::endl;
				item.display_weapon_stats();
			}
			slot++;
		}
		std::cout << std::endl << std::endl;
	}

};

