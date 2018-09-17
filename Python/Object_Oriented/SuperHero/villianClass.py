#Base class for the Villians

class Villian():
    realName = None
    primaryPower = None
    colors = None
    def __init__(self, villianName):
        self.villianName = villianName       

    #sets super villian's real name
    def setRealName(self, realName):
        self.realName = realName

    #Gets super villian's real name
    def getRealName(self):
        return self.realName

    #sets super villian's powers
    def setPrimaryPower(self, primaryPower):
        self.primaryPower = primaryPower
    
    #Gets super villian's powers
    def getPrimaryPower(self):
        return self.primaryPower

    #sets super villian's colors
    def setColors(self, Colors):
        self.Colors = Colors
    
    #Gets super villian's colors
    def getColors(self):
        return self.colors
    
    def printVillianStats(self):
        print
        print "Villian Name: {}".format(self.villianName)
        print "Real Name: {}".format(self.realName)
        print "Primary Power: {}".format(self.primaryPower)
        print "Colors: {}".format(self.colors)
        return str('')