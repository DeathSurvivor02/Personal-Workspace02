""" Define a function called myfunc that takes in an arbitrary number of arguments, and returns a list containing only those arguments that are even.

E.g., myfunc(5,6,7,8) should return [6, 8] """


def myfunc(*args):
    list = []
    len(args)
    for i in range(len(args)):
        if args[i] % 2 == 0:
            list.append(args[i])
    print (list)
	# print (list)

myfunc(1,2,3,4,5,6)

