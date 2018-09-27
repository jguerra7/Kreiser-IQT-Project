# Name: William Kreiser
# Date: 26 Sep 18
# Project: Raw UDP Client Socket

"""
Create a program using a Raw UDP socket in Python with an IPv4 header.
"""

import socket, struct
s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_UDP)

sourceIP = '192.168.31.131'
destIP = '192.168.31.132'

#IP header fields
ip_ihl = 5                      #IP Header Length
ip_ver = 4                      #IP version
ip_tos = 0                      #Type of Service
ip_tot_len = 0                  #Kernel will fill with correct total length
ip_id = 54321                   #ID of this packet
ip_frag_off = 0                 #Fragmentation offset
ip_ttl = 255                    #Packet time to live
ip_proto = socket.IPPROTO_UDP   #Packet Protocol
ip_check = 0                    #Kernel will fill the correct checksum
ip_saddr = socket.inet_aton ( sourceIP ) #You can fill with any source addr
ip_daddr = socket.inet_aton ( destIP )   #Destination IP addr
ip_ihl_ver = (ip_ver << 4) + ip_ihl      #IP Header length version

#Packing the struct in Network(!) bytes order
ip_header = struct.pack('!BBHHHBBH4s4s', ip_ihl_ver, ip_tos, ip_tot_len, ip_id,
ip_frag_off, ip_ttl, ip_proto, ip_check, ip_saddr, ip_daddr)

data = 'RAW SOCKET GIVE YOU ALL OF THE POWER!!!'
source_port = 5000      #Pick a source port
dest_port = 5001        #Pick a destination port
length = 8 + len(data)  #length of packet plus length of data
checksum = 0            #Checksum
udp_header = struct.pack('!HHHH', source_port, dest_port, length, checksum)

s.sendto(ip_header + udp_header + data, ('',0))

data = "POWER OVERWHELMING!!!"
s.sendto(ip_header + udp_header + data, ('',0))

data = "IT'S A GOOD DAY TO DIE"
s.sendto(ip_header+udp_header+data, ('',0))

s.close()