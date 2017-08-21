#!/usr/bin/python
import sys
import socket
import getopt
import threading
import subprocess

#vars
listen = False
command = False
upload = False
execute = ""
target = ""
upload_destination = ""
port = 0

def usage():
  #help - tbd
  pass

def main():
  global listen
  global command
  global upload
  global executa
  global target
  global upload_destination
  global port
  
  #czy sa podane argumenty?
  if not len(sys.argv[1:]):
    usage()
    
  #odczytujemy z wiersza polecen
  try:
    opts,args = getopt.getopt(sys.argv[1:],"hle:t:p:cu:",["help","listen","execute","target","port","command","upload"])
  except getopt.GetoptError as err:
    print str(err)
    usage()
  
  #ustawianie parametrow
  for o,a in opts:
    if o in ("-h","--help"):
      usage()
    elif o in ("-l","--listen"):
      listen = True
    elif o in ("-e","--exceute"):
      execute = a
    elif o in ("-c","--command"):
      command = True
    elif o in ("-u","--upload"):
      upload_destination = a
    elif o in ("-t","--target"):
      target = a
    elif o in ("-p","--port"):
      port = inta(a)
    else:
      assert False,"blad!"