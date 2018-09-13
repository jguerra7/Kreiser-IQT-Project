#Hard coding input values
x = 25
y = 33
z = 15

print "Values before calculation: x: {} and y: {} and z: {}".format(x, y, z)
#Subtotal is used to contain the sum before taxes
subtotal = x + y + z
print "Subtotal: {}".format(subtotal)

#tax is used to calculate how much to add to subtotal for taxes
tax = subtotal * .10
print "Tax: {}".format(tax)
#Total will contain subtotal plus tax after it has been multiplied
total = subtotal + tax
print "Your total is: {}".format(total)