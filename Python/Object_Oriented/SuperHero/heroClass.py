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

class Hero:

    def __init__(self, heroName, realName, powers, colors):
        self._heroName = heroName
        self._realName = realName
        self._powers = powers
        self._colors = colors

    #sets super hero hero's real name
    def setRealName(self, realName):
        self._realName = realName

    #Gets super hero's real name
    def getRealName(self):
        return self._realName

    #sets super hero's powers
    def setPowers1(self, powers):
        self._powers1 = powers
    
    #Gets super hero's powers
    def getPowers(self):
        return self._powers

    #sets super hero's colors
    def setColors(self, colors):
        self._colors = colors
    
    #Gets super hero's colors
    def getColors(self):
        return self._colors
    
    def printHeroStats(self):
        print
        print "Hero Name: {}".format(self._heroName)
        print "Real Name: {}".format(self._realName)
        print "Powers: {}".format(self._powers)
        print "Colors: {}".format(self._colors)
        return str('')