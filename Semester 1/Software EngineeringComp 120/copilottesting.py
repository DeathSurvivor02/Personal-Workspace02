import math

# Using the math module to calculate the square root of 16
result = math.sqrt(16)
print("The square root of 16 is:", result)

# Defining a function to calculate the area of a circle
def calculate_area(radius):
    return math.pi * radius ** 2

# Using the function to calculate the area of a circle with radius 5
area = calculate_area(5)
print("The area of a circle with radius 5 is:", area)

# Defining a class with a method to calculate the circumference of a circle
class Circle:
    def __init__(self, radius):
        self.radius = radius

    def calculate_circumference(self):
        return 2 * math.pi * self.radius

# Creating an instance of Circle with radius 5
circle = Circle(5)
circumference = circle.calculate_circumference()
print("The circumference of a circle with radius 5 is:", circumference)d