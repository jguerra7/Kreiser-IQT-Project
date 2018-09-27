# Name: William Kreiser
# Date: 26 Sep 18
# Project: TCP Chat(Server)

"""
Create a simple TCP chat server that connects to multiple clients using IPv4 and either Select() or Threading. 
Then echo back data to all clients using broadcasts (Use multiple VM's and track traffic in Wireshark)
"""

import socket, select

#Creating the server socket and binding it
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#Reuse the socket even if the timed_wait hasn't expired
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind(('', 9876))
server.listen(10)

#List to keep track of server and clients
inputs = [server]
running = 1

while running:
    #input, output 
    inready, outready, excready = select.select(inputs, [], [])
    
    for s in inready:
        if s == server:
            #accept the connection
            client, address = server.accept()
            #append the new client socket obj to the inready list
            inready.append(client)
        
        else:
            data = s.recv(1024)
            #To different ways to exit the program
            if data.upper() == 'EXIT':
                print "Exiting"
                exit(0)
            elif data.upper() == 'QUIT':
                print "Quitting"
                exit(0)
            else:
                #for loop to send to all sockets inside inready list
                for client in inready:
                    #Passes by if the obj is Server socket
                    if client == server:
                        continue
                    #Send to everyone
                    else:
                        client.send(data)

s.close()