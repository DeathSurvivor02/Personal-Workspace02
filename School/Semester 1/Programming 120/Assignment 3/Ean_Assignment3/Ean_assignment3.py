import csv
"""
This script performs the following tasks:
1. Creates a dictionary of countries and their respective medal counts, then displays the results.
2. Creates a list of countries and their respective medal counts, then displays the results.
3. Explains the difference between a list and a dictionary.
4. Reads NFL offensive stats from a CSV file, calculates the total passing yards for each quarterback, sorts them, and displays the results.
5. Defines a function to check if a password is strong.
6. Defines a function to determine the maximum number of new students that can sit in a row in a classroom.
Functions:
	is_strong_password(password):
		Checks if the given password is strong by ensuring it does not contain 'password' or 'qwerty'.
	most_students(classroom):
		Determines the maximum number of new students that can sit in a row in a classroom.
Variables:
	Medals_dict (dict): A dictionary containing countries and their respective medal counts.
	Medals_list (list): A list containing countries and their respective medal counts.
	qb_passing_yards (dict): A dictionary containing quarterbacks and their total passing yards.
	sorted_qb_passing_yards (list): A list of tuples containing quarterbacks and their total passing yards, sorted in descending order.
	classroom (list): A list of lists representing the seating arrangement in a classroom.
"""


# Use the above table data. Create a dictionary. Use for loop to display the results.
# Use the same data.. Create a list, display the result.
# Write your understanding of the difference between list and dictionary

# Description: Creation of a dictionary
Medals_dict =  {
	'Canada': [2, 0, 2],
	'OAR': [1, 2, 0],
	'Japan': [1, 1, 0],
	'China': [0, 1, 0],
	'Germany': [1, 0, 0] 
}
Information_dict = {
    "name": "Angel",
    "age": 25,
    "city": "New York"
}

print (Information_dict)
print (Information_dict["age"])
Information_dict["city"] = "Los Angeles" 

print("Nation \t\t Gold \t\t Silver \t Bronze")
# Display the country with the amount of medals they won
for country, medals in Medals_dict.items():
    print(f"{country} \t\t {medals[0]} \t\t {medals[1]} \t\t {medals[2]} ")

# Description: Creation of a list
Medals_list = [
    ['Canada', 2, 0, 2],
    ['OAR', 1, 2, 0],
    ['Japan', 1, 1, 0],
    ['China', 0, 1, 0],
    ['Germany', 1, 0, 0]
]

print("Nation \t\t Gold \t\t Silver \t Bronze")
# Display the country with the amount of medals they won
for country in Medals_list:
    print(f"{country[0]} \t\t {country[1]} \t\t {country[2]} \t\t {country[3]} ")

# Difference between List and Dictionary
# The main difference between a list and a dictionary is that a list is an ordered collection of items, while a dictionary is an unordered collection of items.

# Create a dictionary with the specified key-value pairs
person_info = {"name": "Angel", "age": 25, "city": "New York"}

# Print the dictionary
print(person_info)

# Access and print the value associated with the key "age"
print(person_info["age"])

# Update the "city" value to "Los Angeles"
person_info["city"] = "Los Angeles"

# Print the updated dictionary
print(person_info)

# Open the csv file and read in the data
with open('nfl_offensive_stats.csv', mode='r') as file:
	reader = csv.reader(file)
	next(reader)  # Skip the header row
	qb_passing_yards = {}

	for row in reader:
		position = row[2]
		player = row[3]
		passing_yards = int(row[7])

		if position == "QB":
			if player in qb_passing_yards:
				qb_passing_yards[player] += passing_yards
			else:
				qb_passing_yards[player] = passing_yards

# Sort the quarterbacks by passing yards in descending order
sorted_qb_passing_yards = sorted(qb_passing_yards.items(), key=lambda x: x[1], reverse=True)

# Print the sum of the passing yards sorted by sum of passing yards in descending order
print("Player \t\t Passing Yards")
for player, yards in sorted_qb_passing_yards:
	print(f"{player} \t\t {yards}")

def is_strong_password(password):
	# Check if the password is not 'password' or 'qwerty' in any iteration
	forbidden_passwords = ['password', 'qwerty']
	for forbidden in forbidden_passwords:
		if forbidden in password.lower():
			return False
			return True




def most_students(classroom):
		'''
		classroom is a list of lists
		Each ' ' is an empty seat
		Each 'S' is a student
		How many new students can sit in a row?
		'''
		max_empty_seats = 0
		for row in classroom:
			empty_seats = row.count(' ')
			if empty_seats > max_empty_seats:
				max_empty_seats = empty_seats
		return max_empty_seats
	# Example usage
classroom = [
		['S', ' ', 'S', ' ', ' '],
		[' ', ' ', 'S', 'S', ' '],
		['S', 'S', ' ', ' ', ' '],
		[' ', ' ', ' ', 'S', 'S']
	]
	
print(most_students(classroom))  # Output should be 3