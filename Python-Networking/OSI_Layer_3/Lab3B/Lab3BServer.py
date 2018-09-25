# Name: William Kreiser
# Date: 24 Sep 18
# Project: Lab3B

"""
Write a UDP receiver that receives a string, 
and orders the words from longest to shortest in a new string.

That new string should be sent to the remote port + 1.

(i.e. the source port of message from the SENDER's POV)
"""

from socket import *

s = socket(AF_INET, SOCK_DGRAM)
s.bind(("",10000))

while True:
    try:
        data, addr = s.recvfrom(1024)
        print "Connection received from {}.".format(addr)
        print data
        #Create a new string
        newString = data.split(" ")
        print newString    
        #sort the string by length of word
        sortStr = sorted(newString, key=len, reverse=True)
        returnString = ' '.join(sortStr)     
        print returnString
        newAddr = (addr[0], addr[1] + 1)
        print newAddr

        r = socket(AF_INET, SOCK_DGRAM)
<<<<<<< HEAD
        r.sendto(returnString, newAddr)
        r.close()
    except (KeyboardInterrupt): 
        print "Exiting..."
        break
        
=======
        r.sendto(returnString, addr)
    except (KeyboardInterrupt):
        print "Exiting"
        break
>>>>>>> 61c478603f66c66777be263c455f976fe7eca830

s.close()
