#   Name: William Kreiser
#   Date: 19 Sep 18
#   Project: Lab1A-1D

from socket import *
"""This file contains several functions that are individual pieces of the same lab.
If you try to run this is VS Code it will not run due to the server listening each time.
I packaged them in one file for portability"""

""" The next two functions are for IPv4 TCP Sockets """
#Lab1A
def tcpClient():
    s = socket(AF_INET, SOCK_STREAM)
    s.connect(("localhost", 15000))

    s.send("Hello World")
    resp = s.recv(1024)

    print resp

#Lab1A
def tcpServer():
    s = socket(AF_INET, SOCK_STREAM)
    s.bind(("",15000))
    s.listen(5)

    c,a = s.accept()
    print a

    data = c.recv(1024)
    print data

    c.send("Hello Yourself")

""" The next two functions are for IPv4 UDP Sockets """
#Lab1C
def udpClient():
    s = socket(AF_INET, SOCK_DGRAM)
    msg = "Hello World"
    s.sendto(msg,("localhost", 10000))

    data, addr = s.recvfrom(1024)
    print data
    print addr

#Lab1C
def udpServer():
    s = socket(AF_INET, SOCK_DGRAM)
    s.bind(("",10000))

    while True:
        data, addr = s.recvfrom(1024)
        print data
        print addr
        resp = "AH AH AH!!! YOU DIDN'T SAY THE MAGIC WORD!!!"
        s.sendto(resp,addr)

""" IPv6 TCP functions"""
#Lab1B
def IPv6Client():
    s = socket(AF_INET6, SOCK_STREAM)
    s.connect(("localhost",15000))

    s.send("Hello World")

    resp = s.recv(1024)
    print resp

    s.recv(1024)

#Lab1B
def IPv6Server():
    s = socket(AF_INET6, SOCK_STREAM)
    s.bind(("",15000))
    s.listen(5)
    c,a = s.accept()

    data = c.recv(1024)

    c.send("Hello Yourself")

    c.send("Goodbye")
    c.close()

""" UDP IPv6 Functions"""
#Lab1D
def udpIPv6Client():
    s = socket(AF_INET6, SOCK_DGRAM)

    msg = "no more world..."
    s.sendto(msg,("localhost", 15000))

    data, addr = s.recvfrom(1096)
    print data
    print addr
#Lab1D
def udpIPv6Server():
    s = socket(AF_INET6, SOCK_DGRAM)
    s.bind(("",15000))

    while True:
        data, addr = s.recvfrom(1096)
        print data
        print addr
        resp = "Good copy"
        s.sendto(resp, addr)

print "TCP IPv4 Output"
tcpServer()
tcpClient()

print "UDP IPv4 output"
udpServer()
udpClient()

print "TCP IPv6 output"
IPv6Server()
IPv6Client()

print "UDP IPv6 output"
udpIPv6Server()
udpIPv6Client()