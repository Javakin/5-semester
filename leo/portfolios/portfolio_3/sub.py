#!/usr/bin/python

import sys
import zmq
from pymouse import PyMouse

port = "5556"
#if len(sys.argv) > 1:
#    port =  sys.argv[1]
#    int(port)
    
#if len(sys.argv) > 2:
#    port1 =  sys.argv[2]
#    int(port1)

# Socket to talk to server
context = zmq.Context()
socket = context.socket(zmq.SUB)

print "Subscribing port: %s" % port
socket.connect ("tcp://192.168.1.145:%s" % port)

#if len(sys.argv) > 2:
#    socket.connect ("tcp://192.168.1.145:%s" % port1)
    
# Subscribe to zipcode, default is NYC, 10001
topicfilter = "10001"
socket.setsockopt(zmq.SUBSCRIBE, topicfilter)

# Recieve mouse envents 
mouse = PyMouse()
workSpace = mouse.screen_size()

while True:
	string = socket.recv()
	temp = string.split(" ")
	dx = int(temp[2])
	dy = int(temp[3])
	
	print int(temp[2]), int(temp[3])
	
	# move pointer
	xVal = dx + mouse.position()[0]
	yVal = mouse.position()[1] - dy
	
	if xVal < 0:
		xVal = 0
		
	if xVal >= workSpace[0]:
		xVal = workSpace[0] - 1
		
	if yVal < 0:
		yVal = 0
		
	if (yVal >= workSpace[1]):
		yVal = workSpace[1] - 1

	mouse.move(xVal,yVal)


    
    
























