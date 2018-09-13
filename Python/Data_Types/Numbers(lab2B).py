"""Python2 lab2b"""
print "==================================="

x = 545
y = 24
binX = bin(x)
binY = bin(y)

print "{} is {} in binary. {} is {} in binary.".format(x, binX, y, binY)

print "Values before modification: x: {} and y: {}".format(x, y)

# TODO: manually flip the third bit in x
x = x ^ 4

# TODO: manually flip the 1st bit in y
y = y ^ 1

print "Values after modification: x: {} and y: {}".format(x, y)

# NOTE: You may need to add additional re-asignments for the TODOs below
# TODO: sum of x and y as a hex value
answer1 = hex(x+y)

# TODO: difference of x minus y as int
answer2 = x - y

# TODO: product of x and y as octal
z = x * y
answer3 = oct(z)

# TODO: quotient of x divided by y as binary
z = x / y
answer4 = bin(z)

# TODO: x modulus 3 as int
z = x % 3
answer5 = int(x%3)

# TODO: y squared as int
answer6 = int(y**2)

print "1: {}\n2: {}\n3: {}\n4: {}\n5: {}\n6: {}\n \b===================================".format(answer1, answer2, answer3, answer4, answer5, answer6)

# TODO: Using prefixes and conversions:
## TODO: Set binA == 0011, set binB to 1001
binA = 0b0011
binB = 0b1001

## TODO: binA AND binB, assign the value to binC
binC = (binA & binB)

## TODO: Set decA to decimal version of binA, set decB to decimal version of binB
decA = binA
decB = binB

## TODO: Set binA to bin representation of binA, set binB to the bin representation of binB
binA = bin(binA)
binB = bin(binB)

print "Results:\n-Decimal- A: {} B: {}\n-Binary- A: {} B: {}".format(decA, decB, binA, binB)