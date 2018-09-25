# Name: William Kreiser
# Date: 21 Sept 18
# Project: Hostname/IP(Server) Lab2c

from socket import *

s = socket(AF_INET, SOCK_DGRAM)

msg = "I took some stuff and left"
print("Thank you!!! {}".format(msg))
s.sendto(msg,("localhost", 15000))

data, addr = s.recvfrom(1096)
print("Received data: {}".format(data))
print("From: {}".format(addr))
