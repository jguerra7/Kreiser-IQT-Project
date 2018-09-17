# Name: William Kreiser
# Date: 13 Sep 18
# Project: Python Class(Lab2B)

"""Lab 5B: Your First Python Class
Instructions
Create a very simple super hero class. Some attributes you will need:

Hero Name
Real Name
Power(s)
Colors
etc

Requirements
Adhere to PEP8 and utilize proper and efficient code
Utilize a __init__()
Ensure variables are correct type (class vs instance variables)
Utilize methods:
Start to format your class using getters and setters
Create an instance of your class. Populate it with data utilzing a init and/or getters and setters
Additional:
Begin using encapsulation techniques"""

import hero_sub as hs
import villian_sub as vs
import os

global Player1 = hs.hc.hero('Player1')
global CPU = hs.hc.Hero('CPU')

def heroOrVillian():
    global Player1
    Player1 =  str(raw_input("Are you a Hero or a Villian? ")).rstrip()
    try:
        Player1 = str(Player1)
    except:
        print("Who's side are you on anyways? ")
        Player1 = heroOrVillian()
    if(Player1.upper() == "HERO" or Player1.upper() == 'VILLIAN'):
        return Player1
    else:
        print("You don't know what's at stake here!!!")
        Player1 = heroOrVillian()

if __name__ == '__main__':
    print r""" /$$   /$$                                                  
| $$  | $$                                                  
| $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$
| $$$$$$$$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$_____/
| $$__  $$| $$$$$$$$| $$  \__/| $$  \ $$| $$$$$$$$|  $$$$$$ 
| $$  | $$| $$_____/| $$      | $$  | $$| $$_____/ \____  $$
| $$  | $$|  $$$$$$$| $$      |  $$$$$$/|  $$$$$$$ /$$$$$$$/
|__/  |__/ \_______/|__/       \______/  \_______/|_______/   
                                                             """
    print r"""  /$$$$$$           
 /$$__  $$          
| $$  \ $$  /$$$$$$ 
| $$  | $$ /$$__  $$
| $$  | $$| $$  \__/
| $$  | $$| $$      
|  $$$$$$/| $$      
 \______/ |__/     
                    """
    print r""" /$$    /$$ /$$ /$$ /$$ /$$                              
| $$   | $$|__/| $$| $$|__/                              
| $$   | $$ /$$| $$| $$ /$$  /$$$$$$  /$$$$$$$   /$$$$$$$
|  $$ / $$/| $$| $$| $$| $$ |____  $$| $$__  $$ /$$_____/
 \  $$ $$/ | $$| $$| $$| $$  /$$$$$$$| $$  \ $$|  $$$$$$ 
  \  $$$/  | $$| $$| $$| $$ /$$__  $$| $$  | $$ \____  $$
   \  $/   | $$| $$| $$| $$|  $$$$$$$| $$  | $$ /$$$$$$$/
    \_/    |__/|__/|__/|__/ \_______/|__/  |__/|_______/ """


    #Choose your side
    alliance = heroOrVillian()
    if (alliance.upper() == "HERO"):
        os.system('cls')
        hs.heroTitle()
        Player1 = hs.heroSelection()
        CPU = vs.CPUvillian()
        print
        #This line would accept user input and store in a list
        #hInput.heroInput()        
    elif (alliance.upper() == "VILLIAN"):
        os.system('cls')
        vs.villianTitle()
        Player1 = vs.villianSelection()
        CPU = hs.CPUhero()
        print
        #This line would accept user input and store in a list
        #vInput.villianInput() 
        
    print ("{} vs. {}").format(Player1, CPU)
    