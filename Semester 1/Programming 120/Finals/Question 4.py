def calculate_bmi(weight, height):
	return weight / (height ** 2)

def get_bmi_status(bmi):
	if bmi < 18.5:
		return "Underweight"
	elif 18.5 <= bmi < 25:
		return "Normal"
	else:
		return "Obese"

def main():
	try:
		weight = float(input("Enter weight in kilograms: "))
		height = float(input("Enter height in meters: "))
		bmi = calculate_bmi(weight, height)
		status = get_bmi_status(bmi)
		print(f"Your BMI is {bmi:.2f}. You are {status}.")
	except ValueError:
		print("Invalid input. Please enter numeric values for weight and height.")

if __name__ == "__main__":
	main()