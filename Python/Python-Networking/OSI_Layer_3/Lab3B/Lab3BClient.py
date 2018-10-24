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

#Create a string a send it
senderStr = "Confucius says He who stands on toilet is high on pot."
print senderStr
s.sendto(senderStr, ("192.168.31.132", 10000))
addr = s.getsockname()
s.close()

#open a new socket to receive data back
s = socket(AF_INET, SOCK_DGRAM)
s.bind((addr[0], addr[1] +1))

resp, addr = s.recvfrom(1024)
print resp

s.close()