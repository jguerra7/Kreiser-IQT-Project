# Name: William Kreiser
# Date: 12 Sep 18
# Project: Calculator(Lab5A)

"""
Using your calculator you created from Lab4A, split up the functionality 
into modules and utilize packaging. 
Some things you could split up:
    The user menu into it's own module on a higher level package
    Opertions into one module, lower level
    Algorithms into one module, lower level, etc
"""

from CalcFunctions import menu_logic as ml

if __name__ == '__main__':
    ml.menu_logic()