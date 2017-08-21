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