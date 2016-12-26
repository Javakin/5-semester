#!/usr/bin/python

import zmq
import random
import sys
import time

# setup port
port = "5556"
if len(sys.argv) > 1:
    port =  sys.argv[1]
    int(port)

# setup port
context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:%s" % port)

mouse = open('/dev/input/mice', 'rb')

data, dx, dy = mouse.read(3)

mouse.close()

s = str(dx) + " " + str(dy)
print s


while True:
    print "%d %d" % (10001, 10)
    socket.send("%d %s" % (10001, "Hello World"))
    time.sleep(1)
