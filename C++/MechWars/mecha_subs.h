#pragma once
#include "weapon.h"
#include "mecha.h"

class StormWind : public Mecha
{
public:
	// Default Constructor
	StormWind() {
		mechaName = "Storm Wind";
		type = "Storm Wind";
		hitPoints = 2000;
		power = 200;
		doubleHit = 0;	
		critical = 10;	
		setWeapons();
	}
	// Constructor
	StormWind(std::string mn) {
		StormWind();
		mechaName = mn;
	}
	void setWeapons() override
	{
		laserCannon LC;
		weaponSet.push_back(LC);
		weaponSet.push_back(LC);
		autoLaser AR;
		weaponSet.push_back(AR);
		weaponSet.push_back(AR);
	}
};

class Juggernaut : public Mecha
{
public:
	// Default Constructor
	Juggernaut() {
		mechaName = "Juggernaut";
		type = "Juggernaut";
		hitPoints = 3500;
		power = 300;
		doubleHit = 0;
		critical = 15;
		setWeapons();
	}
	// Constructor
	Juggernaut(std::string mn) {
		Juggernaut();
		mechaName = mn;
	}
	void setWeapons() override
	{
		rocketLauncher RL;
		weaponSet.push_back(RL);
		weaponSet.push_back(RL);
		autoRifle AR;
		weaponSet.push_back(AR);
		weaponSet.push_back(AR);
	}
};

class Knight : public Mecha
{
public:
	// Default Constructor
	Knight() {
		mechaName = "Arturias";
		type = "Knight";
		hitPoints = 2000;
		power = 300;
		doubleHit = 15;
		critical = 20;
		setWeapons();
	}
	// Constructor
	Knight(std::string mn) {
		Juggernaut();
		mechaName = mn;
	}
	void setWeapons() override
	{
		sword SW;
		weaponSet.push_back(SW);
		weaponSet.push_back(SW);
		autoLaser AL;
		weaponSet.push_back(AL);
		weaponSet.push_back(AL);
	}
};

class Firebat : public Mecha
{
public:
	int heatWave;
	// Default Constructor
	Firebat() {
		mechaName = "Firebat";
		type = "Soldier";
		hitPoints = 2000;
		power = 300;
		doubleHit = 0;
		afterburn = 10;	//will double damage if it hits
		critical = 20;
		setWeapons();
	}
	// Constructor
	Firebat(std::string mn) {
		Firebat();
		mechaName = mn;
	}
	void setWeapons() override
	{
		flamethrower FT;
		weaponSet.push_back(FT);
		weaponSet.push_back(FT);
		heatSeek HS;
		weaponSet.push_back(HS);
		weaponSet.push_back(HS);
	}
};

class Boxer : public Mecha
{
public:
	// Default Constructor
	Boxer() {
		mechaName = "Muhammed Ali";
		type = "Boxer";
		hitPoints = 1500;
		power = 300;
		doubleHit = 75;
		critical = 30;
		setWeapons();
	}
	// Constructor
	Boxer(std::string mn) {
		Boxer();
		mechaName = mn;
	}
	void setWeapons() override
	{
		hammerFist HF;
		weaponSet.push_back(HF);
		weaponSet.push_back(HF);
	}
};

class Ninja : public Mecha
{
public:
	// Default Constructor
	Ninja() {
		mechaName = "Shinobi";
		type = "Assassin";
		hitPoints = 1000;
		power = 300;
		doubleHit = 50;
		critical = 20;
		setWeapons();
	}
	// Constructor
	Ninja(std::string mn) {
		Ninja();
		mechaName = mn;
	}
	void setWeapons() override
	{
		katana KT;
		weaponSet.push_back(KT);
		ninjaStars NS;
		weaponSet.push_back(NS);
	}
};



