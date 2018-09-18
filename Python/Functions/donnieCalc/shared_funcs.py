#The expression variable a string of the entire equation when the user presses 
#buttons on the calculator it is used by all functions.
import calcGUI as cg
from math import sqrt

expression = ""  

def press(num):
    """This is the function that adds all of the button 
    presses to the text box of the calculator.
    """ 
    global expression 
    expression = expression + str(num)
    #Once we add the new button press entry to the expression 
    #add it to the equation string var. 
    cg.equation.set(expression) 
  
def equals():
    """Handles the math for the equation when the user presses 
    equals
    """ 
    #The try except here catches if the user inputs anything that
    #wouldn't make sense IE putting letters in
    try: 
        global expression 
        total = str(eval(expression)) 
        cg.equation.set(total) 
        expression = ""
    except: 
        cg.equation.set(" error ") 
        expression = "" 
  
def clear(): 
    """Clears the StringVar equation as well as the global 
    string expression
    """
    global expression 
    expression = "" 
    cg.equation.set("0")

def fibIt():
    """Calculates the fibonacci number up the the digit in the 
    entry field
    """
    global expression
    #Check to see if there is any special characters (math signs).
    if expression.isdigit() == True:
        #Pull out the integer and store in n.
        n = int(expression)
        #Since fibonacci starts slowing down after 35, I have decided 
        # to limit it to 35 iterations.
        if n < 35:
            currentFib = 1
            lastFib = 0
            for i in xrange(n):
                temp = currentFib + lastFib
                lastFib = currentFib
                currentFib = temp
            expression = str(currentFib)
            cg.equation.set(expression)
        else:
            cg.equation.set(" error too large ")
    else:
        cg.equation.set(" error invalid number")

def square_root():
    """Calculates the square root of the number in the entry field."""
    global expression
    #Check to make sure we don't have any special characters.
    if expression.isdigit() == True:
        n = int(expression)
        #Cannot sqrt negative numbers.
        if n > 0:
            #calculate the square root and store it in the expression.
            result = sqrt(n)
            expression = str(result)
            cg.equation.set(expression)
        else:
            cg.equation.set(" error number must be positive")
    else:
        cg.equation.set(" error input must only be a positive integer")