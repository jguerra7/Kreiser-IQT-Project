# Name: William Kreiser
# Date: 24 Sep 18
# Project: Lab3B

"""

Write a UDP sender that sends the initial string, and receives the response 
from the receiver above (you can use multiple receivers or combine them).

Hint: The second step is intentionally ambiguous on how to proceed. There are multiple solutions.
"""


import struct
from socket import *

#Socket setup
s = socket(AF_INET, SOCK_DGRAM)
addr = s.getsockname()
port = addr[1] +1

#Create a string a send it
senderStr = "He who stands on toilet is high on pot."
s.sendto(senderStr, (addr, port))
s.close()

#open a new socket to receive data back
s = socket(AF_INET, SOCK_DGRAM)
s.bind((addr[0], port))

resp, addr = s.recvfrom(1024)
print resp

s.close()