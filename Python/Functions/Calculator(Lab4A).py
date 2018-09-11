# Name: William Kreiser
# Date: 10 Sep 18
# Project: Calculator

#Iterative version of the Fibonacci sequence
def fibonacci(num):
    if (num <= 0):
       print "Please enter a positive integer"
    elif (num == 1):
        return num
    else:
        x, y = 0, 1
        for i in range(num):
            x, y = y, x + y
        return x
#Function to print the mathematical operations list
def operator_list():
    print "+ = Addition"
    print "- = Subtraction"
    print "* = Multiplication"
    print "/ = Division"
    print "** = Exponent"
    print "F = Fibonacci"
    print "! = Factorial"
    print "Exit"    

#Operator error checking for input
def operator_input():
    operator_list()
    math_oper = str(raw_input("Please select an operator: ")).rstrip()
    if(math_oper == '+' or math_oper == '-' or math_oper == '*' \
        or math_oper == '/' or math_oper == '**' \
        or math_oper.upper() == 'F' \
        or math_oper == '!'\
        or math_oper.upper() == 'EXIT'):
        return math_oper
    else:
            print "Invalid operator selected. Try again."
            math_oper = operator_input()

#Error checking for integer input
def get_user_input():
    userInput = raw_input("Enter an integer: ").rstrip()
    try:
        userInput =int(userInput)
    except ValueError:
        print("Try again.\n")
        userInput = get_user_input()
    return userInput

# For continuous input to evaluate and parse through a string
keep_going = True

while keep_going == True:
    x = get_user_input()
    y = get_user_input()
    math_oper = operator_input()
    if (math_oper == '+'): 
        total = lambda x, y: x + y
    elif (math_oper == '-'): 
        total = lambda x,y: x - y
    elif (math_oper == '*'): 
        total = lambda x,y: x * y
    elif (math_oper == '/'): 
        if (y == 0):
            print "Armageddon has been triggered. \
            Division by 0 detected."
            continue
        else:
            total = lambda x,y: x / y       
    elif (math_oper == '**'): 
        total  = lambda x,y: x ** y
    elif (math_oper == 'F'): 
        fib = lambda n:reduce(lambda x, n: [x[1], x[0] + x[1]], \
                                    range(n), [0,1])[0]
    elif (math_oper.upper() == '!'):
        fact = lambda x: 1 if x == 0 else x * fact(x-1)
    elif (math_oper.upper() == 'EXIT'):
        print "Exiting now..."
        keep_going = False
        break
    if math_oper in ["+", "-", "/", "*", "**"]:
        output = total(x, y)
        print("The result of {} {} {} is {}").format(
                x, math_oper, y, output)
    if math_oper is "F":
        choice = raw_input("Perform Fibonacci Sequence on x or y?").rstrip()
        if (choice.upper() == 'X'):
            output = fib(x)
            print("The fibonacci number at position {} is {}").format(
                x, output)               
        elif (choice.upper() == 'Y'):
            output = fib(y)
            print("The fibonacci number at position {} is {}").format(
                y, output)
        else:
            print "Unknown choice."
            continue        
    if math_oper is "!":
        choice = raw_input("Run Factorial on x or y?").rstrip()
        if (choice.upper() == 'X'):
            output = fact(x)
            print("{} {} is {}").format(
                x, math_oper, output)
        elif (choice.upper() == 'Y'):
            output = fact(y)
            print("{} {} is {}").format(
                y, math_oper, output)
        else:
            print "Unknown choice."
            continue