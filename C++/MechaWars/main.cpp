#include "mecha.h"
#include "mecha_subs.h"

int main()
{
	Mecha player1;
	Mecha player2;

	std::cout << "Entering Mecha Selection phase for player 1." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
	mecha_stats_display(player1, 1);

	std::cout << "Entering Mecha Selection phase for player 2." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
	mecha_stats_display(player2, 2);
	system("cls");

	bool gameOver = false;
	bool player = true;
	//Game play continue until someone wins
	while (!gameOver)
	{
		system("cls");
		std::cout << R"( __       __  ________   ______   __    __   ______         __       __   ______   _______    ______
/  \     /  |/        | /      \ /  |  /  | /      \       /  |  _  /  | /      \ /       \  /      \ 
$$  \   /$$ |$$$$$$$$/ /$$$$$$  |$$ |  $$ |/$$$$$$  |      $$ | / \ $$ |/$$$$$$  |$$$$$$$  |/$$$$$$  |
$$$  \ /$$$ |$$ |__    $$ |  $$/ $$ |__$$ |$$ |__$$ |      $$ |/$  \$$ |$$ |__$$ |$$ |__$$ |$$ \__$$/ 
$$$$  /$$$$ |$$    |   $$ |      $$    $$ |$$    $$ |      $$ /$$$  $$ |$$    $$ |$$    $$< $$      \ 
$$ $$ $$/$$ |$$$$$/    $$ |   __ $$$$$$$$ |$$$$$$$$ |      $$ $$/$$ $$ |$$$$$$$$ |$$$$$$$  | $$$$$$  |
$$ |$$$/ $$ |$$ |_____ $$ \__/  |$$ |  $$ |$$ |  $$ |      $$$$/  $$$$ |$$ |  $$ |$$ |  $$ |/  \__$$ |
$$ | $/  $$ |$$       |$$    $$/ $$ |  $$ |$$ |  $$ |      $$$/    $$$ |$$ |  $$ |$$ |  $$ |$$    $$/ 
$$/      $$/ $$$$$$$$/  $$$$$$/  $$/   $$/ $$/   $$/       $$/      $$/ $$/   $$/ $$/   $$/  $$$$$$/ 
)";
		//If the player's mech is out of power, then that player doesn't have a turn
		if (player ? player1.needsRecharging() : player2.needsRecharging())
		{
			std::cout << "Your mech is out of power." << std::endl;
			player ? player1.rechargeOff() : player2.rechargeOff();
		}
		else
		{
			int weaponChoice = 0;
			int damage = 0;
			std::cout << "\nPlayer " << (player ? 1 : 2) << ", select which weapon to use: " << std::endl;
			//Displays the weapon available to player, uses a ternary operator to determine which player's loadout to display
			player ? player1.display_stats() : player2.display_stats();
			do
			{
				//Handles user input, if not a number, send back as invalid
				weaponChoice = get_int_input();
				//If not is range of the mech number, send back as invalid
				if (!(weaponChoice > 0 && weaponChoice < (player ? player1.getWeapons().size() + 1 : player2.getWeapons().size() + 1)))
				{
					std::cout << "Invalid number, please try again" << std::endl;
				}
				//Continue loop until user makes a valid choice
			} while (!(weaponChoice > 0 && weaponChoice < (player ? player1.getWeapons().size() + 1 : player2.getWeapons().size() + 1)));
			//Pull damage from the player's mech
			damage = player ? player1.releasePayload(weaponChoice - 1) : player2.releasePayload(weaponChoice - 1);
			//Subtract the damage from the other player's mech's health and see if that mech is destroyed
			gameOver = player ? player2.computeDamageReceived(damage) : player1.computeDamageReceived(damage);
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