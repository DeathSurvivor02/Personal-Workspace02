
numbers = []
for i in range(6):
	num = int(input(f"Enter number {i+1}: "))
	numbers.append(num)
odd = [num for num in numbers if num % 2 != 0]
even = [num for num in numbers if num % 2 == 0]
print("Odd numbers:", odd)
print("Even numbers:", even)
numbers = [0 if num % 2 == 0 else num for num in numbers]
print("Updated list:", numbers)