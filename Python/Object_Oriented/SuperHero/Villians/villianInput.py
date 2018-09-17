# Name:William Kreiser
# Date: 13 Sep 18
# Project: Super Hero(Lab5B)

import villianClass as vc

def villianInput():

    new_villian = True
    num_villian = inputNumVillians()
    villian_counter = 0
    villian_list = []
    while (villian_counter < num_villian):
        
        if (new_villian == True):
            #Takes in hero name
            villian_name = inputVillianName()

            #Takes in heroes real name
            real_name = inputRealName()

            #takes in number of hero powers
            num_powers = inputNumPowers()

            #Error checking for number of powers
            if (num_powers < 1):
                print "Must be a bad ass to not need powers"
                powers = None
            elif (num_powers == 1):
                powers = inputPowers()
            # elif (num_powers > 1):
            #     counter = 1
            #     while counter < num_powers:
            #         powers[counter] = vi.inputPowers()
            #Takes in hero outfit colors
            colors = inputColors()            
            #Creates new hero instance and stores in a list
            villian_list.append(vc.Villian(villian_name, real_name, powers, colors))
            villian_counter += 1
            print
        else:
            new_villian == False
    
    for villian in villian_list:
        


def inputVillianName():
    inputString = str(raw_input("Villian Callsign: ")).rstrip()
    try:
        inputString = str(inputString)
    except:
        print "That sure is a weird."
        inputString = inputVillianName()
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
    inputInt = raw_input("How many powers does your villian wield? ")
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
        inputString = inputColors()
    return inputString

def inputNumVillians():
    inputInt = raw_input("How many villians need keep access? ")
    try:
        inputInt = int(inputInt)
    except:
        print "I expected a number!!!"
        inputInt = inputNumVillians()
    return int(inputInt)
    
     