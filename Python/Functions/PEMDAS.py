"""
Name: Zackery Vering
Project: Lab 4A
Date: 10 Sept 2018
Instructions
Create a fully functional calculator using BOTH functions and lambdas.
Create a user menu as well as a "screen" where the numbers and
operations take place. The calculator needs to have the following
functionality:

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
"""
import time
from math import sqrt
import imageop
#define variables
user_choice = 0
#define functions
def check_int():
    #ask for user input and check if it's an integer
    user_input = raw_input("What would you like to do?\n")
    try:
        user_input = int(user_input)
    except ValueError:
        print ("Try again.")
        user_input = check_int()
    return user_input

def num1():
    #ask for user input and check if it's an integer
    user_input = raw_input("What is the first number?\n")
    try:
        user_input = int(user_input)
    except ValueError:
        print ("Try again.")
        user_input = check_int()
    return user_input

def num2():
    #ask for user input and check if it's an integer
    user_input = raw_input("What is the second number?\n")
    try:
        user_input = int(user_input)
    except ValueError:
        print ("Try again.")
        user_input = check_int()
    return user_input

def addition():
    #perform addition
    print("You selected addition.")
    add1 = num1()
    add2 = num2()
    x = add1+add2
    print ("{} + {} = {}").format(add1, add2, x)

def subtraction():
    #perform subtraction
    print("You selected subtraction.")
    sub1 = num1()
    sub2 = num2()
    x = sub1-sub2
    print ("{} - {} = {}").format(sub1, sub2, x)

def division():
    #perform division
    print("You selected division.")
    div1 = num1()
    div2 = float(num2())
    x = div1/div2
    print ("{} / {} = {}").format(div1, div2, x)

def multiplication():
    #perform multiplication
    print("You selected multiplication.")
    mul1 = num1()
    mul2 = num2()
    x = mul1*mul2
    print ("{} * {} = {}").format(mul1, mul2, x)

def power():
    #perform a power operation
    print("You selected power.")
    pow1 = num1()
    pow2 = num2()
    x = pow1**pow2
    print ("{} to the power of {} is {}").format(pow1, pow2, x)

def fibonacci(n):
    #run fibonacci
    if n <= 1:
        return n
    else:
        return fibonacci(n-1)+fibonacci(n-2)

def pythagoras():
    #perfrom pythagorian theorm
    pyt1 = num1()
    pyt2 = num2()
    print("The third side of your right triangle is {}.").format(sqrt((pyt1**2)+(pyt2**2)))
#start loop
while (user_choice != 7):
    #print menu
    print("{:_^20}").format("")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Division")
    print("4. Multiplication")
    print("5. Power")
    print("6. Algorithms")
    #print("7. Something else")
    print("7. Quit")
    print("{:_^20}").format("")
    #ask user what they want to do
    user_choice = check_int()
    print("{:_^20}").format("")
    #call function based on user choice
    if (user_choice == 1):
        addition()
    elif (user_choice == 2):
        subtraction()
    elif (user_choice == 3):
        division()
    elif (user_choice == 4):
        multiplication()
    elif (user_choice == 5):
        power()
    elif (user_choice == 6):
        #let user choose what algorithm they want to run
        print("You selected algorithms.")
        print("1. Fibanacci")
        print("2. Pythagoras")
        user_choice2 = check_int()
        while(True):
            if (user_choice2 == 1):
                y = int(raw_input("How many times would you like to loop?\n"))
                while(True):
                    for i in xrange(y):
                        print(fibonacci(i))
                    break
                break
            elif (user_choice2 == 2):
                pythagoras()
                break
            else:
                print("That was an invalid response. Please try again.")
                user_choice2 = check_int()
                print("{:_^20}").format("")
    elif (user_choice == 7):
        #haven't got this workkng yet
        print("You selected something else.")
        picture = image.open("C:\IQTRepo\Project\Python\Functions\doge.jpg")
        image.show()
        time.sleep(7)
        picture.close()
    elif (user_choice == 8):
        print("Have a good day!")
    else:
        print("That was an invalid response. Please try again.")
        user_choice = check_int()
        print("{:_^20}").format("")