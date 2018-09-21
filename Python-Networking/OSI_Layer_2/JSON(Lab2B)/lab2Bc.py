# Name: William Kreiser
# Date: 21 Sept 18
# Project: JSON String (Client)

from socket import *
import json

"""
Write a UDP sender that takes a dictionary, turns it into a JSON string, and sends it to a listener.
"""

s = socket(AF_INET, SOCK_DGRAM)
msg = {}
msg = { '1' : 'Hello World', '2' : 'Goodbye World', '3' : 'End of World'}
#json.dumps() saves the msg
loaded_msg = json.dumps(msg)
s.sendto(loaded_msg ,("localhost", 10000))

data, addr = s.recvfrom(1024)
print data
print addr

s.close()