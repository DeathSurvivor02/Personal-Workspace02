# Functions to manipulate global variable count


count = 8 #arbitrary value of count
###################################################
# You should enter functions on the next lines.

# Reset global count to zero.
def reset():
	global count
	count = 0
#   print_count()




# Increment global count.
def increment():
	global count
	count += 1
#     print_count()
    # return count


# Decrement global count.
def decrement():
	global count
	count -= 1
#     print_count()
    # return count


# Print global count.
def print_count():
	print(count)


###################################################
# Test - don't change
# note that the GLOBAL count is defined inside a function
reset()
increment()
print_count()
increment()
print_count()
reset()
decrement()
decrement()
print_count()

####################################################
# Your output should be
#1
#2
#-2