""" Write a function that accepts a number from the user, 
calculates the cube of the number using another function, and then returns the result. """

from math import *


def cube():
    x = int(input("Enter a number: "))
    return pow(x, 3)


x = cube()

mixed_list = ["hello", 2.0, 5 * 2, [10, 20], [3, 4, 6 * 6]]
print("The cube of the number is:", x)
print("The mixed list is:", mixed_list)
print("The length of the mixed list is:", len(mixed_list))
