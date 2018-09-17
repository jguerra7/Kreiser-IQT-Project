from heroClass import Hero

class newHero(Hero):
    realName = None
    primaryPower = None
    colors = None
    
    def __init__(self, heroname, name):
        Hero.__init__(self, name)
        self.heroname = heroname

    def getInfo(self):
        self.printHeroStats()
