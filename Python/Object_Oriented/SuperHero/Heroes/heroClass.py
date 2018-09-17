# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Class(Lab5C)

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

class Hero():
    realName = None
    primaryPower = None
    colors = None

    def __init__(self, heroName):
        self.heroName = heroName        

    #sets super hero's real name
    def setRealName(self, realName):
        self.realName = realName

    #Gets super hero's real name
    def getRealName(self):
        return self.realName

    #sets super hero's powers
    def setPrimaryPower(self, primaryPower):
        self.primaryPower = primaryPower
    
    #Gets super hero's powers
    def getPrimaryPower(self):
        return self.primaryPower

     #sets super hero's colors
    def setColors(self, colors):
        self.colors = colors
    
    #Gets super hero's colors
    def getColors(self):
        return self.colors
    
    def printHeroStats(self):
        print
        print "Hero Name: {}".format(self.heroName)
        print "Real Name: {}".format(self.realName)
        print "Primary Power: {}".format(self.primaryPower)
        print "Colors: {}".format(self.colors)
        return str('')