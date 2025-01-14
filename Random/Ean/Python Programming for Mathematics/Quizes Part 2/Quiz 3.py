import math

def triangle_area(x0, y0, x1, y1, x2, y2):
	A = point_distance(x0, y0, x1,y1)
	B = point_distance(x0,y0, x2,y2)
	C = point_distance(x1,y1, x2,y2)
	s = (A+B+C)/2
	triangle_area = s(s-A)(s-B)(s-C)
	print (triangle_area)



# def point_distance(x0, y0, x1, y1):
# 	distance = math.sqrt(pow((x0-x1),2)+pow((y0-y1),2))
# 	return distance



def point_distance(x0, y0, x1, y1):
	distance = (((x0-x1)**2)+((y0-y1)**2))**(1/2)
	return distance
	

triangle_area(2,3,2,8,5,9)