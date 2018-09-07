def fizzbuzz(n):

    if n % 3 == 0 and n % 5 == 0:
        return 'FizzBuzz'
    elif n % 3 == 0:
        return 'Fizz'
    elif n % 5 == 0:
        return 'Buzz'
    else:
        return str(n)

def get_user_input():
    userInput = raw_input("Please enter a number: ").rstrip()
    try:
        userInput =int(userInput)
    except ValueError:
        print("Try again.\n")
        userInput = get_user_input()
    return userInput

n = get_user_input()

print "\n".join(fizzbuzz(n) for n in xrange(1, 21))



