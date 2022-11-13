""" Define a function myfunc that takes in an arbitrary number of arguments, and returns the sum of those arguments. """

# from ctypes import sizeof

def myfunc(*args):
	sum = 0
	sum= sum + args
	print (sum)

myfunc(3,4,5,6,7)


# def manyArgs(*arg):
#     print("I was called with", len(arg), "arguments:", arg)


# manyArgs(1,2,3,4,5,6,7)