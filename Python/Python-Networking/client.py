from socket import *

def clientIPv4():

    s = socket(AF_INET, SOCK_STREAM)
    s.connect(("localhost", 15000))

clientIPv4()
