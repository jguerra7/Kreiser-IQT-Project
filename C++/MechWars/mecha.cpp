#include "mecha.h"
#include "mecha_subs.h"

int main() {

	Mecha *player1, *player2;
	int currentPlayer;
	player1 = mecha_stats_display(1);
	player2 = mecha_stats_display(2);
	bool gameOver = false;
	
	//Game play continue until someone wins
	while (!gameOver)
	{
		//If the player's mech is overheated, then that player doesn't have a turn
		if (currentPlayer ? player1->isOverHeated() : mech2_ptr->isOverHeated())
		{
			std::cout << "Your mech is overheated. You have to wait a turn." << std::endl;
			player ? mech1_ptr->switchHeatState() : mech2_ptr->switchHeatState();
		}
		else
		{
			int weaponChoice = 0;
			int damage = 0;
			std::cout << "Player " << (player ? 1 : 2) << ", select which weapon to use: " << std::endl;
			//Displays the weapon available to player, uses a ternary operator to determine which player's loadout to display
			player ? mech1_ptr->display_stats() : mech2_ptr->display_stats();
			do
			{
				//Handles user input, if not a number, send back as invalid
				weaponChoice = userInput(weaponChoice);
				//If not is range of the mech number, send back as invalid
				if (!(weaponChoice > 0 && weaponChoice < (player ? mech1_ptr->getWeapons().size() + 1 : mech2_ptr->getWeapons().size() + 1)))
				{
					std::cout << "Invalid number, please try again" << std::endl;
				}
				//Continue loop until user makes a valid choice
			} while (!(weaponChoice > 0 && weaponChoice < (player ? mech1_ptr->getWeapons().size() + 1 : mech2_ptr->getWeapons().size() + 1)));
			//Pull damage from the player's mech
			damage = player ? mech1_ptr->releasePayload(weaponChoice - 1) : mech2_ptr->releasePayload(weaponChoice - 1);
			//Subtract the damage from the other player's mech's health and see if that mech is destroyed
			gameOver = player ? mech2_ptr->computeDamageReceived(damage) : mech1_ptr->computeDamageReceived(damage);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//If either mech is down, end match
			if (gameOver)
			{
				break;
			}
		}
		//Switch to other player
		player = !player;
	}
	std::cout << "The match has finished!" << std::endl;
	std::cout << "Player " << (player ? 1 : 2) << " has defeated his enemy!" << std::endl << std::endl << std::endl;
	getchar();
	getchar();

	return 0;
}