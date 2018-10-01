# Name: William Kreiser
# Date: 26 Sep 18
# Project: Raw UDP Server Socket

from socket import *
import struct

#IP address and port
ip_addr = ''
port = 5001

#Create the socket
s = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)
s.bind((ip_address, port))

#Receive all of the datas
c,a = s.recvfrom(1024)
data = c
print(data[46::])

#Receive more datas
c,a = s.recvfrom(1024)
data = c
print(data[46::])

#still more reception of datas
c,a = s.recvfrom(1024)
data = c
print(data[46::])

#Turn off the pitching machine of datas
s.close()