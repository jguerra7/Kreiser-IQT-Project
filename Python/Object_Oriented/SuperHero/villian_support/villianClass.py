#Base class for the Villians

class Villian():
    realName = None
    primaryPower = None
    secondaryPower = None
    damage = None
    health = None
    def __init__(self, villianName):
        self.villianName = villianName       

    #Setters
    def setRealName(self, realName):
        self.realName = realName    
    def setPrimaryPower(self, primaryPower):
        self.primaryPower = primaryPower
    def setSecondaryPower(self, secondaryPower):
        self.secondaryPower = secondaryPower
    def setDamage(self, damage):
        self.damage = damage
    def setHealth(self, health):
        self.health = health
    
    #Getters
    def getRealName(self):
        return self.realName
    def getPrimaryPower(self):
        return self.primaryPower
    def getSecondaryPower(self):
        return self.secondaryPower
    def getDamage(self):
        return self.damage
    def getHealth(self):
        return self.health
    
    def printVillianStats(self):
        print
        print "Villian Name: {}".format(self.villianName)
        print "Real Name: {}".format(self.realName)
        print "Primary Power: {}".format(self.primaryPower)
        print "Secondary Power: {}".format(self.secondaryPower)
        print "Health: {}".format(self.health)
        print "Damage: {}".format(self.damage)
        return str('')