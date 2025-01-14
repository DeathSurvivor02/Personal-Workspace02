
""" Write a Python function circle_circumference that takes a single parameter
	radius corresponding to the radius of a circle in centimeters and returns the 
	circumference of a circle with radius in centimeters. Do not use π=3.14, 
	instead use the math module to supply a higher-precision approximation to π. """
import math 

def circle_circumference(radius):
    return(2*math.pi * radius)
