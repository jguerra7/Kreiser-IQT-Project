import socket, sys
from struct import *

s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_RAW)

# tcp header fields
tcp_source = 1234   # source port
tcp_dest = 80   # destination port
tcp_seq = 454
tcp_ack_seq = 0
tcp_doff = 5    #4 bit field, size of tcp header, 5 * 4 = 20 bytes
#tcp flags
tcp_fin = 0
tcp_syn = 1
tcp_rst = 0
tcp_psh = 0
tcp_ack = 0
tcp_urg = 0
tcp_window = socket.htons (5840)    #   maximum allowed window size
tcp_check = 0
tcp_urg_ptr = 0
 
tcp_offset_res = (tcp_doff << 4) + 0
tcp_flags = tcp_fin + (tcp_syn << 1) + (tcp_rst << 2) + (tcp_psh <<3) + (tcp_ack << 4) + (tcp_urg << 5)
 
# the ! in the pack format string means network order
tcp_header = pack('!HHLLBBHHH' , tcp_source, tcp_dest, tcp_seq, tcp_ack_seq, tcp_offset_res, tcp_flags,  tcp_window, tcp_check, tcp_urg_ptr)

# The construction of the tcp header is similar to the ip header.  
# A pseudo header is constructed to compute the checksum. 
# The checksum is calculated over the tcp header along with the data. 
# Checksum is necessary to detect errors in the transmission on the receiver side.