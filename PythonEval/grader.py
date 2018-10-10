#!/usr/bin/env python
# Name: William Kreiser
# Date: 9 Oct 18
# Project: Python-Networking Eval
import socket, struct

dest = ('10.128.102.222', 1337)
accept_port_1 = 12345
accept_port_2 = 54321

cmd_list = {
	'success' : 0x800,
	'error' : 0x801,
	'query_mode' : 0x802,
	'get_key' : 0x803,
}

padding = 0x0000

"""
  To accomplish this task, you will need to communicate with a server running on TCP port 1337 of 
 the grader system, using a fictional protocol. 

-> Each command you issue will need to consist of a struct with two unsigned 32-bit longs, a command from the
cmd_list (above), and either an optional argument, or padding.

-> The grader expects to receive this in network byte order, and will return results in network
byte order (with the exception of the result you will get back from the get_key command).

-> The grader will give you back one of three types of results: 'success', 'error' (followed by
zeros if a generic error occurred, or all f's if an exception occurred while processing your request),
and finally, a 32 byte string (when the get_key command is successfully received).

-> Finally, the grader will only accept your commands if you set your source port to the value it 
is expecting (further explained in the task breakout below).

-> You will need to perform the following actions: 
1.) send a "query_mode" command to the server, using accept_port_1 as your source port
2.) send a "get_key" command to the server, with the mode you got back from the previous command,
using accept_port_2 as your source port.
"""
if __name__ == '__main__':
	pass
#Create the connection to the server on TCP port 1337
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(("10.128.102.214", accept_port_1))
s.connect((dest))
# #Structs containing command and padding/argument
packed_data = struct.pack('!LL', cmd_list["query_mode"], padding)
s.send(packed_data)
#response from query_mode
data = s.recv(1024)
data = struct.unpack('!LL', data)
print data
#Close the Socket
s.close()

#Second socket for get_key
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(("10.128.102.214", accept_port_2))
s.connect((dest))
#send the second struct
packed_data = struct.pack('!LL', cmd_list["get_key"], 12648430)
s.send(packed_data)
#receive the key back
get_key_data = s.recv(1024)
print get_key_data

#Close the Socket
s.close()