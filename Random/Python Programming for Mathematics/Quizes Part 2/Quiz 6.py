""" Given numbers a, b, and c, the quadratic equation ax2+bx+c=0 can have zero, one or two real solutions (i.e; values for x that satisfy the equation). The quadratic formula x=−b±b2−4ac√2a can be used to compute these solutions. 
The expression b2−4ac is the discriminant associated with the equation. If the discriminant is positive, the equation has two solutions. If the discriminant is zero, the equation has one solution. Finally, if the discriminant is negative, the equation has no solutions. 

Write a Python function smaller_root that takes an input the numbers a, b, c and returns the smaller solution to this equation if one exists. If the equation has no real solution, return the message "Error: No real solutions". Similarly, if a has the value 0, return the message "Error: Not a quadratic equation". """

import math

def smaller_root(a, b, c):
    if (a == 0):
        return ("Error: Not a quadratic equation")
    discriminant = math.pow(b, 2) - 4 * a * c
    if discriminant < 0:
        return ("Error: No real solutions")
    else:
        x2 = -b - math.pow(b, 2) - 4 * a * c * math.sqrt(2 * a)
        x1 = -b + math.pow(b, 2) - 4 * a * c * math.sqrt(2 * a)
        if (x1 > x2):
            return x1
        else:
            return x2
