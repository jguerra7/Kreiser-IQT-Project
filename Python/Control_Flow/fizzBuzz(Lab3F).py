# Name: Will Kreiser
# Date: 10 Sep 18
# Project: FizzBuzz Lab 3F

"""
Iterate through a loop 100 times... printing Fizz for any number divisable by 3 
and Buzz for any number divisable by 5. 
If the number is divisable by both... print FizzBuzz. 
All other numbers... print the number. 

One version which is as short as possible
Another version which is as drawn out and creative as possible

I included counts for Fizz, Buzz, and FizzBuzz
I also took user input for number range
"""                                                                                                                                       

                                                                                                                                            
def fizzbuzz(n):
    #If n modulus division by 3 and 5 return "FizzBuzz"
    if n % 3 == 0 and n % 5 == 0:
        return 'FizzBuzz'
    #If n modulo 3 return "Fizz"
    elif n % 3 == 0:
        return 'Fizz'
    #If n modulo 5 return "Buzz"
    elif n % 5 == 0:
        return 'Buzz'
    #Else return number
    else:
        return str(n)
#Function to check user input
def get_user_input():
    userInput = raw_input("Please enter a number: ").rstrip()
    try:
        userInput =int(userInput)
    except ValueError:
        print("Try again.\n")
        userInput = get_user_input()
    return userInput


#Fizz, Buzz, FizzBuzz counters
fbCount, bCount, fCount = 0, 0, 0
#User input here
n = get_user_input()            
#prints based on modulo division in fizzbuzz function                                                                                                                                 
print "\n".join(fizzbuzz(n) for n in xrange(1, n))
#Counts occurences of Fizz, Buzz, or FizzBuzz in n range
for n in xrange(1, n):
    if (fizzbuzz(n) == 'Fizz'):
        fCount += 1
    elif (fizzbuzz(n) == 'Buzz'):
        bCount += 1
    elif (fizzbuzz(n) == 'FizzBuzz'):
        fbCount += 1
    else:
        continue
#Prints the occurences of Fizz, Buzz, and FizzBuzz in n range
print("Fizz count: {}\nBuzz count: {}\nFizzBuzz count: {}")\
    .format(fCount, bCount, fbCount)

#Shortest FizzBuzz program 
#print '\n'.join("Fizz"*(i%3==0)+"Buzz"*(i%5==0) or str(i) for i in range(1,n)) 