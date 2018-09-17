from villianClass import Villian

class newvillian(Villian):
    primaryPower = None
    colors = None
    realName = None

    def __init__(self, villianName, name):
        Villian.__init__(self, name)
        self.villianName = villianName

    def getInfo(self):
        self.printVillianStats()