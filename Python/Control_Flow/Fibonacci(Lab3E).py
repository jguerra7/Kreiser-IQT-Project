# Name: William Kreiser
# Date: 7 Sep 18
# Project: Fibonacci (Lab3E)

"""
1. Write a file that prints out the first 100 numbers iteratively
2. Revisit this lab and create a Fibonacci recursive function

Some additional things you can do are:
    Utilize functions
    Create the recursive solution before going over ch04
    Utilize some Python modules or built in functionality
    Ask user for range of numbers to calculate
"""
#Recursive function for the fibonacci sequence
def recursive_fibo(num):
    if (num <= 1):
        return 1
    else:
        return(recursive_fibo(num-1) + recursive_fibo(num -2))

#Iterative version of the fibonacci sequence
def iterative_fibo(num):
    if (num <= 0):
       print "Please enter a positive integer"
    elif (num == 1):
        return num
    else:
        x, y = 0, 1
        for i in range(num):
            x, y = y, x + y
        return x

#This function will take in userInput and verify it is an integer
def get_user_input():
    userInput = raw_input("Please enter a number: ").rstrip()
    try:
        userInput = int(userInput)
    except ValueError:
        print("Try again.\n")
        userInput = get_user_input()
    #Cannot do negative fibonacci sequence
    if (userInput <= 0):
        userInput = abs(userInput)
    return userInput

print "---------------------------------------"
print "----------Fibonacci Sequence-----------"
print "---------------------------------------\n"
#takes user input
fibo_number = get_user_input()

#Recursive fibonacci function call
print "----------Recursive Output-------------"
for i in xrange(1, fibo_number + 1):
    print recursive_fibo(i)

#Iterative fibonacci function call
print "----------Iterative Output-------------"
for j in xrange(1, fibo_number + 1):
    print iterative_fibo(j)