# Name: William Kreiser
# Date: 26 Sep 18
# Project: Performance lab

"""
    Create a TCP client using IPv4.
    Pack the following values in a struct using network byte order: 12345, 56789, &, *, 0x7d0, 0b11111010000. 
    Then send the packed struct to a TCP server and print the unpacked values.
"""
import struct, socket

#Make the connection
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("",15000))
s.listen(5)
#accept the connection
c,a = s.accept()
data = c.recv(1024)
#Network bytes order
unpacked_data = struct.unpack('!iiccii', data)
#print unpacked_data
for i in xrange(len(unpacked_data)):
    #if less than 4 print normally
    if i < 4:
        print unpacked_data[i]
    #if i equals 4, convert to hex and print
    elif i == 4:
        print hex(unpacked_data[4])
    #if i equals 5, convert to binary and print
    else:
        print bin(unpacked_data[5])
#close the socket
s.close()