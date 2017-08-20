#!/usr/bin/python

import socket

proto = socket.getprotobyname('tcp')
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto)

try:
  sock.connect(('localhost',9999))
  sock.send('Hello World')
  
  resp = sock.recv(1024)
  print resp
except socket.error:
  pass
finally:
  sock.close()