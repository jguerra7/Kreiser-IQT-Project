# Name: William Kreiser
# Date: 21 Sept 18
# Project: JSON string (Server)

from socket import *
import json
"""
Write the UDP receiver to receive the JSON string and turns it back into a dictionary.
Validate by printing the type of your dictionary variable (build in IPv4).
"""

s = socket(AF_INET, SOCK_DGRAM)
s.bind(("", 15000))

while True:
    data, addr = s.recvfrom(1024)
    print("Received data from: {}".format(addr))
    print("Received data type: {}".format(type(data)))
    print("Received data: {}".format(data))

    json_data = json.loads(data)
    print("\nConverted data type: {}".format(type(json_data)))
    print("Converted data: {}\n\n".format(json_data))

    resp = "AH AH AH!!! YOU DIDN'T SAY THE MAGIC WORD!!!"
    s.sendto(resp,addr)  