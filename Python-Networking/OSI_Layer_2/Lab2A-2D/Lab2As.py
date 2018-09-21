# Name: William Kreiser
# Date: 21 Sept 18
# Project: Socket String Reversal (Server)

"""Write a TCP server that receives a string, reverses order of the words, 
and sends it back to the client."""

from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.bind(("",15000))
s.listen(5)

c,a = s.accept()
print a

data = []
data[0] = c.recv(1024)
print "String to reverse"
print data[0]

resp = data[0].reverse()
c.send("Gnirts Desrever")
c.send(data)
