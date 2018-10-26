# Name: William Kreiser
# Date: 24 Sep 18
# Project: Lab3B


""" 
sing the struct package from the python library, pack the values (1, 2, -3, -4) 
as the following data types (unsigned short, unsigned int, signed short, signed int)

1 as an unsigned short
2 as an unsigned int
-3 as a signed short
-4 as a signed int
Write a TCP client that packs those values, sends the packed string to a server.

Write a TCP server that receives the string, unpacks it using little endian and prints it, 
then unpacks it again using big endian and prints it.
"""

import struct
from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.bind(("",15000))
s.listen(5)

c,a = s.accept()
data = c.recv(1024)
#Little Indian
print struct.unpack('<HIhi', data)
#Big Endian 
print struct.unpack('>HIhi', data)

s.close()