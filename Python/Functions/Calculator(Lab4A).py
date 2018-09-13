# Name: William Kreiser
# Date: 10 Sep 18
# Project: Calculator(Lab4A)
#Error checking for integer input
def get_user_input():
    userInput = raw_input("Enter an integer: ").rstrip()
    try:
        userInput =int(userInput)
    except ValueError:
        print("Try again.\n")
        userInput = get_user_input()
    return userInput

    #Function to print the mathematical operations list
def operator_list():
    print "\n+ = Addition"
    print "- = Subtraction"
    print "* = Multiplication"
    print "/ = Division"
    print "** = Exponent"
    print "% = Modulus Division"
    print "F = Fibonacci"
    print "! = Factorial"
    print "N = New Numbers"
    print "Exit\n"    

#Operator error checking for input
def operator_input():
    operator_list()
    math_oper = str(raw_input("Please select an operator: ")).rstrip()
    if(math_oper == '+' or math_oper == '-' or math_oper == '*' \
        or math_oper == '/' or math_oper == '**' \
        or math_oper.upper() == 'F' \
        or math_oper == '!'\
        or math_oper.upper() == 'EXIT' or math_oper.upper() == 'N'\
        or math_oper == '%'):
        return math_oper
    else:
            print "Invalid operator selected. Try again."
            math_oper = operator_input()
            
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

keep_going = True
x = get_user_input()
y = get_user_input()
while keep_going == True:
    
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
            total = lambda x,y: float(x) / float(y) 
    elif (math_oper == '%'):
        total = lambda x,y: x % y      
    elif (math_oper == '**'): 
        total  = lambda x,y: x ** y
    elif (math_oper.upper() == 'F'): 
        fib = lambda n:reduce(lambda x, n: [x[1], x[0] + x[1]], \
                                    range(n), [0,1])[0]
    elif (math_oper == '!'):
        fact = lambda x: 1 if x == 0 else x * fact(x-1)
    elif(math_oper.upper() == 'N'):
        x = get_user_input()
        y = get_user_input()
        continue
    elif (math_oper.upper() == 'EXIT'):
        print "Exiting now..."
        keep_going = False
        break
    if math_oper in ["+", "-", "/", "*", "**", "%"]:
        output = total(x, y)
        print("\nThe result of {} {} {} is {}").format(
                x, math_oper, y, output)
    elif math_oper.upper() == "F":
        choice = raw_input("Perform Fibonacci Sequence on x or y?").rstrip()
        if (choice.upper() == 'X'):
            if (x >= 100000):
                print "Large Numbers don't work well with Fibonacci."
            else:
                output = fib(x)
                print("The fibonacci number at position {} is {}").format(
                    x, output)               
        elif (choice.upper() == 'Y'):
            if (y >= 100000):
                 print "Large Numbers don't work well with Fibonacci."
            else:
                output = fib(y)
                print("The fibonacci number at position {} is {}").format(
                    y, output)
        else:
            print "Unknown variable."
            continue        
    elif math_oper == "!":
        choice = raw_input("Run Factorial on x or y?").rstrip()
        if (choice.upper() == 'X'):
            if (x >= 980):
                print "Number exceeds factorial depth"
            else:
                output = fact(x)
                print("{}{} is {}").format(
                    x, math_oper, output)
        elif (choice.upper() == 'Y'):
            if (y >= 980):
                print "Number exceeds factorial depth"
            else:
                output = fact(y)
                print("{}{} is {}").format(
                    y, math_oper, output)
        else:
            print "Unknown variable."
            continue