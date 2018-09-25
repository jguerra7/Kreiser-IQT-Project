# Name: William Kreiser
# Date: 21 Sept 18
# Project: Domain/IP(Server) Lab2d

from socket import *

domainName=raw_input("Enter a web address: ")
ipaddr=getaddrinfo(domainName)
print "Domain Name: {}\nIPAddress: {}".format(domainName,ipaddr)
nameinfo=getnameinfo(ipaddr)
print nameinfo