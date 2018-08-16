#include "mecha.h"
#include "mecha_subs.h"
#include <sstream>
#include <thread>	// std::this_thread::sleep_for
#include <chrono>	// std::chrono::seconds

int get_int_input();

Ninja NJ;
Boxer BX;
Firebat FB;
Knight KT;
Juggernaut JG;
StormWind SW;
Mecha *player1_mecha;
Mecha *player2_mecha;

void mecha_stats_display(int num)
{
	//Choice and selection variables
	int mechaStats = 1;
	int mechaChoice = 0;
	int mechaSelected = 0;
	do
	{
		std::cout << "\nWelcome to Mecha Wars." << std::endl;
		std::cout << "MECHA STATS MENU" << std::endl;
		std::cout << "1 - Firebat\n2 - Muhammed Ali\n3 - Arturias\n4 - Shinobi\n5 - Juggernaut\n6 - Storm Wind\n" << std::endl;
		std::cout << "Select a number to display the stats";
		mechaStats = get_int_input();

		switch (mechaStats)
		{
		case 1:	//1 - Firebat
			FB.display_stats();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Would you like to pilot this Mecha? (1 for Yes, 2 for No) ";
			mechaChoice = get_int_input();
			if (mechaChoice == 1 && num == 1) {
				player1_mecha = (Firebat *)&FB;
				mechaSelected = 1;
			}
			else if (mechaChoice == 1 && num == 2) {
				player2_mecha = (Firebat *)&FB;
				mechaSelected = 1;
			}
			else {
				mechaSelected = 0;
				mechaChoice = 0;
				break;
			}
		case 2:	//2 - Ali
			BX.display_stats();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Would you like to pilot this Mecha? (1 for Yes and 2 for No) ";
			mechaChoice = get_int_input();
			if (mechaChoice == 1 && num == 1) {
				player1_mecha = (Boxer *)&BX;
				mechaSelected = 1;
			}
			else if (mechaChoice == 1 && num == 2) {
				player2_mecha = (Boxer *)&BX;
				mechaSelected = 1;
			}
			else {
				mechaSelected = 0;
				mechaChoice = 0;
				break;
			}
		case 3:	//3 - Arturias
			KT.display_stats();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Would you like to pilot this Mecha? (1 for Yes and 2 for No) ";
			mechaChoice = get_int_input();
			if (mechaChoice == 1 && num == 1) {
				player1_mecha = (Knight *)&KT;
				mechaSelected = 1;
			}
			else if (mechaChoice == 1 && num == 2) {
				player2_mecha = (Knight *)&KT;
				mechaSelected = 1;
			}
			else {
				mechaSelected = 0;
				mechaChoice = 0;
				break;
			}
		case 4:	//4 - Shinobi
			NJ.display_stats();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Would you like to pilot this Mecha? (1 for Yes and 2 for No) ";
			mechaChoice = get_int_input();
			if (mechaChoice == 1 && num == 1) {
				player1_mecha = (Ninja *)&NJ;
				mechaSelected = 1;
			}
			else if (mechaChoice == 1 && num == 2) {
				player2_mecha = (Ninja *)&NJ;
				mechaSelected = 1;
			}
			else {
				mechaSelected = 0;
				mechaChoice = 0;
				break;
			}
		case 5:	//5 - Juggernaut
			JG.display_stats();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Would you like to pilot this Mecha? (1 for Yes and 2 for No) ";
			mechaChoice = get_int_input();
			if (mechaChoice == 1 && num == 1) {
				player1_mecha = (Juggernaut *)&JG;
				mechaSelected = 1;
			}
			else if (mechaChoice == 1 && num == 2) {
				player2_mecha = (Juggernaut *)&JG;
				mechaSelected = 1;
			}
			else {
				mechaSelected = 0;
				mechaChoice = 0;
				break;
			}
		case 6:	//6 - Storm
			SW.display_stats();
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Would you like to pilot this Mecha? (1 for Yes and 2 for No) ";
			mechaChoice = get_int_input();
			if (mechaChoice == 1 && num == 1) {
				player1_mecha = (StormWind *)&SW;
				mechaSelected = 1;
			}
			else if (mechaChoice == 1 && num == 2) {
				player2_mecha = (StormWind *)&SW;
				mechaSelected = 1;
			}
			else {
				mechaSelected = 0;
				mechaChoice = 0;
				break;
			}
		default:
			break;
		}
	} while (mechaSelected == 0);	//Once a mecha is selected exit the loop
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