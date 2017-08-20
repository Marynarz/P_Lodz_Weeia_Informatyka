#!/usr/bin/python

import socket
import sys

print 'Witaj w serwerze'

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

sock.bind(('localhost',9999))
sock.listen(1)

while True:
    conn,adress = sock.accept()
    print 'Odebrano polczenie z: %s %s' % conn, adress
    while True:
      data = conn.recv(64)
      if data:
	conn.send(data[::-1])
	print data
      else:
	break
      
    conn.close()
    print 'Bajo!'

print 'END'
