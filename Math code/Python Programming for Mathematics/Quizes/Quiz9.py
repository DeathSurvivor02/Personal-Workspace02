""" Write a Python function point_distance that takes as the parameters x0, y0, x1 and y1, 
and returns the distance between the points (x0,y0) and (x1,y1).
Hint: You need to use the power operation ** . There is no need to use the math module. """
import math  

def point_distance(x0, y0, x1, y1):
	value = math.sqrt(pow((x0-x1),2)+pow((y0-y1),2))
	return value
	
point_distance()

