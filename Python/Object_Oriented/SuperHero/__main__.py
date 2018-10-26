# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Class(Lab5C)

"""Update your hero class lab with the following additions:

Create a generic Person class
Create a Hero class that inherits from Person
Refactor code where needed
Utilize proper Encapsulation
Include user input
Use getters and setters
Requirments
Adhere to PEP8 and utilize proper and efficient code
Input validation
Utilize a __init__()
Ensure variables are correct type (class vs instance variables)
Utilize methods for getters and setters
Create an few instances of your class. Populate it with data utilzing a init and/or getters and setters
Split your classes into seperate files and import them properly
Additional:
Expand this program into a game or larger program. Some possible ideas:
Hero vs Villan
Battle Royal
Guess that Hero
etc"""

from SuperHero import hero_support, villian_support
from hero_support import hero_sub as hs
from villian_support import villian_sub as vs
import os

def heroOrVillian():
    choice =  str(raw_input("Are you a Hero or a Villian? ")).rstrip()
    try:
        choice = str(choice)
    except:
        print("Who's side are you on anyways? ")
        choice = heroOrVillian()
    if(choice.upper() == "HERO" or choice.upper() == 'VILLIAN'):
        return choice
    else:
        print("You don't know what's at stake here!!!")
        choice = heroOrVillian()


if __name__ == '__main__':

#Choose your side
    alliance = heroOrVillian()
    if (alliance.upper() == "HERO"):
        os.system('cls')
        print r""" /$$   /$$                                                  
    | $$  | $$                                                  
    | $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$
    | $$$$$$$$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$_____/
    | $$__  $$| $$$$$$$$| $$  \__/| $$  \ $$| $$$$$$$$|  $$$$$$ 
    | $$  | $$| $$_____/| $$      | $$  | $$| $$_____/ \____  $$
    | $$  | $$|  $$$$$$$| $$      |  $$$$$$/|  $$$$$$$ /$$$$$$$/
    |__/  |__/ \_______/|__/       \______/  \_______/|_______/   
                                                                """
        print "Available Heroes"
        print "----------------"
        #Wolverine Class
        hero1 = hs.Wolverine("Wolverine")
        hero1.setPrimaryPower("Super Healing")
        hero1.setRealName("Logan")
        hero1.printHeroStats()
        
        #Storm Class
        hero2 = hs.Storm("Storm")
        hero2.setPrimaryPower("Weather Wizardry")
        hero2.setRealName("Unknown")
        hero2.printHeroStats()

        choice = str(raw_input("\nPlease select your Hero: ")).rstrip()
        if (choice.upper() == 'STORM' or choice.upper() == 'WOLVERINE'):
            powerSwap = str(raw_input("Would you like to change their power(Y/N)? ")).rstrip()
            if (powerSwap.upper() == 'Y'):
                newPower = str(raw_input("Enter the new power: ")).rstrip()
                if (choice.upper() == 'WOLVERINE'):
                    hero1.setPrimaryPower(newPower)
                    hero1.printHeroStats()
                else:
                    hero2.setPrimaryPower(newPower)
                    hero2.printHeroStats()
        else:
            print "Good bye"
            exit(0)

       
    elif (alliance.upper() == "VILLIAN"):
        os.system('cls')
        print r""" /$$    /$$ /$$ /$$ /$$ /$$                              
| $$   | $$|__/| $$| $$|__/                              
| $$   | $$ /$$| $$| $$ /$$  /$$$$$$  /$$$$$$$   /$$$$$$$
|  $$ / $$/| $$| $$| $$| $$ |____  $$| $$__  $$ /$$_____/
\  $$ $$/ | $$| $$| $$| $$  /$$$$$$$| $$  \ $$|  $$$$$$ 
\  $$$/  | $$| $$| $$| $$ /$$__  $$| $$  | $$ \____  $$
\  $/   | $$| $$| $$| $$|  $$$$$$$| $$  | $$ /$$$$$$$/
\_/    |__/|__/|__/|__/ \_______/|__/  |__/|_______/ """
    
        hero1 = vs.Mystique("Mystique")
        hero1.setPrimaryPower("Metamorphology")
        hero1.setRealName("Raven")
        hero1.printVillianStats()

        hero2 = vs.Samurai("Samurai")
        hero2.setPrimaryPower("Adamantium Sword")
        hero2.setRealName("Jack")
        hero2.printVillianStats()


        choice = str(raw_input("Please select your villian: ")).rstrip()
        if (choice.upper() == 'MYSTIQUE' or choice.upper() == 'SAMURAI'):
            powerSwap = str(raw_input("Would you like to change their power(Y/N)? ")).rstrip()
            if (powerSwap.upper() == 'Y'):
                newPower = str(raw_input("Enter the new power: ")).rstrip()
                if (choice.upper() == 'MYSTIQUE'):
                    hero1.setPrimaryPower(newPower)
                    hero1.printVillianStats()
                else:
                    hero2.setPrimaryPower(newPower)
                    hero2.printVillianStats()
        else:
            print "Good bye"
            exit(0)
