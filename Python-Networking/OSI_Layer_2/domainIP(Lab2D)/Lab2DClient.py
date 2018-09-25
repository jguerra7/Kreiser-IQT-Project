# Name: William Kreiser
# Date: 21 Sept 18
# Project: Domain/IP(Server) Lab2d

"""
Write a simple socket program that will ask a user to enter a domain and pull the IP address from a remote website.
"""
from socket import *

url = raw_input("Enter a URL (Ex: www.outlook.com): ")
url_ip = gethostbyname(url)
print("Domain Name: {}\nIP Address: {}".format(url, url_ip))
domain_info = gethostbyaddr(url_ip)
print domain_info
