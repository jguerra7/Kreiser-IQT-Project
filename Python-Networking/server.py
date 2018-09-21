from socket import *

def serverIPv4():
    s = socket(AF_INET, SOCK_STREAM)
    s.bind(("", 15000))
    s.listen(5)
    c,a = s.accept()

   
