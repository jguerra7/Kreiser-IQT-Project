# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Class(Lab2B)

"""Lab 5B: Your First Python Class
Instructions
Create a very simple super hero class. Some attributes you will need:

Hero Name
Real Name
Power(s)
Colors
etc

Requirements
Adhere to PEP8 and utilize proper and efficient code
Utilize a __init__()
Ensure variables are correct type (class vs instance variables)
Utilize methods:
Start to format your class using getters and setters
Create an instance of your class. Populate it with data utilzing a init and/or getters and setters
Additional:
Begin using encapsulation techniques"""
import heroGetSet as hgs
import villianGetSet as vgs
from hero_sub import Wolverine, Storm, Iceman, Cyclops
from villian_sub import Mystique, Phoenix, Pyro, Samurai
import hero_sub as hs
import villian_sub as vs
import os

def heroOrVillian():
    global Player1
    Player1 =  str(raw_input("Are you a Hero or a Villian? ")).rstrip()
    try:
        Player1 = str(Player1)
    except:
        print("Who's side are you on anyways? ")
        Player1 = heroOrVillian()
    if(Player1.upper() == "HERO" or Player1.upper() == 'VILLIAN'):
        return Player1
    else:
        print("You don't know what's at stake here!!!")
        Player1 = heroOrVillian()


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
        hero1 = Wolverine("Wolverine")
        hero1.setColors("Black")
        hero1.setPrimaryPower("Super Healing")
        hero1.setRealName("Logan")
        hero1.printHeroStats()
        
        #Storm Class
        hero2 = Storm("Storm")
        hero2.setColors("White")
        hero2.setPrimaryPower("Weather Wizardry")
        hero2.setRealName("Unknown")
        hero2.printHeroStats()

        choice = str(raw_input("Please select your Hero: ")).rstrip()
        if (choice.upper() == 'Storm' or choice.upper() == 'Wolverine'):
            powerSwap = str(raw_input("Would you like to change their power(Y/N)? ")).rstrip()
            if (powerSwap.upper() == 'Y'):
                newPower = str(raw_input("Enter the new power: ")).rstrip()
                if (choice.upper() == 'Wolverine'):
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
    
        hero1 = Mystique("Mystique")
        hero1.setColors("All Colors")
        hero1.setPrimaryPower("Metamorphology")
        hero1.setRealName("Raven")
        hero1.printVillianStats()

        hero2 = Samurai("Samurai")
        hero2.setColors("Silver and Red")
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
