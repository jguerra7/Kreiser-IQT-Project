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