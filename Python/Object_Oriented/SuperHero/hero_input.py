# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Classes(Lab5B)

""" This file will contain of the userInput that the program will user to 
create a new instance of SuperHero class """

import heroClass as hc
import valid_input as vi


def printTitle():
    print r""" /$$   /$$                                                         /$$$$$$            /$$ /$$       /$$
| $$  | $$                                                        /$$__  $$          |__/| $$      | $$
| $$  | $$  /$$$$$$   /$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$$      | $$  \__/ /$$   /$$ /$$| $$  /$$$$$$$
| $$$$$$$$ /$$__  $$ /$$__  $$/$$__  $$ /$$__  $$ /$$_____/      | $$ /$$$$| $$  | $$| $$| $$ /$$__  $$
| $$__  $$| $$$$$$$$| $$  \__/ $$  \ $$| $$$$$$$$|  $$$$$$       | $$|_  $$| $$  | $$| $$| $$| $$  | $$
| $$  | $$| $$_____/| $$     | $$  | $$| $$_____/ \____  $$      | $$  \ $$| $$  | $$| $$| $$| $$  | $$
| $$  | $$|  $$$$$$$| $$     |  $$$$$$/|  $$$$$$$ /$$$$$$$/      |  $$$$$$/|  $$$$$$/| $$| $$|  $$$$$$$
|__/  |__/ \_______/|__/      \______/  \_______/|_______/        \______/  \______/ |__/|__/ \_______/"""



def heroInput():

    new_hero = True
    num_heroes = vi.inputNumHeroes()
    hero_counter = 0
    hero_list = []
    while (hero_counter < num_heroes):
        
        if (new_hero == True):
            #Takes in hero name
            hero_name = vi.inputHeroName()

            #Takes in heroes real name
            real_name = vi.inputRealName()

            #takes in number of hero powers
            num_powers = vi.inputNumPowers()

            #Error checking for number of powers
            if (num_powers < 1):
                print "Must be a bad ass to not need powers"
                powers = None
            elif (num_powers == 1):
                powers = vi.inputPowers()
            # elif (num_powers > 1):
            #     counter = 1
            #     while counter < num_powers:
            #         powers[counter] = vi.inputPowers()
            #Takes in hero outfit colors
            colors = vi.inputColors()            
            #Creates new hero instance and stores in a list
            hero_list.append(hc.Hero(hero_name, real_name, powers, colors))
            hero_counter += 1
            print
        else:
            new_hero == False
    
    for hero in hero_list:
        print hero.printHeroStats()

        