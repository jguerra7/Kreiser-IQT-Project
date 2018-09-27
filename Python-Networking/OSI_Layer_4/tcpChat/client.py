# Name: William Kreiser
# Date: 26 Sep 18
# Project: TCP Chat

"""
Create a simple TCP chat server that connects to multiple clients using IPv4 and either Select() or Threading. 
Then echo back data to all clients using broadcasts (Use multiple VM's and track traffic in Wireshark).
"""

import struct, socket

while True:
    sendmessage = raw_input("Would you like to send a message(Y/N)? ").rstrip()

    if sendmessage.upper() == 'Y':

        try:
            #client socket 1
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect(("192.168.31.132", 9876))
            
            #client socket 2
            t = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            t.connect(("192.168.31.132", 9876))
        
            #client socket 3
            u = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            u.connect(("192.168.31.132", 9876))           
            
            #Send and receive messages on 's' socket
            msgS1 = raw_input("Enter a message to send: ")
            s.send(str(msgS1))
            dataS1 = s.recv(1024)
            print msgS1
            print dataS1
            
            #Send and receive messages on 't' socket
            msgT1 = raw_input("Enter a message to send: ")
            t.send(str(msgT1))
            dataT1 = t.recv(1024)
            print msgT1
            print dataT1

            #Send and receive messages on 'u' socket
            msgU1 = raw_input("Enter a message to send: ")
            u.send(str(msgU1))
            dataU1 = u.recv(1024)  
            print msgU1
            print dataU1   

            s.close()
            t.close()
            u.close()       
        #Catch Ctrl-C
        except KeyboardInterrupt:
            print "You have stepped into the exit portal..."
    #user wants to exit
    elif sendmessage.upper() == 'N':
        
        print "Good-Bye."
        break
    #User doesn't listen
    else:
        print "That's not an option"
        continue
    


