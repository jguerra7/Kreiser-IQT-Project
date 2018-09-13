# Name:William Kreiser
# Date: 13 Sep 18
# Project: Super Hero(Lab5B)

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