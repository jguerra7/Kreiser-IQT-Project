from heroClass import Hero
import heroClass as hc

def heroTitle():
    print r""" /$$   /$$                                                         /$$$$$$            /$$ /$$       /$$
| $$  | $$                                                        /$$__  $$          |__/| $$      | $$
| $$  | $$  /$$$$$$   /$$$$$$  /$$$$$$   /$$$$$$   /$$$$$$$      | $$  \__/ /$$   /$$ /$$| $$  /$$$$$$$
| $$$$$$$$ /$$__  $$ /$$__  $$/$$__  $$ /$$__  $$ /$$_____/      | $$ /$$$$| $$  | $$| $$| $$ /$$__  $$
| $$__  $$| $$$$$$$$| $$  \__/ $$  \ $$| $$$$$$$$|  $$$$$$       | $$|_  $$| $$  | $$| $$| $$| $$  | $$
| $$  | $$| $$_____/| $$     | $$  | $$| $$_____/ \____  $$      | $$  \ $$| $$  | $$| $$| $$| $$  | $$
| $$  | $$|  $$$$$$$| $$     |  $$$$$$/|  $$$$$$$ /$$$$$$$/      |  $$$$$$/|  $$$$$$/| $$| $$|  $$$$$$$
|__/  |__/ \_______/|__/      \______/  \_______/|_______/        \______/  \______/ |__/|__/ \_______/"""

class Wolverine(Hero):
    realName = 'Logan'
    primaryPower = 'Super Healing'
    secondaryPower = 'Adamantium Claws'
    health = 500
    damage = 50

    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Wolverine)
        print   

        
class Cyclops(Hero):
    realName = 'Scott'
    primaryPower = 'Kinetic Eye Blast'
    secondaryPower = None
    health = 150
    damage = 30

    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Cyclops)
        print

class Storm(Hero):
    realName = 'Storm'
    primaryPower = 'Weather Wizardry'
    secondaryPower = 'Flying'
    health = 125
    damage = 25

    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Storm)
        print

class Iceman(Hero):
    realName = 'Jack Frost'
    primaryPower = 'Deep Freeze'
    secondaryPower = 'Ice Armor'
    health = 150
    damage = 30

    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Iceman)
        print