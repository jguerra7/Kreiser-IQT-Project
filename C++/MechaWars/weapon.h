#pragma once
#include <string>
#include <iostream>

/*
This one is already built for you... feel free to add to it.
Utilize the damage in either a method (pref in mecha_sub) or main() to determine how muchh damage you do on an enemy mech
Ensure power is being subtracted by cost after every action. Prevent action if power is too low for action (this can be done via method (pref in mecha sub)  or main)
*/
class Weapon {
protected:
	std::string weaponName;
	int damage;					// How much damage this weapon does
	int powerCost;					// Cost to use weapon on turn
public:
	Weapon() {}
	Weapon(std::string name, std::string type, int dmg, int ct) {
		weaponName = name;
		damage = dmg;
		powerCost = ct;
	}
	int getCost()
	{
		return powerCost;
	}
	std::string getName()
	{
		return weaponName;
	}
	virtual int fireWeapon()
	{
		
		std::cout << "Dealt " << damage << " damage " << "with " << weaponName << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return damage;
	}
	virtual void display_weapon_stats() {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Cost: " << powerCost << std::endl;
	}
};
//Main Weapons
class flamethrower : public Weapon {
public:
	flamethrower()
	{
		weaponName = "Close Range Flamethrower";
		damage = 100;
		powerCost = 30;
	}
};

class rocketLauncher : public Weapon {
public:
	rocketLauncher()
	{
		weaponName = "Rocket Launcher";
		damage = 75;
		powerCost = 10;
	}
};

class laserCannon : public Weapon {
public:
	laserCannon()
	{
		weaponName = "Laser Cannon";
		damage = 300;
		powerCost = 50;
	}
};

class hammerFist : public Weapon {
public:
	hammerFist()
	{
		weaponName = "Hammer Fist";
		damage = 50;
		powerCost = 10;
	}
};

class sword : public Weapon {
public:
	sword()
	{
		weaponName = "Master Sword";
		damage = 100;
		powerCost = 25;
	}
};

class katana : public Weapon {
public:
	katana()
	{
		weaponName = "Muramasa";
		damage = 150;
		powerCost = 50;
	}
};

//Secondary weapons
class heatSeek : public Weapon {
public:
	heatSeek()
	{
		weaponName = "Heat Seeking Missles";
		damage = 35;
		powerCost = 10;
	}
};

class autoLaser : public Weapon {
public:
	autoLaser()
	{
		weaponName = "Auto Laser";
		damage = 50;
		powerCost = 15;
	}
};

class autoRifle : public Weapon {
public:
	autoRifle()
	{
		weaponName = "Auto Rifle";
		damage = 20;
		powerCost = 5;
	}
};

class ninjaStars : public Weapon {
public:
	ninjaStars()
	{
		weaponName = "Ninja Stars";
		damage = 25;
		powerCost = 5;
	}
};