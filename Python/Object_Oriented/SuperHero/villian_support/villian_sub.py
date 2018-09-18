from villianClass import Villian
import villianClass as vc
def villianTitle():
    print r""" /$$    /$$ /$$ /$$ /$$ /$$                    /$$              /$$   /$$                              
| $$   | $$|__/| $$| $$|__/                   | $/             | $$  /$$/                              
| $$   | $$ /$$| $$| $$ /$$  /$$$$$$  /$$$$$$$|_//$$$$$$$      | $$ /$$/   /$$$$$$   /$$$$$$   /$$$$$$ 
|  $$ / $$/| $$| $$| $$| $$ |____  $$| $$__  $$ /$$_____/      | $$$$$/   /$$__  $$ /$$__  $$ /$$__  $$
 \  $$ $$/ | $$| $$| $$| $$  /$$$$$$$| $$  \ $$|  $$$$$$       | $$  $$  | $$$$$$$$| $$$$$$$$| $$  \ $$
  \  $$$/  | $$| $$| $$| $$ /$$__  $$| $$  | $$ \____  $$      | $$\  $$ | $$_____/| $$_____/| $$  | $$
   \  $/   | $$| $$| $$| $$|  $$$$$$$| $$  | $$ /$$$$$$$/      | $$ \  $$|  $$$$$$$|  $$$$$$$| $$$$$$$/
    \_/    |__/|__/|__/|__/ \_______/|__/  |__/|_______/       |__/  \__/ \_______/ \_______/| $$____/ 
                                                                                             | $$      
                                                                                             | $$      
                                                                                             |__/"""


class Pyro(Villian):
    realName = "Sparky"
    primaryPower = "Fire-bending"
    secondaryPower = None
    health = 150
    damage = 30

    def __init__(self, villianName):
        Villian.__init__(self, villianName)
        self.villianName = villianName

    def getInfo(self):
        vc.Villian.printVillianStats(Pyro)

class Samurai(Villian):
    realName = "Mr. Roboto"
    primaryPower = "Adamantium Sword"
    secondaryPower = None
    health = 500
    damage = 35 

    def __init__(self, villianName):
        Villian.__init__(self, villianName)
        self.villianName = villianName

    def getInfo(self):
        vc.Villian.printVillianStats(Samurai)

class Mystique(Villian):
    realName = "Raven"
    primaryPower = "Shape-Shifting"
    secondaryPower = "Extreme Agility"
    health = 150
    damage = 30

    def __init__(self, villianName):
        Villian.__init__(self, villianName)
        self.villianName = villianName

    def getInfo(self):
        vc.Villian.printVillianStats(Mystique)

class Phoenix(Villian):
    realName = "Jean Grey"
    primaryPower = "Limitless Telekinetic Energy"
    secondaryPower = "Flying"
    health = 200
    damage = 75

    def __init__(self, villianName):
        Villian.__init__(self, villianName)
        self.villianName = villianName

    def getInfo(self):
        vc.Villian.printVillianStats(Phoenix)


  


