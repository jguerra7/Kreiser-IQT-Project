from heroClass import Hero
import heroClass as hc
import random

hero_list = []
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
    colors = 'Black and Yellow'

    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Wolverine)
        print   

        
class Cyclops(Hero):
    realName = 'Scott'
    primaryPower = 'Kinetic Eye Fungus'
    colors = 'Black and Red'
    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Cyclops)
        print

class Storm(Hero):
    realName = 'Storm'
    primaryPower = 'Weather Wizardry'
    colors = 'White'
    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Storm)
        print

class Iceman(Hero):
    realName = 'Jack Frost'
    primaryPower = 'Deep Freeze'
    colors = 'Blue'

    def __init__(self, heroName):
        Hero.__init__(self, heroName)
        self.heroName = heroName

    def getInfo(self):
        hc.Hero.printHeroStats(Iceman)
        print