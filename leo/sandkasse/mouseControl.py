#!/usr/bin/python
from pymouse import PyMouse
import sys

def publisher(s):
	# publisher side
	#mouse = PyMouse()
	
	mouse = open('/dev/input/mice', 'rb') 
	
	data = mouse.read(3)
	dx = data[1]
	dy = data[2]
	mouse.close()

	s = str(dx) + " " + str(dy)
	print s
	return s
   
   
    
def subscriber(s):
	# setup
	print s
	mouse = PyMouse()
	temp = s.split(" ")
	workSpace = mouse.screen_size()
	
	# convertering
	dx = int(temp[0])
	if (int(temp[0])>125):
		dx = dx - 255
	
	dy = int(temp[1])
	if (int(temp[1])>125):
		dy = dy - 255
	
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

	#print xVal, " ", yVal
	mouse.move(xVal,yVal)
	return s

