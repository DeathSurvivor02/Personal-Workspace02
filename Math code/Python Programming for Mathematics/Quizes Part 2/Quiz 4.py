""" 
Write a Python function interval_intersect that takes parameters a, b, c, and d and returns True if the intervals [a,b] and [c,d] intersect and False otherwise. 

While this test may seem tricky, the solution is actually very simple and consists of one line of Python code. (You may assume that a≤b and c≤d.) """

def interval_intersect(a, b, c, d):
    return (c <= b) and (a <= d)