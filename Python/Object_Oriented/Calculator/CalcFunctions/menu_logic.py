# Name: William Kreiser
# Date: 13 Sep 18
# Project: Calculator Lab5A

import calcFunctions as cf

def menu_logic():

    keep_going = True
    x = cf.get_user_input()
    y = cf.get_user_input()
    while keep_going == True:
        
        math_oper = cf.operator_input()
        if (math_oper == '+'): 
            total = lambda x, y: x + y
        elif (math_oper == '-'): 
            total = lambda x,y: x - y
        elif (math_oper == '*'): 
            total = lambda x,y: x * y
        elif (math_oper == '/'): 
            if (y == 0):
                print "Armageddon has been triggered. Division by 0 detected."
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
            x = cf.get_user_input()
            y = cf.get_user_input()
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