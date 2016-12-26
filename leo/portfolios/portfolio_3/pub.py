#!/usr/bin/python

import zmq
import random
import sys
import time

# setup port
port = "5556"
#if len(sys.argv) > 1:
#    port =  sys.argv[1]
#    int(port)

# setup port
context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:%s" % port)


mouse = open('/dev/input/mice', 'rb')

while True:
	status, dx, dy = tuple(ord(c) for c in mouse.read(3))

	def to_signed(n):
		return n - ((0x80 & n) << 1)

	dx = to_signed(dx)
	dy = to_signed(dy)
	
	print "%#02x %d %d" % (status, dx, dy)
	socket.send("%d %#02x %d %d" % (10001, status, dx, dy))
	#time.sleep(1)

mouse.close()










