#!/usr/bin/python

def filterFunc(ln):
    return ln.upper()

#!/usr/bin/python
from pymouse import PyMouse

def getXVal():
	mouse = PyMouse()
    return mouse.position()[0]
   

def getYVal():
    mouse = PyMouse()
    return mouse.position()[1]
   
    
def SetPointer(s):
    mouse = PyMouse()
    
    mouse.move(xVal,yVal)
    return 0

