#Base class for the Heroes
class Hero():
    realName = None
    primaryPower = None
    secondaryPower = None
    damage = None
    health = None

    def __init__(self, heroName):
        self.heroName = heroName   

    #Setters
    def setDamage(self, damage):
        self.damage = damage  
    def setHealth(self, health):
        self.health = health
    def setRealName(self, realName):
        self.realName = realName
    def setPrimaryPower(self, primaryPower):
        self.primaryPower = primaryPower    
    def setSecondaryPower(self, secondaryPower):
        self.secondaryPower = secondaryPower

    #getters
    def getDamage(self):
        return self.damage
    def getHealth(self, health):
        return self.health   
    def getRealName(self):
        return self.realName
    def getPrimaryPower(self):
        return self.primaryPower
    def getSecondaryPower(self):
        return self.secondaryPower
    
    def printHeroStats(self):
        print
        print "Hero Name: {}".format(self.heroName)
        print "Real Name: {}".format(self.realName)
        print "Primary Power: {}".format(self.primaryPower)
        print "Secondary Power: {}".format(self.secondaryPower)
        print "Health: {}".format(self.health)
        print "Damage: {}".format(self.damage)
        return str('')