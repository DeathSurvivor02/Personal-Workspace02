""" Please write a function volume_in_sphere that calculates liquid volume in a sphere using the following formula involving the parameters hc, the cap height, and r, the radius of the sphere. The radius r is usually 10, so make it a default parameter. 

Import the value of π from the module math. """
import math


def volume_in_sphere(h,r=10):
	liquid_volume = ((4 * math.pi * math.pow(r, 3)) / 3) - (math.pi * math.pow(h, 2) * (3 * r - h))/3
	return liquid_volume
