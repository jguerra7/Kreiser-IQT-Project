# Name: William Kreiser
# Date: 7 Sep 18
# Project: Integer Factorial Lab3D

""" Write a program that prompts a user to input an integer and calculates the 
    factorial of that number using a while loop."""

#Guarantees integer for input
userInput = raw_input("Please enter a number: ").rstrip()
userInput = unicode(userInput, 'utf-8')
while (userInput.isnumeric() == False):
    userInput = raw_input("Please enter a number: ").rstrip()
    userInput = unicode(userInput, 'utf-8')
    
userInput = int(userInput)
#number to factor by
factorial = 1

while userInput:
    #Error Check 
    if userInput < 0:
        print ("Negative numbers do not have factorials.")
        exit(-1)
    elif userInput == 0:
        print ("The factorial of 0 is 1.")
    else:
        #loop to process to factorial of user input number
        for i in range(1, userInput + 1):
            factorial *= i
        print("The factorial of",userInput, "is",factorial)
        break