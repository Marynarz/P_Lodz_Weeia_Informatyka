#!/usr/bin/python

import socket
import sys

print 'Witaj w serwerze'
proto = socket.getprotobyname('tcp')
sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM,proto)

sock.bind(('localhost',9999))
sock.listen(1)

while True:
    conn,adress = sock.accept()
    print 'Odebrano polczenie z: ' , adress
    while True:
      data = conn.recv(64)
      if data:
	conn.send(data[::-1])
	print data
      else:
	break
      
    conn.close()
    print 'Bajo!'
    break

print 'END'

