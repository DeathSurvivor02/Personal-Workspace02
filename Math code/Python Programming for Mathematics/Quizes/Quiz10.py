# Write a Python function name_and_age that take as input the parameters name (a string) and age (a number) and returns a string of the form "% is % years old." where the percents are the string forms of name and age. The function should include an error check for the case when age is less than zero. In this case, the function should return the string "Error: Invalid age".


def name_and_age(name, age):
	print("%s is %i",name, age)
	return ("%s is %i",name, age)

name_and_age("Ean", 20)