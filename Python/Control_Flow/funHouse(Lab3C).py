# Name: William Kreiser
# Date: 7 Sep 18
# Project: Fun House

import os
print """                                                                                                                            
      _____   ____   ____  _____   ______          ____   ____         _____     ____   ____          ______       ______   
 ____|\    \ |    | |    ||\    \ |\     \        |    | |    |   ____|\    \   |    | |    |     ___|\     \  ___|\     \  
|    | \    \|    | |    | \\    \| \     \       |    | |    |  /     /\    \  |    | |    |    |    |\     \|     \     \ 
|    |______/|    | |    |  \|    \  \     |      |    |_|    | /     /  \    \ |    | |    |    |    |/____/||     ,_____/|
|    |----'\ |    | |    |   |     \  |    |      |    .-.    ||     |    |    ||    | |    | ___|    \|   | ||     \--'\_|/
|    |_____/ |    | |    |   |      \ |    |      |    | |    ||     |    |    ||    | |    ||    \    \___|/ |     /___/|  
|    |       |    | |    |   |    |\ \|    |      |    | |    ||\     \  /    /||    | |    ||    |\     \    |     \____|\ 
|____|       |\___\_|____|   |____||\_____/|      |____| |____|| \_____\/____/ ||\___\_|____||\ ___\|_____|   |____ '     /|
|    |       | |    |    |   |    |/ \|   ||      |    | |    | \ |    ||    | /| |    |    || |    |     |   |    /_____/ |
|____|        \|____|____|   |____|   |___|/      |____| |____|  \|____||____|/  \|____|____| \|____|_____|   |____|     | /
  )/             \(   )/       \(       )/          \(     )/       \(    )/        \(   )/      \(    )/       \( |_____|/ 
  '               '   '         '       '            '     '         '    '          '   '        '    '         '    )/    
                                                                                                                      '  """

print "Welcome to the Fun House. Have fun navigating through this maze."
goodInput = False
while goodInput != True:    
    funInput = raw_input("Enter 1 for Left, 2 for Right, or 3 for Straight: ").rstrip()
    if funInput == "1":
        print "You are staring at a wall."
    elif funInput == "2":
        print "You see Rick and Morty watching TV."
    elif funInput == "3":
        print "You are now entering the mirror maze."
        goodInput = True
        os.system("cls")
    else:
        print "Non-decisiveness gets you nowhere."


print """                                                                                                                                                               
     ______  _______    ____      _____        _____           _____         _____              ______  _______          ____      _____              ______   
    |      \/       \  |    | ___|\    \   ___|\    \     ____|\    \    ___|\    \            |      \/       \    ____|\   \    /    /|___      ___|\     \  
   /          /\     \ |    ||    |\    \ |    |\    \   /     /\    \  |    |\    \          /          /\     \  /    /\    \  /    /|    |    |     \     \ 
  /     /\   / /\     ||    ||    | |    ||    | |    | /     /  \    \ |    | |    |        /     /\   / /\     ||    |  |    ||\____\|    |    |     ,_____/|
 /     /\ \_/ / /    /||    ||    |/____/ |    |/____/ |     |    |    ||    |/____/        /     /\ \_/ / /    /||    |__|    || |   |/    |___ |     \--'\_|/
|     |  \|_|/ /    / ||    ||    |\    \ |    |\    \ |     |    |    ||    |\    \       |     |  \|_|/ /    / ||    .--.    | \|___/    /    ||     /___/|  
|     |       |    |  ||    ||    | |    ||    | |    ||\     \  /    /||    | |    |      |     |       |    |  ||    |  |    |    /     /|    ||     \____|\ 
|\____\       |____|  /|____||____| |____||____| |____|| \_____\/____/ ||____| |____|      |\____\       |____|  /|____|  |____|   |_____|/____/||____ '     /|
| |    |      |    | / |    ||    | |    ||    | |    | \ |    ||    | /|    | |    |      | |    |      |    | / |    |  |    |   |     |    | ||    /_____/ |
 \|____|      |____|/  |____||____| |____||____| |____|  \|____||____|/ |____| |____|       \|____|      |____|/  |____|  |____|   |_____|____|/ |____|     | /
    \(          )/       \(    \(     )/    \(     )/       \(    )/      \(     )/            \(          )/       \(      )/       \(    )/      \( |_____|/ 
     '          '         '     '     '      '     '         '    '        '     '              '          '         '      '         '    '        '    )/    
                                                                                                                                                         ' """

print "You entered the mirror maze and the door shuts behind. There are 3 doors and 2 staircases in front of you."

goodInput = False
while goodInput != True:
    mirrorInput = raw_input("Enter 1 for Left, 2 for Right, 3 for Straight, 4 for Upstairs, or 5 for Downstairs.")
    if mirrorInput == "1":
        print "Welcome to the black hole of eternity. You float off into space. Game Over."
        exit(1)
    elif mirrorInput == "2":
        print "You have enter the Hyperbolic Training Chamber and get hit with a Final Flash from Vegeta. Game Over."
        exit(2)
    elif mirrorInput == "3":
        print "You stumble while walking through the door and fall in front of a raging Saiyan Gorilla. He rips you limb from limb. Game Over."
        exit(3)
    elif mirrorInput == "4":
        print "Congratulations you have escaped the Mirror Maze!!! You win!!!"
        goodInput = True
        os.system("cls")
    elif mirrorInput == "5":
        print "You stepped on a trapdoor and have fallen into a spike pit. Game Over."
        exit(5)
    else:
        print "Nowhere...you will go nowhere!!!"
    