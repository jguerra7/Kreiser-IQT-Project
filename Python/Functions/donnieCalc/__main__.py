"""
Author: ELF
Course: Python
version: Python 3.X
FileName: lab4a.py
Lab 4a: Calculator
Recommended Version: Python 3.X
IMPORTANT: You must double click the application in windows or
download the Tkinter package in linux. The package is not
installed by default in linux but is in Windows!
Instructions
    Create a fully functional calculator using BOTH functions and lambdas. 
    Create a user menu as well as a "screen" where the numbers and operations 
    take place. The calculator needs to have the following functionality:
        Addition
        Subtraction
        Division
        Multiplication
        Power
        At least two math algorithms (One can be your Fibonacci)
Requirments
    Adhere to PEP8
    Functionality requirments above
    Utilize user input and proper validation
    Utilize proper formatting
    Utilize proper and clean statements and loop
Additional
    More than two numbers
    Continuous operations (5 + 5 + 2 - 1 / 2 for example)
    Additional operations
    Additonal math algorithms
    etc
"""
import calcGUI as cg

if __name__ == '__main__':
        #Loops the application until the user closes the program.
        cg.top.mainloop()