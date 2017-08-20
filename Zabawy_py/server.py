#!/usr/bin/python

import socket
import sys

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

sock.bind(('localhost',9999))
scok.listen(1)

while True:
    conn,adress = sock.accept()
    while True:
      data = conn.recv(64)
      if data:
	conn.send(data[::-1])
	print data
      else:
	break
      
    conn.close()

print END
