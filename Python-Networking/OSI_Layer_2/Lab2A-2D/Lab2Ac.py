# Name: William Kreiser
# Date: 21 Sept 18
# Project: Socket String Reversal (Client)

from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect(("localhost", 15000))

beforeReverse = "Ninjy num chucks. Don't go ninjin someone who don't need ninjin!! -Diamond Dave"
print beforeReverse
s.send(beforeReverse)

resp = s.recv(1024)
print resp