#Base class for the Heroes

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