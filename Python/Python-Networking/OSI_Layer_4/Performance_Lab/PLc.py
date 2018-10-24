# Name: William Kreiser
# Date: 26 Sep 18
# Project: Performance lab

"""
    Create a TCP client using IPv4.
    Pack the following values in a struct using network byte order: 12345, 56789, &, *, 0x7d0, 0b11111010000. 
    Then send the packed struct to a TCP server and print the unpacked values.
"""
import socket, struct

#pack the struct
packed_data =  struct.pack('!iiccii', 12345, 56789, '&', '*', 0x7d0, 0b11111010000)

#Make the socket and connection
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("localhost", 15000))
#send the data
s.send(packed_data)
#close the socket
s.close()