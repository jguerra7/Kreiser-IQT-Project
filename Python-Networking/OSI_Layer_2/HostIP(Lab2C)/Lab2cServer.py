# Name: William Kreiser
# Date: 21 Sept 18
# Project: Hostname/IP(Server) Lab2c

from socket import *

s = socket(AF_INET, SOCK_DGRAM)
s.bind(("",15000))

while True:
    data, addr = s.recvfrom(1096)
    print("Received data from: {}".format(addr))
    print("Received data: {}".format(data))

    host_ip, unknown = addr
    h_name, unk, nown = gethostbyaddr(host_ip)

    print("Stolen IP: {}".format(host_ip))
    print("Stolen Hostname: {}\n\n".format(h_name))

    msg = "Host IP: " + host_ip + ", Hostname: " + h_name
    s.sendto(str(msg), addr)