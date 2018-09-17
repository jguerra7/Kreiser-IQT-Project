# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Class(Lab5C)


class Villian:

    def __init__(self, villianName, realName, primaryPower, secondaryPower, strength, damage):
        self._villianName = villianName
        self._realName = realName
        self._primaryPower = primaryPower
        self._secondaryPower = secondaryPower
        self._strength = strength
        self._damage = damage

    #sets super villian's real name
    def setRealName(self, realName):
        self._realName = realName

    #Gets super villian's real name
    def getRealName(self):
        return self._realName

    #sets super villian's powers
    def setPrimaryPower(self, primaryPower):
        self._primaryPower = primaryPower
    
    #Gets super villian's powers
    def getPrimaryPower(self):
        return self._primaryPower

    #sets super villian's colors
    def setSecondaryPower(self, secondaryPower):
        self._secondaryPower = secondaryPower
    
    #Gets super villian's colors
    def getSecondaryPower(self):
        return self._secondaryPower

    #Sets super villian's strength
    def setStrength(self, strength):
        self._strength = strength

    #Gets super villian's strength
    def getStrength(self):
        return self._strength

    def setDamage(self, damage):
        self._damage = damage

    def getDamage(self):
        return self._damage
    
    def printVillianStats(self):
        print
        print "Villian Name: {}".format(self._villianName)
        print "Real Name: {}".format(self._realName)
        print "Primary Power: {}".format(self._primaryPower)
        print "Secondary Power: {}".format(self._secondaryPower)
        print "Strength: {}".format(self._strength)
        print "Damage: {}".format(self._damage)
        return str('')