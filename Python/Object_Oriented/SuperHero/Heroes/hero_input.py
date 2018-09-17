# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Classes(Lab5C)

""" This file will contain of the userInput that the program will user to 
create a new instance of SuperHero class """

import heroClass as hc
from heroGetSet import newHero

def heroInput():

    new_hero = True
    num_heroes = inputNumHeroes()
    hero_counter = 0
    hero_list = []
    while (hero_counter < num_heroes):
        
        if (new_hero == True):
            #Takes in hero name
            hero_name = inputHeroName()
            newHero(hero_name)
            #Takes in heroes real name
            real_name = inputRealName()
            hero_name.setRealName(real_name)
            #takes in number of hero powers
            num_powers = inputNumPowers()

            #Error checking for number of powers
            if (num_powers < 1):
                print "Must be a bad ass to not need powers"
                primaryPow = None
            elif (num_powers == 1):
                primaryPow = inputPowers()
                hero_name.setPrimaryPower(primaryPow)
            colors = inputColors()     
            hero_name.setColors(colors)
            #Creates new hero instance and stores in a list
            hero_list.append(hero_name)
            hero_counter += 1
            print
        else:
            new_hero == False
    
    for hero in hero_list:
        hero.printHeroStats()

def inputHeroName():
    inputString = str(raw_input("What is the heroes name: ")).rstrip()
    try:
        inputString = str(inputString)
    except:
        print "That sure is a weird."
        inputString = inputHeroName()
    return inputString

def inputRealName():
    inputString = str(raw_input("What is their real name? ")).rstrip()
    try:
        inputString = str(inputString)
    except:
        print "That sure is a weird."
        inputString = inputRealName()
    return inputString

def inputNumPowers():
    inputInt = raw_input("How many powers does your hero wield? ")
    try:
        inputInt = int(inputInt)
    except:
        print "I expected a number!!!"
        inputInt = inputNumPowers()
    return int(inputInt)

def inputPowers():
    power = str(raw_input("Enter their power: ")).rstrip()
    try:
        power = str(power)
    except:
        print "What kind of power is that?"
        power = inputPowers()
    return power

def inputColors():
    inputString = str(raw_input("What is their outfit color? ")).rstrip()
    try:
        inputString = str(inputString)
    except:
        print "Hmmmm.....running around without clothes."
        inputString = inputRealName()
    return inputString

def inputNumHeroes():
    inputInt = raw_input("How many heroes need guild access? ")
    try:
        inputInt = int(inputInt)
    except:
        print "I expected a number!!!"
        inputInt = inputNumPowers()
    return int(inputInt)